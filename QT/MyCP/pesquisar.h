#ifndef PESQUISAR_H
#define PESQUISAR_H
#include <Qtsql>
#include <QString>
#include <QDialog>
#include <QFileInfo>
#include <QVector>
#include <QMessageBox>
#include <QSqlQuery>
#include "string"
#include "Classes/cdatabase.h"
#include "comprar.h"
#include "Auxiliar/cvalid.h"
#include <QList>

namespace Ui {
class Pesquisar;
}

class Pesquisar : public QDialog
{
    Q_OBJECT

public:
    explicit Pesquisar(QWidget *parent = 0);
    explicit Pesquisar(const QString &path1, const QString &path2, QWidget *parent = 0);
    ~Pesquisar();

private slots:

    void on_Sair_clicked();

    void on_Comprar_clicked();

private:
    QString m_qsPath1;
    QString m_qsPath2;
    Ui::Pesquisar *ui;
    Comprar *nova_compra;
    QList <CViagem> listaviagem;
    QList<CClientes> listacliente;
    QList<CCompra> listacompra;




};

#endif // PESQUISAR_H
