#include <QWidget>
#include <QMainWindow>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <QString>

#include "GPSInfo.h"

#ifndef BSERVER_H
#define BSERVER_H


class BServer : public QMainWindow
{
    Q_OBJECT

    public:
        explicit BServer(QMainWindow *parent = nullptr);
        //~BServer();
        void closeEvent(QCloseEvent *event);

    public slots:
        void onNewConnection();
        //void onReadyRead();
        void showGPS();

    private:
        QTcpServer *_server;
        QLabel *labelTop;
        QLabel *labelDown;
        GPSInfo *info;
        QTimer *timer;
        QString *getInfo();
        void createCircularGPSInfo();
        void initGPSTimer();


};


#endif //BSERVER_H
