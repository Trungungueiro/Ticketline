#ifndef REGISTAR_H
#define REGISTAR_H
#include "perfil.h"
#include "Classes/cdatabase.h"

using namespace std;
namespace Ui {
class Registar;
}

class Registar : public QDialog
{
    Q_OBJECT

public:
    explicit Registar(QWidget *parent = 0);
    ~Registar();

private slots:

    void on_Registar_2_clicked();

    void on_Sair_clicked();

private:
    Ui::Registar *ui;
    Perfil *novo_perfil;

};

#endif // REGISTAR_H
