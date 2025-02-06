#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "ui_menu.h"
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
     void menu_num(QVector<int> num_Dishes, QVector<QString> names);
private slots:
    void on_closeButton_clicked();

private:
    Ui::menu *ui;

};

#endif // MENU_H
