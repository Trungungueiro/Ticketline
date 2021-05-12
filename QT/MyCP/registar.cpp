#include "registar.h"
#include "ui_registar.h"
#include <QtDebug>
Registar::Registar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registar)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();
}

Registar::~Registar()
{
    delete ui;
}

void Registar::on_Registar_2_clicked()
{

    /*if(Senha != Conf_Senha)
        QMessageBox::warning(this,"Senhas diferentes!!!", "\n");
    if(Senha.size() <6)
        QMessageBox::warning(this,"Senhas demasiada curta!!!", "\n");
    string aux = Conf_Senha.toStdString();
    int countNumero = 0;
    int countLetra = 0;

    size_t letra = aux.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXZabcdefghijklmnopqrstuvwxz");
    while (letra != string ::npos) {
        countLetra++;
    }
    if(countLetra == 0)
        QMessageBox::warning(this,"Introduz pelo menos 1 caracter!!!", "\n");


    size_t num = aux.find_first_of("1234567890");
    while (num != string ::npos) {
        countNumero++;
    }
    if(countNumero == 0)
        QMessageBox::warning(this,"Introduz pelo menos 1 digito!!!", "\n");*/



    CdataBase novo;
    CClientes cliente;
    cliente.setNome(ui->lineEdit->text());
    cliente.setMorada(ui->lineEdit_2->text());
    QString bi = ui->lineEdit_3->text();
    cliente.setBi(bi.toInt());
    QString nif = ui->lineEdit_4->text();
    cliente.setNif(nif.toInt());
    if(ui->radioButton->isChecked())
        cliente.setSexo("M");
    if(ui->radioButton_2->isChecked())
        cliente.setSexo("F");
    cliente.setDataNasc(ui->lineEdit_5->text());
    cliente.setEmail(ui->lineEdit_6->text());
    QString senha1 = ui->lineEdit_7->text();
    QString senha2 = ui->lineEdit_8->text();
    if(senha1 == senha2)
    {
      cliente.setPassword(senha1);
      if(novo.sign_in(cliente))
      {
          if(novo.login(cliente.getEmail(), cliente.getSenha(), cliente))
          {
              int aux1 = cliente.getCliente_id();
              stringstream ss;
              ss << aux1;
              QString aux2 = QString::fromStdString(ss.str());
              close();
              novo_perfil = new Perfil(aux2);
              novo_perfil->show();
          }

      }


    } else
        QMessageBox::warning(this,"Erro", "Senhas diferente!!!");
}

void Registar::on_Sair_clicked()
{
    close();
}
