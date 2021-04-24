#ifndef CDATABASE_H
#define CDATABASE_H
#include "sstream"
#include <QSqlQuery>
#include <QMessageBox>
#include <Qtsql>
#include <QVector>
#include <QList>
#include "Classes/cclientes.h"
#include "Classes/ccartao.h"
#include "Classes/ccidade.h"
#include "Classes/crota.h"
#include "Classes/cviagem.h"
#include "Classes/cpromocao.h"
#include "Classes/ccompra.h"

class CdataBase
{
    QList <CViagem> listaviagem;

public:
    CdataBase();
    bool login(QString, QString, CClientes&);
    bool sign_in(CClientes&);
    bool travel(QString, QString, CRota&);
    bool show_user(QString, CClientes &);
    bool delete_user(QString);
    bool update_user(QString);
    bool travel_list(QString, QList<CViagem>&);
    bool top_user();
    bool top_source(CCidade&);
    bool sale();
    bool statistics();
    bool buy_ticket(QString, QString, QString, CCompra&, CViagem&);
};

#endif // CDATABASE_H
