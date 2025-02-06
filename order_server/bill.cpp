#include "bill.h"
#include "ui_bill.h"
#include "tcporder.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QtWidgets>
#include <QDebug>
#include <QThread>
#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <numeric> // For std::accumulate

#define PORT 8080

bill::bill(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bill)
{
    ui->setupUi(this);
    qDebug() << "服务器子线程：" << QThread::currentThread();

    m_server = new QTcpServer(this);
    // 使用 QHostAddress::Any 来监听所有可用地址
    if (!m_server->listen(QHostAddress::Any, PORT)) {
        qDebug() << "无法启动服务器：" << m_server->errorString();
        return; // 监听失败，退出构造函数
    }

    connect(m_server, &QTcpServer::newConnection, this, [=]() {
        QTcpSocket* tcp = m_server->nextPendingConnection(); //等待下次链接
        TcpOrder* order = new TcpOrder(tcp); // 创建 TcpOrder 实例
        order->start();

        connect(order, &TcpOrder::trans_over, this, &bill::new_table);
    });
}
bill::~bill()
{
    delete ui;
}

void bill::new_table(QVector<int> num_Dishes)
{
    this->num_Dishes = num_Dishes;
    QVector<QString> names = { "红烧肉", "鱼香肉丝", "溜肉段", "锅包肉", "炒青菜",
                               "炒豆芽", "炒豌豆", "西红柿鸡蛋", "矿泉水", "可乐" };
    QString str_desknum;
    QWidget* table = new QWidget();
    QWidget* button = new QWidget(table);
    QTextBrowser* textBrowser = new QTextBrowser(table);
    QLabel* priceLabel = new QLabel(button);
    QPushButton* closeOrder = new QPushButton(button);
    closeOrder->setText("关闭");

    QHBoxLayout* hlayout = new QHBoxLayout;
    QVBoxLayout* vlayout = new QVBoxLayout;
    hlayout->addWidget(priceLabel);
    hlayout->addWidget(closeOrder);
    hlayout->setSpacing(100);
    button->setLayout(hlayout);
    vlayout->addWidget(textBrowser);
    vlayout->addWidget(button);
    table->setLayout(vlayout);
    //桌号设置
     str_desknum = "桌号:";
     str_desknum.append(QString::number(num_Dishes[0]));

    for (int i = 1; i < num_Dishes.size(); ++i) {
        if(num_Dishes[i]>0){
        textBrowser->append(QString("%1 - %2 份")
                              .arg(names[i-1])
                              .arg(num_Dishes[i]));}
    }
    // 计算总价
    int i = dish_price();
    priceLabel->setText("总价:" + QString::number(i));

    ui->tabWidget->addTab(table, str_desknum);

    connect(closeOrder, &QPushButton::clicked, this, [=]() {
        int currentIndex = ui->tabWidget->currentIndex();
        if (currentIndex != -1) {
            ui->tabWidget->removeTab(currentIndex);
        }
        table->deleteLater();
    });
}
int bill::dish_price() {
       int total = 0;

       // 计算总价，假设 num_Dishes 第 0 个元素是桌号，菜品数量从索引 1 开始
       for (int i = 1; i < num_Dishes.size(); i++) {
           total += num_Dishes[i] * prices[i - 1];
       }
       return total;
   }
