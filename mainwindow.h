#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authregform.h"
#include "task1_vigenere.h"
#include "task2_bisection.h"
#include "stat_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Exit_clicked();
    void slot_on_auth_ok();
    void on_Task1_clicked();
    void on_pushButton_Task2_clicked();
    void on_pushButton_Stat_clicked();
    void returnFromTask1();  // Слоты для возврата
    void returnFromTask2();
    void returnFromStat();

private:
    Ui::MainWindow *ui;
    AuthRegForm *ui_reg;
    Task1_Vigenere *task1Window;
    Task2_Bisection *task2Window;
    Stat_Window *statWindow;
};
#endif // MAINWINDOW_H
