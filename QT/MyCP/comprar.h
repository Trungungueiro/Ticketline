#ifndef COMPRAR_H
#define COMPRAR_H
#include "Classes/cdatabase.h"
#include <QDialog>

namespace Ui {
class Comprar;
}

class Comprar : public QDialog
{
    Q_OBJECT

public:
    explicit Comprar(QWidget *parent = 0);
    explicit Comprar(const QString &path1, const QString &path2, QWidget *parent = 0);
    ~Comprar();

private slots:
    void on_pushButton_clicked();

private:
    QString m_qsPath1;
    QString m_qsPath2;
    Ui::Comprar *ui;
    QList <CViagem> listaviagem;
    QList<CClientes> listacliente;
};

#endif // COMPRAR_H
