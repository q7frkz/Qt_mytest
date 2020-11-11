#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>


class Menu : public QMainWindow {

    Q_OBJECT

    public:
        explicit Menu(QWidget *parent = nullptr);
//        ~Menu() override;

    public slots:
        void rgb();
        void bilberry();
    signals:

    private:
        QPushButton *b1;
        QPushButton *b2;
        QPushButton *b3;
        QVBoxLayout *box;
};

#endif //MENU_H
