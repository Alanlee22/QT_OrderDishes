#include "menu.h"
#include "ui_menu.h"
#include <QVector>
menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_closeButton_clicked()
{
   this-> close();
}

void menu::menu_num(QVector<int> num_Dishes, QVector<QString> names) {
    QString str;
    for (int i = 0; i < names.size(); i++) {
        if (num_Dishes[i] != 0) { // 检查非零值
            str = names[i];
            str.append(" * ");
            str.append(QString::number(num_Dishes[i]));
            ui->textBrowser->append(str); // 确保能看到内容
        }
    }
}

