#include "perfil.h"
#include "ui_perfil.h"

Perfil::Perfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perfil)
{
    ui->setupUi(this);

    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();

}

Perfil::Perfil(const QString &path, QWidget *parent)
    :QDialog(parent)
    ,m_qsPath(path)
    , ui(new Ui::Perfil)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();

    CdataBase novo;
    CClientes cliente;




    if(novo.show_user(path,cliente))
    {
        int aux1 = cliente.getCliente_id();
        stringstream ss;
        ss << aux1;
        QString aux2 = QString::fromStdString(ss.str());
        cliente.setPath(aux2);
        codcliente.push_front(cliente);
        ui->lineEdit->setText(cliente.getNome());
        ui->lineEdit_2->setText(cliente.getMorada());
        ui->lineEdit_3->setText(aux2);
        ui->lineEdit_4->setText(cliente.getEmail());

    }

    cliente.setPath(path);
    codcliente.push_front(cliente);




}

Perfil::~Perfil()
{
    delete ui;
}


void Perfil::on_Sair_clicked()
{
    close();
    /*inicio = new MainWindow;
    inicio->show();*/

}


void Perfil::on_pushButton_clicked()
{

    QVector <QString> vect(4);
    QString *data =  vect.data();
    QList<CClientes>:: iterator it;
    int i=0;
    for(it = codcliente.begin() ; it!= codcliente.end(); ++it)
            data[i++]= (*it).getPath();


    //QMessageBox::warning(this,"codcliente", data[0]);

    nova_consulta = new Consultar(data[0]);
    nova_consulta->show();

}

void Perfil::on_pushButton_2_clicked()
{
    CdataBase novo;


   QList<CClientes>:: iterator it;
   QVector<QString> vect(1);
   QString *data= vect.data();
   int i= 0;
   for(it= codcliente.begin(); it!= codcliente.end(); it++)
       data[i++] = (*it).getPath();


    if(novo.delete_user(data[0]))
    {
        QMessageBox::warning(this, "Conta eliminada", "Sentimos muito!!!");
        close();
    }else QMessageBox::warning(this, "Conta nao eliminada", "falhou");
}
