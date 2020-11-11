#include <QDebug>

#include "Bilberry.h"

Bilberry::Bilberry(QWidget *parent) : QMainWindow(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    server = new QPushButton("Server", this);
    server->setGeometry(50, 25, 400, 50);
    server->setFont(QFont("Times", 18, QFont::Bold));
    connect(server, SIGNAL(clicked()), this, SLOT(B_Server()));

    client = new QPushButton("Client", this);
    client->setGeometry(50, 100, 400, 50);
    client->setFont(QFont("Times", 18, QFont::Bold));
    connect(client, SIGNAL(clicked()), this, SLOT(B_Client()));
}

//Bilberry::~Bilberry()
//{
//    qDebug() << "Delete Bilberry";
//    delete server;
//    delete client;
//    qDebug() << "Fin Delete Bilberry";
//}

void Bilberry::B_Server()
{
    bserver = new BServer(this);
    bserver->setWindowTitle("Bilberry Server");
    bserver->setFixedSize(500, 500);
    bserver->show();
}

void Bilberry::B_Client()
{
    qDebug() << "Client";
}