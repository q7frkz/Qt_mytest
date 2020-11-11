#ifndef LCD_H
#define LCD_H

#include <QWidget>
#include <QLCDNumber>
#include <QVector>
#include <QSlider>
#include <QHBoxLayout>
#include <QPalette>

class LCDRange : public QWidget
{
    Q_OBJECT

    public:
        explicit LCDRange(QWidget *parent);
        ~LCDRange() override;
    public slots:
        void setBackground();
    signals:

    private:
        QVector<QLCDNumber *> vecLcd;
        QVector<QSlider *> vecSlider;
        QVector<QVBoxLayout *> vecV;
        QHBoxLayout *boxH;
};

#endif // LCD_H
