#include <QFont>
#include <QHostAddress>
#include <QTimer>
#include <QString>
#include <QRandomGenerator>

#include "global.h"
#include "BServer.h"

BServer::BServer(QMainWindow *parent) : QMainWindow(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    labelTop = new QLabel(this);
    labelTop->resize(500, 100);
    labelTop->setFont(QFont("Times", 18, QFont::Bold));
    labelTop->setAlignment(Qt::AlignBaseline);
    labelTop->setText("Waiting connection on localhost:4242\n");
    labelTop->show();

    labelDown = new QLabel(this);
    labelDown->resize(500, 400);
    labelDown->move(0, 100);
    labelDown->setFont(QFont("Times", 13, QFont::Bold));
    labelDown->setAlignment(Qt::AlignBaseline);

    qsrand(time(nullptr));
    createCircularGPSInfo();
    initGPSTimer();

    _server = new QTcpServer(this);
    _server->listen(QHostAddress::LocalHost, 4242);

    connect(_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    //connect(_server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    //connect(this, SIGNAL(close()), this, BServer::~BServer());
}

//BServer::~BServer()
//{
//    qDebug() << "Debut delete";
//    timer->stop();
//    delete timer;
//    _server->close();
//    delete _server;
//    delete labelTop;
//    delete labelDown;
//    info->prev->next = nullptr;
//    delete info;
//    qDebug() << "Fin delete";
//}

void BServer::closeEvent(QCloseEvent *event)
{
    qDebug() << "Coucou !";
    info->prev->next = nullptr;
    delete info;
}
void BServer::onNewConnection()
{
    labelTop->setText("Waiting connection on localhost:4242<br />New Connection");
}

//void BServer::onReadyRead()
//{
//    labelTop->setText("Connected");
//}

void BServer::createCircularGPSInfo()
{
    info = new GPSInfo();
    GPSInfo *tmp = info;
    for (int count = 0 ; count < 19 ; ++count) {
        tmp->next = new GPSInfo();
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    tmp->next = info;
    info->prev = tmp;
}

QString *BServer::getInfo()
{
    QString *data = new QString();
    GPSInfo *tmp = info;
    while (tmp->prev && tmp->prev->getInfo().size())
    {
        data->push_back(tmp->prev->getInfo());
        data->push_back("<br/>");
        tmp = tmp->prev;
        if (tmp == info)
            break;
    }
    return data;
}

void BServer::initGPSTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showGPS()));
    timer->start(1000);
}

void BServer::showGPS()
{
    info->setInfo(GPS[qrand() % 17]);
    info = info->next;

    labelDown->setText(*(getInfo()));
}

