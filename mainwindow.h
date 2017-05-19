#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QStandardItemModel>
#include <QtNetwork>
#include <QTcpSocket>

#include "my_taxi_server.h"




namespace Ui {
class MainWindow;
}

class my_taxi_server;

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStandardItemModel *model;
    Ui::MainWindow *ui;



    my_taxi_server *serv;

protected slots:
    // Когда сложный объект не модифицируешь, всегда используй константную ссылку.
    // Так эффективнее, обходишься без ненужных копирований.
    void append_server_message(const QString &message);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();

    void newuser();

//    void slotReadClient();

private:


};

#endif // MAINWINDOW_H
