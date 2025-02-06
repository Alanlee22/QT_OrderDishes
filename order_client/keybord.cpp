#include "keybord.h"
#include "ui_keybord.h"


keybord::keybord(QWidget *parent) :
    QMainWindow(parent),
    uik(new Ui::keybord)
{
    uik->setupUi(this);
}

keybord::~keybord()
{
    delete uik;
}

void keybord::on_pushButton_1_clicked()
{
    expression += "1";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_2_clicked()
{
    expression += "2";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_3_clicked()
{
    expression += "3";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_4_clicked()
{
    expression += "4";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_5_clicked()
{
    expression += "5";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_6_clicked()
{
    expression += "6";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_7_clicked()
{
    expression += "7";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_8_clicked()
{
    expression += "8";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_9_clicked()
{
    expression += "9";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_0_clicked()
{
    expression += "0";
    uik->lineEdit->setText(expression);
    uik->pushButton_queren->setEnabled(true);
}

void keybord::on_pushButton_qingchu_clicked()
{
    expression.clear();
    uik->lineEdit->clear();
}

void keybord::on_pushButton_queren_clicked()
{
    int tableNumber = uik->lineEdit->text().toInt();  // 获取输入的桌号
    this->page_2 = new MainWindow;
    connect(this, &keybord::tableNumberEntered,this->page_2, &MainWindow::updateTableNumber);
    emit tableNumberEntered(tableNumber);
    this->close();
    this->page_2->show();
}



void keybord::on_pushButton_xiaochu_clicked()
{
    expression.chop(1);
    uik->lineEdit->setText(expression);
}
