#include "entrar.h"
#include "ui_entrar.h"


Entrar::Entrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entrar)
{

    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();
}

Entrar::~Entrar()
{
    delete ui;
  //  db.close();
}

void Entrar::on_Apagar_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

void Entrar::on_Entrar_2_clicked()
{
    QString E_mail = ui->lineEdit->text();
    QString Senha = ui->lineEdit_2->text();

   QSqlQuery query;
   const QString entrar("SELECT D.nome, D.e_mail, D.morada, D.bi, D.nif, D.data_nasc, cliente_id\
                          FROM Clientes D\
                          WHERE D.e_mail =\'" + E_mail + "\'AND D.palavra_passe =\'" + Senha +"\';");


    if(query.exec(entrar))
        {
             if(query.next())
             {
                 QString Nome = "Nome : "+ query.value(0).toString() + "\n" +
                                 "Mail: "+ query.value(1).toString() ;

                 QMessageBox::warning(this,"Seja Bem vindo!!!",Nome) ;
                 QString aux = query.value(6).toString();
                 novo_perfil = new Perfil(aux);
                 novo_perfil->show();

             } else
           QMessageBox::warning(this,"E-mail ou Senha errado!!!","\n") ;
          }
    }





void Entrar::on_Sair_clicked()
{
    close();
}
