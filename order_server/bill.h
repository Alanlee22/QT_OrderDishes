#ifndef BILL_H
#define BILL_H

#include <QMainWindow>
#include <QTcpServer>
#include <QVector>

namespace Ui {
class bill;
}

class bill : public QMainWindow
{
    Q_OBJECT

public:
    explicit bill(QWidget *parent = nullptr);
    ~bill();
    int dish_price() ;
private slots:
    void new_table(QVector<int> num_Dishes); // 槽函数，用于处理新桌子

private:
    Ui::bill *ui;                  // UI 指针
    QTcpServer *m_server;          // TCP 服务器指针
    QVector<int> num_Dishes; // 成员变量，存储菜品数量和桌号
    QVector<int> prices = { 32, 23, 35, 38, 12, 8, 13, 15, 2, 3 };
};

#endif // BILL_H
