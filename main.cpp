#include <QApplication>
#include <QGraphicsBlurEffect>

#include "RGB.h"
#include "LCDRange.h"
#include "Menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu menu(new QWidget());
    menu.setFixedSize(500, 250);
    menu.setWindowTitle("Qt Demonstration");
    menu.show();

    a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
