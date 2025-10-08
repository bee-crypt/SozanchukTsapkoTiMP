#include <QCoreApplication>
#include <QSocketNotifier>
#include <QTextStream>
#include <iostream>  // Добавьте этот include
#include "singletonclient.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    MyClient* client = new MyClient();
    client->connectToServer();

    // Создаем notifier для стандартного ввода
    QSocketNotifier *notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, &a);

    QObject::connect(notifier, &QSocketNotifier::activated, [client]() {
        QTextStream stream(stdin);
        QString input = stream.readLine();
        qDebug() << "Sending command:" << input;
        client->sendCommand(input);
    });

    std::cout << "You can now type commands. Available commands:" << std::endl;
    std::cout << "- reg login:password" << std::endl;
    std::cout << "- auth login:password" << std::endl;
    std::cout << "- enc message" << std::endl;
    std::cout << "- hash data" << std::endl;
    std::cout << "Type your command and press Enter..." << std::endl;

    return a.exec();
}
