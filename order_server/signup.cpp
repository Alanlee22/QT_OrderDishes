#include "signup.h"
#include "mainwindow.h"
#include "ui_signup.h"
#include <QMessageBox>
#include<QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_username_editingFinished()
{
     Username = ui->username->text(); // 将输入存储到类级别变量

    // 检查用户名是否为空
    if (Username.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名为空");
        return;  // 返回以避免后续处理
    }

    // 对用户名进行进一步检查，例如检查长度或格式
    if (Username.length() < 3) {
        QMessageBox::warning(this, "输入错误", "用户名必须至少包含3个字符");
        return;
    }
}

void signup::on_password_editingFinished()
{
     Password = ui->password->text(); // 将输入存储到类级别变量

    // 检查密码是否为空
    if (Password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "密码为空");
        return;  // 返回以避免后续处理
    }

    // 对密码进行进一步检查，例如检查长度
    if (Password.length() < 6) {
        QMessageBox::warning(this, "输入错误", "密码必须至少包含6个字符");
        return;
    }
}



void signup::on_pushButton_clicked()
{
    sqlite_Init();
    EnsurePassword = ui->ensurepassword->text();
    // 在这里比较类级别的 Password 和 confirmPassword
    if (Password == EnsurePassword) {

        QString sql = QString("insert into user(username,password) values('%1','%2');")
                      .arg(Username).arg(Password);
        QSqlQuery query;
        if(!query.exec(sql)){
                qDebug()<<"insertError";
                QMessageBox::information(this,"失败","插入错误");
    }
        else
        {
            qDebug()<<"insert into success";
            QMessageBox::information(this,"成功","成功插入");
            MainWindow *w = new MainWindow;
            w->show();
            this->close();
        }
    }
    else {
        QMessageBox::warning(this, "输入错误", "密码与确认密码不匹配");
    }
}


