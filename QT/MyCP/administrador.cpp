#include "administrador.h"
#include "ui_administrador.h"

Administrador::Administrador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrador)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();
}

Administrador::~Administrador()
{
    delete ui;
}

void Administrador::on_pushButton_clicked()
{

}

void Administrador::on_pushButton_2_clicked()
{
    origem = new Top_Origem;
    origem->show();
}

void Administrador::on_pushButton_3_clicked()
{

}

void Administrador::on_pushButton_4_clicked()
{

}

void Administrador::on_pushButton_5_clicked()
{
    close();
}
