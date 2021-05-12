#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Entrar_clicked()
{

    QString E_mail = ui->lineEdit->text();
    QString Senha = ui->lineEdit_2->text();


    CdataBase novo;
    CClientes cliente;

    if(novo.login(E_mail, Senha, cliente))
    {
        int aux1 = cliente.getCliente_id();
        stringstream ss;
        ss << aux1;
        QString aux2 = QString::fromStdString(ss.str());
        close();
        if(cliente.getCliente_id() == 2)
        {
            novo_adm = new Administrador;
            novo_adm->show();
        }
        else
        {
            novo_perfil = new Perfil(aux2);
            novo_perfil->show();

        }



    }
    else QMessageBox::warning(this,"Erro no Login","e-mail ou password errado");
}


void MainWindow::on_Registar_clicked()
{
 novo_registo = new Registar;
 novo_registo->show();
}



void MainWindow::on_Sair_clicked()
{
  close();
}
