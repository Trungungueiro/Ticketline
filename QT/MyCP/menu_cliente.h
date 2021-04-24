#ifndef MENU_CLIENTE_H
#define MENU_CLIENTE_H
#include "perfil.h"


namespace Ui {
class Menu_Cliente;
}

class Menu_Cliente : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_Cliente(QWidget *parent = 0);
    explicit Menu_Cliente(const QString &path, QWidget *parent = 0);
    //void setPath(QString &path);
    //void on_Perfil_clicked(QString  &path);
    void on_Perfil_clicked(QString &path);
    ~Menu_Cliente();

private slots:

    void on_Sair_clicked();

    //void on_Perfil_clicked();

private:
    Ui::Menu_Cliente *ui;
    Perfil *novo_perfil;
    QString m_qsPath;
};

#endif // MENU_CLIENTE_H
