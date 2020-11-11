#include "Menu.h"
#include "LCDRange.h"
#include "RGB.h"
#include "Bilberry.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    b1 = new QPushButton("Test RGB", this);
    b1->setGeometry(50, 25, 400, 50);
    b1->setFont(QFont("Times", 18, QFont::Bold));
    connect(b1, SIGNAL(clicked()), this, SLOT(rgb()));

    b2 = new QPushButton("Bilberry", this);
    b2->setGeometry(50, 100, 400, 50);
    b2->setFont(QFont("Times", 18, QFont::Bold));
    connect(b2, SIGNAL(clicked()), this, SLOT(bilberry()));

    b3 = new QPushButton("Next", this);
    b3->setGeometry(50, 175, 400, 50);
    b3->setFont(QFont("Times", 18, QFont::Bold));

    box = new QVBoxLayout();
    box->addWidget(b1);
    box->addWidget(b2);
    box->addWidget(b3);
}

//Menu::~Menu()
//{
//    qDebug() << "Delete menu";
//    delete b1;
//    delete b2;
//    delete b3;
//    delete box;
//    qDebug() << "Fin Delete menu";
//}

void Menu::rgb()
{
    auto *w = new RGB(this);
    w->setWindowTitle("RGB");
    w->setFixedSize(500, 500);
    w->show();
}

void Menu::bilberry()
{
    auto *bil = new Bilberry(this);
    bil->setWindowTitle("Bilberry");
    bil->setFixedSize(500, 175);
    bil->show();
}