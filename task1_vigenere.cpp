#include "task1_vigenere.h"
#include "ui_task1_vigenere.h"
#include <QDebug>

Task1_Vigenere::Task1_Vigenere(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task1_Vigenere)
{
    ui->setupUi(this);
}

Task1_Vigenere::~Task1_Vigenere()
{
    delete ui;
}

void Task1_Vigenere::on_pushButton_Back_clicked()
{
    qDebug() << "Returning to main window from Task1";
    emit returnToMain();  // Испускаем сигнал вместо закрытия
}

void Task1_Vigenere::on_pushButton_Encrypt_clicked()
{
    qDebug() << "Encrypt button clicked";
    ui->textEdit_Result->setPlainText("Encrypted text would be here (Vigenere)");
}

void Task1_Vigenere::on_pushButton_Decrypt_clicked()
{
    qDebug() << "Decrypt button clicked";
    ui->textEdit_Result->setPlainText("Decrypted text would be here (Vigenere)");
}
