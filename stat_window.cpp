#include "stat_window.h"
#include "ui_stat_window.h"
#include <QDebug>

Stat_Window::Stat_Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Stat_Window)
{
    ui->setupUi(this);
}

Stat_Window::~Stat_Window()
{
    delete ui;
}

void Stat_Window::on_pushButton_Back_clicked()
{
    qDebug() << "Returning to main window from Stat";
    emit returnToMain();  // Испускаем сигнал вместо закрытия
}

void Stat_Window::on_pushButton_Refresh_clicked()
{
    qDebug() << "Refresh button clicked";
    ui->textEdit_Stats->setPlainText("User statistics would be here\n\nUser: user\nTasks completed: 0\nLast login: 2024-01-01");
}
