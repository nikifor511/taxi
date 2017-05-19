#include "my_taxi_server.h"
//#include "mainwindow.h"
//#include "ui_mainwindow.h"


my_taxi_server::my_taxi_server(QObject *parent)
{
    tcpserver = new QTcpServer (this);
    //tcpserver->setMaxPendingConnections();
    tcpserver->listen(QHostAddress::LocalHost, 59590);
    connect(tcpserver, SIGNAL(newConnection()), this, SLOT(connect_new()));
    emit add_text("mes");
    //MainWindow *window = new MainWindow();
    //window->append_server_message("xd");
    //Ui::MainWindow *uu;
    //uu->label_2->setText("45454");
    //window->append_server_message("5454");
    //MainWindow::append_server_message("d");

    //w->append_server_message("f");
    //w->append_server_message("OK on 59590");
    //w.append_server_message("OK on 59590");
    qDebug() << "OK on 59590";
}

my_taxi_server::~my_taxi_server()
{
    //delete ui;
}

void my_taxi_server::connect_new()
{
    //tcpclient = tcpserver->nextPendingConnection();
    connect(tcpclient, SIGNAL(readyRead()), this, SLOT(leer_socketclient()));
}

void my_taxi_server::leer_socketclient()
{
    QByteArray buffer;
    buffer.resize( tcpclient->bytesAvailable() );
    tcpclient->read( buffer.data(), buffer.size() );

    //w->append_server_message(QString (buffer));
}


   // tcpclient->write( ui->lineEdit->text().toLatin1().data(), ui->lineEdit->text().size());

