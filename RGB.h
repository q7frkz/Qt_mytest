#ifndef RGB_H
#define RGB_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QDebug>
#include <QPushButton>

#include "LCDRange.h"


class RGB : public QMainWindow
{
    Q_OBJECT

public:
    explicit RGB(QWidget *parent = nullptr);
    ~RGB();
    void closeEvent(QCloseEvent *event);

private:
    LCDRange *_lcd;
    QPushButton *_ret;
};

#endif // RGB_H
