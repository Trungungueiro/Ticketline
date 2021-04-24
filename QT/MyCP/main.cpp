#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("MyCP");
    db.setUserName("root");
    db.setPassword("Eladiomy14");
    if(!db.open())
    {
       //ui->textBrowser->setText(db.lastError().text());

    } else
        w.showMaximized();

    return a.exec();
}
