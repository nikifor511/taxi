#ifndef MY_TAXI_SERVER_H
#define MY_TAXI_SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QList>



//#include "ui_mainwindow.h"

//class MainWindow;


class my_taxi_server : public QObject
{
    Q_OBJECT
public:
    explicit my_taxi_server(QObject *parent = 0); // конструктор
    ~my_taxi_server();
    //MainWindow *window;

signals:
    add_text(QString);

public slots:
    void connect_new();
    void leer_socketclient();

private:
    QTcpServer *tcpserver;
    QTcpSocket *tcpclient;

};
#endif // MY_TAXI_SERVER_H
