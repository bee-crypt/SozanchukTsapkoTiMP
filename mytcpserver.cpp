#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QByteArray>
#include <QDateTime>

MyTcpServer::~MyTcpServer()
{
    if (mTcpServer) {
        mTcpServer->close();
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] Server stopped";
    }
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent),
    mTcpServer(nullptr)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] ERROR: Server failed to start on port 33333";
    } else {
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] SERVER STARTED - Listening on port 33333";
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] Ready for client connections...";
    }
}

void MyTcpServer::slotNewConnection(){
    QTcpSocket* clientSocket = mTcpServer->nextPendingConnection();
    QString clientInfo = QString("%1:%2").arg(clientSocket->peerAddress().toString()).arg(clientSocket->peerPort());

    qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] NEW CLIENT CONNECTED:" << clientInfo;
    qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] Active connections:" << mTcpServer->isListening();

    // Отправляем приветствие
    QByteArray welcomeMsg = "Hello! Connected to echo server. Type your messages.\r\n";
    clientSocket->write(welcomeMsg);

    qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] Sent welcome message to" << clientInfo;

    // Подключаем сигналы для этого конкретного клиента
    connect(clientSocket, &QTcpSocket::readyRead,
            this, &MyTcpServer::slotServerRead);
    connect(clientSocket, &QTcpSocket::disconnected,
            this, &MyTcpServer::slotClientDisconnected);
    connect(clientSocket, &QTcpSocket::disconnected,
            clientSocket, &QTcpSocket::deleteLater);
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket || clientSocket->state() != QAbstractSocket::ConnectedState) {
        return;
    }

    QString clientInfo = QString("%1:%2").arg(clientSocket->peerAddress().toString()).arg(clientSocket->peerPort());
    QByteArray array = clientSocket->readAll();

    // Фильтруем Telnet команды
    QByteArray filteredData;
    for (int i = 0; i < array.size(); ++i) {
        if (static_cast<unsigned char>(array[i]) == 0xFF) {
            i += 2;
            continue;
        }
        filteredData.append(array[i]);
    }

    // Убираем символы возврата каретки и новой строки для чистого вывода
    QByteArray cleanData = filteredData;
    cleanData = cleanData.replace("\r", "\\r").replace("\n", "\\n");

    if (!cleanData.isEmpty()) {
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] REQUEST from" << clientInfo << ":" << cleanData;

        // Отправляем эхо-ответ
        QByteArray response = filteredData + "\r\n";
        clientSocket->write(response);

        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] RESPONSE to" << clientInfo << ":" << cleanData;
    }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (clientSocket) {
        QString clientInfo = QString("%1:%2").arg(clientSocket->peerAddress().toString()).arg(clientSocket->peerPort());
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] CLIENT DISCONNECTED:" << clientInfo;
        qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss") << "] Waiting for new connections...";
    }
}
