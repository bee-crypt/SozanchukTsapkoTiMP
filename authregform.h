#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
#include "functionsforclient.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    FunctionsForClient* get_func();

signals:
    void auth_ok();

private slots:
    void on_pushButtonAuth_clicked();
    void on_pushButton_3_clicked();
    void on_auth_error(QString error_message);  // Новый слот для ошибки

private:
    Ui::AuthRegForm *ui;
    FunctionsForClient func;
};

#endif // AUTHREGFORM_H
