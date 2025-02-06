#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_keybord.h"
#include "keybord.h"
#include <QTcpSocket>
#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <menu.h>
#include <QHostAddress>
#include "ui_menu.h"
#define PORT 8080
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置图片
    ui->hsr->setPixmap(QPixmap("/mnt/images/1.jpg").scaled(80, 80));  // 使用资源路径
    ui->yxrs->setPixmap(QPixmap("/mnt/images/2.jpg").scaled(80, 80));
    ui->lrd->setPixmap(QPixmap("/mnt/images/3.jpg").scaled(80, 80));
    ui->gbr->setPixmap(QPixmap("/mnt/images/4.jpg").scaled(80, 80));
    ui->cqc->setPixmap(QPixmap("/mnt/images/5.jpg").scaled(80, 80));
    ui->cdy->setPixmap(QPixmap("/mnt/images/6.jpg").scaled(80, 80));
    ui->cwd->setPixmap(QPixmap("/mnt/images/7.jpg").scaled(80, 80));
    ui->xhscjd->setPixmap(QPixmap("/mnt/images/8.jpg").scaled(80, 80));
    ui->kqs->setPixmap(QPixmap("/mnt/images/9.jpg").scaled(80, 80));
    ui->kl->setPixmap(QPixmap("/mnt/images/10.jpeg").scaled(80, 80));

    // 数据库设置
    db_Order = QSqlDatabase::addDatabase("QSQLITE");
    db_Order.setDatabaseName("db_order.db");

    if (!db_Order.open()) {
        qDebug() << "数据库连接失败：" << db_Order.lastError().text();
        return;
    }

    // 创建表格
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO order_dishes (id, name, price, num) VALUES (?, ?, ?, ?)");
    for (int i = 0; i < names.size(); i++) {
        query.addBindValue(i + 1);
        query.addBindValue(names[i]);
        query.addBindValue(prices[i]);
        query.addBindValue(0);  // num 默认为 0

        if (!query.exec()) {
            qDebug() << "插入数据失败：" << query.lastError().text();
        }
    }

    // TCP 连接
    m_tcp = new QTcpSocket(this);
    m_tcp->connectToHost(QHostAddress(IP), PORT);

    connect(m_tcp, &QTcpSocket::connected, this, [=](){
        qDebug() << "成功连接服务器"; // 正确的连接日志
    });

    connect(m_tcp, &QTcpSocket::disconnected, this, [=](){
        qDebug() << "断开连接"; // 正确的断开日志
    });

    // 初始化 num_Dishes
    num_Dishes.fill(0, names.size()); // 使用 fill 函数初始化 num_Dishes
}
void MainWindow::updateTableNumber(int tableNumber) {
    currentTableNumber = tableNumber; // 保存桌号
   ui->labeltable->setText(QString("桌号：%1").arg(tableNumber));// 显示桌号
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_9_clicked()
{
    if (num_Dishes[0] < 99) {  // 设定一个最大限制
        this->num_Dishes[0]++;
        ui->label0->setText(QString::number(num_Dishes[0]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_9_clicked()
{
    if (num_Dishes[0] > 0) { // 防止变成负数
        this->num_Dishes[0]--;
        ui->label0->setText(QString::number(num_Dishes[0]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_addButton_10_clicked()
{
    if (num_Dishes[1] < 99) {  // 设定一个最大限制
        this->num_Dishes[1]++;
        ui->label1->setText(QString::number(num_Dishes[1]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
}
}

void MainWindow::on_subButton_10_clicked()
{
    if (num_Dishes[1] > 0) { // 防止变成负数
        this->num_Dishes[1]--;
        ui->label1->setText(QString::number(num_Dishes[1]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_addButton_11_clicked()
{
    if (num_Dishes[2] < 99) {  // 设定一个最大限制
        this->num_Dishes[2]++;
        ui->label2->setText(QString::number(num_Dishes[2]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_11_clicked()
{
    if (num_Dishes[2] > 0) { // 防止变成负数
        this->num_Dishes[2]--;
        ui->label2->setText(QString::number(num_Dishes[2]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_12_clicked()
{
    if (num_Dishes[3] > 0) { // 防止变成负数
        this->num_Dishes[3]--;
        ui->label3->setText(QString::number(num_Dishes[3]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}
void MainWindow::on_addButton_12_clicked()
{
    if (num_Dishes[3] < 99) {  // 设定一个最大限制
        this->num_Dishes[3]++;
        ui->label3->setText(QString::number(num_Dishes[3]));
       int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_5_clicked()
{
    if (num_Dishes[4] > 0) { // 防止变成负数
        this->num_Dishes[4]--;
        ui->label4->setText(QString::number(num_Dishes[4]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}


void MainWindow::on_addButton_5_clicked()
{
    if (num_Dishes[4] < 99) {  // 设定一个最大限制
        this->num_Dishes[4]++;
        ui->label4->setText(QString::number(num_Dishes[4]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}


void MainWindow::on_subButton_6_clicked()
{
    if (num_Dishes[5] > 0) { // 防止变成负数
        this->num_Dishes[5]--;
        ui->label5->setText(QString::number(num_Dishes[5]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_addButton_6_clicked()
{
    if (num_Dishes[5] < 99) {  // 设定一个最大限制
        this->num_Dishes[5]++;
        ui->label5->setText(QString::number(num_Dishes[5]));
        int d = dish_price();  // 计算总价格
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}


void MainWindow::on_subButton_8_clicked()
{
    if (num_Dishes[6] > 0) { // 防止变成负数
        this->num_Dishes[6]--;
        ui->label6->setText(QString::number(num_Dishes[6]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_addButton_8_clicked()
{
    if (num_Dishes[6] < 99) {  // 设定一个最大限制
        this->num_Dishes[6]++;
        ui->label6->setText(QString::number(num_Dishes[6]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_7_clicked()
{
    if (num_Dishes[7] > 0) { // 防止变成负数
        this->num_Dishes[7]--;
        ui->label7->setText(QString::number(num_Dishes[7]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_addButton_7_clicked()
{
    if (num_Dishes[7] < 99) {  // 设定一个最大限制
        this->num_Dishes[7]++;
        ui->label7->setText(QString::number(num_Dishes[7]));
        int d =  dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_clicked()
{
    if (num_Dishes[8] > 0) { // 防止变成负数
        this->num_Dishes[8]--;
        ui->label8->setText(QString::number(num_Dishes[8]));
        int d = dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_addButton_clicked()
{
    if (num_Dishes[8] < 99) {  // 设定一个最大限制
        this->num_Dishes[8]++;
        ui->label8->setText(QString::number(num_Dishes[8]));
        int d =  dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

void MainWindow::on_subButton_2_clicked()
{
    if (num_Dishes[9] > 0) { // 防止变成负数
        this->num_Dishes[9]--;
        ui->label9->setText(QString::number(num_Dishes[9]));
        int d =  dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
}
}

void MainWindow::on_addButton_2_clicked()
{
    if (num_Dishes[9] < 99) {  // 设定一个最大限制
        this->num_Dishes[9]++;
        ui->label9->setText(QString::number(num_Dishes[9]));
        int d =  dish_price();
        ui->labelprice->setText(QString("总价：%1").arg(d));
    }
}

    int MainWindow::dish_price() {
        int total = 0;
        for (int i = 0; i < 10; i++) {
            total += num_Dishes[i] * prices[i];
        }
        return total;
    }

void MainWindow::on_exit_clicked()
{
        keybord *keybord1 = new keybord();  // 不设置 parent，防止 MainWindow 关闭时销毁 keybord
        keybord1->show();
        this->close();
}

void MainWindow::on_menu_clicked()
{
    menu *menu1 = new menu(this);

    // 连接销毁信号以避免内存泄漏
    connect(menu1, &QObject::destroyed, this, [=](){
        // 在这里处理任何必要的清理
    });

    menu1->menu_num(num_Dishes, names); // 先设置内容
    menu1->show(); // 然后显示窗口
}

void MainWindow::on_sendup_clicked()
{
    QString str = QString::number(currentTableNumber);
    str.append(",");
    for(size_t i = 0; i < 10;i++){
        str.append(QString::number(num_Dishes[i]));
        str.append(",");
    }
    m_tcp -> write(str.toUtf8());
}


