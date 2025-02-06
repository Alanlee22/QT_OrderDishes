#ifndef KEYBORD_H
#define KEYBORD_H

#include "mainwindow.h"
#include <QMainWindow>


namespace Ui {
class keybord;
}

class MainWindow;

class keybord : public QMainWindow
{
    Q_OBJECT

public:
    QString expression;
    explicit keybord(QWidget *parent = nullptr);
    ~keybord();
    MainWindow* page_2;
signals:
    void tableNumberEntered(int tableNumber);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_queren_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_qingchu_clicked();

    void on_pushButton_xiaochu_clicked();

private:
    Ui::keybord *uik;

};

#endif // KEYBORD_H
