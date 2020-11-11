#include <QLCDNumber>
#include <QHBoxLayout>
#include <QDebug>
#include <QSizePolicy>
#include <QColor>
#include <QPushButton>
#include <QSpacerItem>

#include "RGB.h"
#include "LCDRange.h"

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE

LCDRange::LCDRange(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    for (int count = 0 ; count < 3 ; count++) {
        vecLcd.push_back(new QLCDNumber(3, this));
        vecLcd[count]->setSegmentStyle(QLCDNumber::Filled);
    }
    
    for (int count = 0 ; count < 3 ; count++) {
        vecSlider.push_back(new QSlider(Qt::Horizontal));
        vecSlider[count]->setRange(0, 255);
        vecSlider[count]->setValue(0);
    }

    for (int count = 0 ; count < 3 ; count++) {
        vecV.push_back(new QVBoxLayout());
        vecV[count]->addWidget(vecLcd[count]);
        vecV[count]->addWidget(vecSlider[count]);
        connect(vecSlider[count], SIGNAL(valueChanged(int)), vecLcd[count], SLOT(display(int)));
        connect(vecSlider[count], SIGNAL(valueChanged(int)), this, SLOT(setBackground()));
    }

    boxH = new QHBoxLayout(this);
    for (int count = 0 ; count < 3 ; count++)
        boxH->addLayout(vecV[count]);
}

LCDRange::~LCDRange()
{
    for (int count = 0 ; count < 3 ; count++) {
        delete vecLcd[count];
        delete vecSlider[count];
        delete vecV[count];
    }
    delete boxH;
}

void LCDRange::setBackground()
{
    QPalette pal(this->palette());
    pal.setColor(QPalette::Window,
                 QColor::fromRgb(vecSlider[0]->value(),
                                       vecSlider[1]->value(),
                                       vecSlider[2]->value()));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

}