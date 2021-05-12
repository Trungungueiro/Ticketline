#ifndef CONSULTAR_H
#define CONSULTAR_H
#include "pesquisar.h"
#include "Classes/cdatabase.h"

namespace Ui {
class Consultar;
}

class Consultar : public QDialog
{
    Q_OBJECT

public:
    explicit Consultar(QWidget *parent = 0);
    explicit Consultar(const QString &path,QWidget *parent = 0);
    ~Consultar();

private slots:
    void on_Pesquisar_clicked();


    void on_Sair_clicked();

private:
    QString m_qsPath;
    Ui::Consultar *ui;
    Pesquisar *nova;
    QList<CClientes> codcliente;
};

#endif // CONSULTAR_H
