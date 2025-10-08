#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QObject>

class FunctionsForClient: public QObject
{
    Q_OBJECT
public:
    void is_auth(QString, QString);
    FunctionsForClient();
signals:
    void on_auth_ok();
    void on_auth_error(QString error_message);
};

#endif // FUNCTIONSFORCLIENT_H
