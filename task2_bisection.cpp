#include "task2_bisection.h"
#include "ui_task2_bisection.h"
#include <QDebug>

Task2_Bisection::Task2_Bisection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task2_Bisection)
{
    ui->setupUi(this);
}

Task2_Bisection::~Task2_Bisection()
{
    delete ui;
}

void Task2_Bisection::on_pushButton_Back_clicked()
{
    qDebug() << "Returning to main window from Task2";
    emit returnToMain();  // Испускаем сигнал вместо закрытия
}

void Task2_Bisection::on_pushButton_Solve_clicked()
{
    qDebug() << "Solve button clicked";
    ui->textEdit_Result->setPlainText("Equation solution would be here (Bisection method)");
}
