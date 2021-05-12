#ifndef ENTRAR_H
#define ENTRAR_H
#include "entrar.h"
#include "perfil.h"
namespace Ui {
class Entrar;
}

class Entrar : public QDialog
{
    Q_OBJECT

public:
    explicit Entrar(QWidget *parent = 0);
    ~Entrar();

private slots:
    void on_Apagar_clicked();

    void on_Entrar_2_clicked();

    void on_Sair_clicked();

private:
    Ui::Entrar *ui;
    Perfil  *novo_perfil;
};

#endif // ENTRAR_H
