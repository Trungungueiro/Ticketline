#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "top_origem.h"
#include <QDialog>

namespace Ui {
class Administrador;
}

class Administrador : public QDialog
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = 0);
    ~Administrador();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Administrador *ui;
    Top_Origem *origem;
};

#endif // ADMINISTRADOR_H
