#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "registar.h"
#include "administrador.h"
#include "Classes/cdatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_Entrar_clicked();

    void on_Registar_clicked();


    void on_Sair_clicked();

private:
    Ui::MainWindow *ui;
    Perfil *novo_perfil;
    Registar *novo_registo;
    Administrador *novo_adm;

};

#endif // MAINWINDOW_H
