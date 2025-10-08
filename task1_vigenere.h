#ifndef TASK1_VIGENERE_H
#define TASK1_VIGENERE_H

#include <QWidget>

namespace Ui {
class Task1_Vigenere;
}

class Task1_Vigenere : public QWidget
{
    Q_OBJECT

public:
    explicit Task1_Vigenere(QWidget *parent = nullptr);
    ~Task1_Vigenere();

signals:
    void returnToMain();  // Сигнал для возврата на главную

private slots:
    void on_pushButton_Back_clicked();
    void on_pushButton_Encrypt_clicked();
    void on_pushButton_Decrypt_clicked();

private:
    Ui::Task1_Vigenere *ui;
};

#endif // TASK1_VIGENERE_H
