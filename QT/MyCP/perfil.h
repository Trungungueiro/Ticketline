#ifndef PERFIL_H
#define PERFIL_H
#include "consultar.h"
#include <QVector>
//#include "mainwindow.h"

namespace Ui {
class Perfil;
}

class Perfil : public QDialog
{
    Q_OBJECT

public:
    explicit Perfil(QWidget *parent = 0);
    explicit Perfil(const QString &path, QWidget *parent = 0);
    ~Perfil();

    //void Perfil_Cliente(QString);

private slots:
    void on_Sair_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    QString m_qsPath;
    Ui::Perfil *ui;
    QList<CClientes> codcliente;
    Consultar *nova_consulta;

};

#endif // PERFIL_H
