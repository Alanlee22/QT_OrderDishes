#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <keybord.h>
#include <QSqlQuery>   // 适用于SQL查询
#include <QVariant>    // 适用于可变类型
#include <QSqlDatabase> // 适用于数据库连接
#include <QList>
#include <QLabel>
#include <QVector>
#include <QTcpSocket>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int table_num(const QString& expression) {
        bool ok; // 用于接收转换是否成功的标识
        int number = expression.toInt(&ok);
        if (ok) {
            return number;
        } else {
            return 0;
        }}
    QVector<QString> names = { "红烧肉", "鱼香肉丝", "溜肉段", "锅包肉", "炒青菜", "炒豆芽", "炒豌豆", "西红柿鸡蛋", "矿泉水", "可乐" };
    int dish_price();
public slots:
    void updateTableNumber(int tableNumber);

private slots:


    void on_addButton_9_clicked();

    void on_subButton_9_clicked();

    void on_subButton_10_clicked();

    void on_addButton_10_clicked();

    void on_addButton_11_clicked();

    void on_subButton_11_clicked();

    void on_subButton_12_clicked();

    void on_addButton_12_clicked();

    void on_subButton_5_clicked();

    void on_addButton_5_clicked();

    void on_subButton_6_clicked();

    void on_addButton_6_clicked();

    void on_subButton_8_clicked();

    void on_addButton_8_clicked();

    void on_subButton_7_clicked();

    void on_addButton_7_clicked();

    void on_subButton_clicked();

    void on_addButton_clicked();

    void on_subButton_2_clicked();

    void on_addButton_2_clicked();

    void on_sendup_clicked(int tableNumber);

    void on_exit_clicked();

    void on_menu_clicked();

    void on_sendup_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db_Order;
    QSqlQuery query;
    int currentIndex ;
    QList<QLabel*> labelList;
    QList<int> prices = { 32, 23, 35, 38, 12, 8, 13, 15, 2, 3 };
    QVector<int> num_Dishes;
    QTcpSocket *m_tcp;
    QString IP = "192.168.5.11";
    int currentTableNumber;
};
#endif // MAINWINDOW_H
