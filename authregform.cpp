#include "authregform.h"
#include "ui_authregform.h"
#include <QMessageBox>

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->label_Email->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->pushButton_Registration->setVisible(false);

    // Подключаем сигнал ошибки
    connect(&func, &FunctionsForClient::on_auth_error, this, &AuthRegForm::on_auth_error);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushButtonAuth_clicked()
{
    func.is_auth(ui->lineEditLogin->text(), ui->lineEdit_Password->text());
}

void AuthRegForm::on_pushButton_3_clicked()
{
    bool flag = ui->label_Email->isVisible();

    ui->label_Email->setVisible(!flag);
    ui->lineEdit_3->setVisible(!flag);
    ui->pushButton_Registration->setVisible(!flag);
    ui->pushButtonAuth->setVisible(flag);
}

FunctionsForClient* AuthRegForm::get_func(){
    return &(this->func);
}

void AuthRegForm::on_auth_error(QString error_message)
{
    QMessageBox::warning(this, "Authentication Error", error_message);
}
