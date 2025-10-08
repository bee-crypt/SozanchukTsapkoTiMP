#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_reg = new AuthRegForm;
    ui_reg->show();
    connect(ui_reg->get_func(), &FunctionsForClient::on_auth_ok, this, &MainWindow::slot_on_auth_ok);

    // Инициализация окон задач
    task1Window = nullptr;
    task2Window = nullptr;
    statWindow = nullptr;

    // Вручную подключаем сигналы к слотам
    connect(ui->Task1, &QPushButton::clicked, this, &MainWindow::on_Task1_clicked);
    connect(ui->pushButton_Task2, &QPushButton::clicked, this, &MainWindow::on_pushButton_Task2_clicked);
    connect(ui->pushButton_Stat, &QPushButton::clicked, this, &MainWindow::on_pushButton_Stat_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(task1Window) delete task1Window;
    if(task2Window) delete task2Window;
    if(statWindow) delete statWindow;
}

void MainWindow::on_pushButton_Exit_clicked()
{
    this->close();
}

void MainWindow::slot_on_auth_ok()
{
    delete ui_reg;
    this->show();
}

void MainWindow::on_Task1_clicked()
{
    qDebug() << "Task1 button clicked!";
    this->hide();
    if(!task1Window) {
        task1Window = new Task1_Vigenere();
        connect(task1Window, &Task1_Vigenere::returnToMain, this, &MainWindow::returnFromTask1);
    }
    task1Window->show();
}

void MainWindow::on_pushButton_Task2_clicked()
{
    qDebug() << "Task2 button clicked!";
    this->hide();
    if(!task2Window) {
        task2Window = new Task2_Bisection();
        connect(task2Window, &Task2_Bisection::returnToMain, this, &MainWindow::returnFromTask2);
    }
    task2Window->show();
}

void MainWindow::on_pushButton_Stat_clicked()
{
    qDebug() << "Stat button clicked!";
    this->hide();
    if(!statWindow) {
        statWindow = new Stat_Window();
        connect(statWindow, &Stat_Window::returnToMain, this, &MainWindow::returnFromStat);
    }
    statWindow->show();
}

void MainWindow::returnFromTask1()
{
    if(task1Window) {
        task1Window->hide();
    }
    this->show();
}

void MainWindow::returnFromTask2()
{
    if(task2Window) {
        task2Window->hide();
    }
    this->show();
}

void MainWindow::returnFromStat()
{
    if(statWindow) {
        statWindow->hide();
    }
    this->show();
}
