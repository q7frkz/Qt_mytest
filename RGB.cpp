#include "RGB.h"
#include "LCDRange.h"

RGB::RGB(QWidget *parent)
    : QMainWindow(parent)
{
    _ret = new QPushButton("Back", this);
    _ret->setFont(QFont("Times", 18, QFont::Bold));
    _ret->setGeometry(0, 0, 500, 50);
    connect(_ret, SIGNAL(clicked()), this, SLOT(close()));

    _lcd = new LCDRange(this);
    _lcd->setGeometry(0, 50, 500, 450);
}

RGB::~RGB()
{
    delete _ret;
    delete _lcd;
}

void RGB::closeEvent(QCloseEvent *event)
{
    this->close();
}

