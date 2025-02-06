#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "bill.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void sqlite_Init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    QString createsql = QString("create table if not exists user(id integer primary key autoincrement,"
                              "username ntext unique not NULL,"
                              "password ntext not NULL)");
    QSqlQuery query;
    if(!query.exec(createsql)){
        qDebug()<<"table create error";
    }
    else{
        qDebug()<<"table create success";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    signup *s = new signup();
           s->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    sqlite_Init();
    username = ui->lognumber->text();
    password = ui->password->text();
    QString sql = QString("select * from user where username='%1' and password='%2'")
            .arg(username).arg(password);
    QSqlQuery query(sql);
    if(!query.next())
    {
        qDebug()<<"Login error";
        QMessageBox::information(this,"登录认证","登录失败");
    }
    else
    {
        qDebug()<<"Login success";
        QMessageBox::information(this,"登录认证","登录成功");
        bill *b = new bill;
        b->show();
        this->close();
    }
}

