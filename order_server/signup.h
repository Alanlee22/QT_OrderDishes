#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:


    void on_username_editingFinished();

    void on_password_editingFinished();

    void on_pushButton_clicked();

    void on_ensurepassword_editingFinished();

private:
    Ui::signup *ui;
    QString Username;          // 声明类级别变量
    QString Password;          // 声明类级别变量
    QString EnsurePassword;
};

#endif // SIGNUP_H
