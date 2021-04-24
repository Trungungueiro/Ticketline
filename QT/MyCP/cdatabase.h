#ifndef CDATABASE_H
#define CDATABASE_H
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>


using namespace std;
class CDataBase
{
public:
    CDataBase();
    bool Login(QString, QString);
};

#endif // CDATABASE_H
