#include "functionsforclient.h"
#include <QDebug>

FunctionsForClient::FunctionsForClient()
{
}

void FunctionsForClient::is_auth(QString log, QString pass){
    // Проверка на пустые поля
    if (log.isEmpty() || pass.isEmpty()) {
        emit on_auth_error("Please enter login and password");
        return;
    }

    // Проверка правильности логина и пароля
    if (log == "user" && pass == "123") {
        emit on_auth_ok();
    } else {
        emit on_auth_error("Invalid login or password");
    }
}
