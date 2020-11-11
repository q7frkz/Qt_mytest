#ifndef BILBERRY_H
#define BILBERRY_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QPushButton>

#include "BServer.h"


class Bilberry : public  QMainWindow
{
    Q_OBJECT

    public:
        explicit Bilberry(QWidget *parent = nullptr);
//        ~Bilberry();

    public slots:
        void B_Server();
        void B_Client();

    private:
        QPushButton *client;
        QPushButton *server;
        BServer *bserver;
};


#endif //TUTO2_BILBERRY_H
