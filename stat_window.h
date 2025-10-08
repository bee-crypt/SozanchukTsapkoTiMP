#ifndef STAT_WINDOW_H
#define STAT_WINDOW_H

#include <QWidget>

namespace Ui {
class Stat_Window;
}

class Stat_Window : public QWidget
{
    Q_OBJECT

public:
    explicit Stat_Window(QWidget *parent = nullptr);
    ~Stat_Window();

signals:
    void returnToMain();  // Сигнал для возврата на главную

private slots:
    void on_pushButton_Back_clicked();
    void on_pushButton_Refresh_clicked();

private:
    Ui::Stat_Window *ui;
};

#endif // STAT_WINDOW_H
