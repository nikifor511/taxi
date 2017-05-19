#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydb");
    db.setUserName("postgres");
    db.setPassword("STUDENT511");

    bool ok = db.open();
    if (ok)
    {
        ui->label->setText("OK");
        QStringList lst_tables = db.tables();
        ui->comboBox->addItems(lst_tables);
    }
    else
        ui->label->setText("Error Connection");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString current_table = ui->comboBox->currentText();
    QSqlQuery query("SELECT * FROM \"" + current_table + "\"");

    if (query.size() > 0)
    {
        model = new QStandardItemModel(query.size(),3, ui->tableView);
        ui->tableView->setModel(model);

        int row = 0;
        while (query.next())
        {
            for (int i=0; i<3; i++)
            {
                QStandardItem *newItem = new QStandardItem(query.value(i).toString());
                model->setItem(row, i, newItem);
            }
            row++;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    qApp->exit();
}

void MainWindow::append_server_message(QString mes)
{
    ui->label_2->setText(mes);
}

void MainWindow::newuser()
{
   ui->label_2->setText(QString::fromUtf8("Новый юзер!"));
}

void MainWindow::on_pushButton_5_clicked()
{
   serv = new my_taxi_server;

   connect(serv, SIGNAL(add_text(QString)), this, SLOT(append_server_message(QString mes)) );

//     tcpServer = new QTcpServer(this);
//     connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newuser()));
//     if (!tcpServer->listen(QHostAddress::Any, 59590))
//     {
//        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
//        ui->label_2->setText(tcpServer->errorString());
//     }
//     else
//     {
//        qDebug() << tcpServer->isListening() << "TCPSocket listen on port";
//        ui->label_2->setText(QString::fromUtf8("Сервер запущен!"));
//        qDebug() << QString::fromUtf8("Сервер запущен!");
//     }
}
