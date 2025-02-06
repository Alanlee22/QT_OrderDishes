#include <QApplication>
#include "keybord.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    keybord keybord1;

    keybord1.show();
    return a.exec();
}
