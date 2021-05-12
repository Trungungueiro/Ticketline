#include "consultar.h"
#include "ui_consultar.h"

Consultar::Consultar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Consultar)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();
}

Consultar::Consultar(const QString &path, QWidget *parent)
    :QDialog(parent),
     m_qsPath(path),
     ui(new Ui::Consultar)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();

    CClientes cliente;
    cliente.setPath(path);
    codcliente.push_front(cliente);




}



Consultar::~Consultar()
{
    delete ui;
}

void Consultar::on_Pesquisar_clicked()
{

    QVector <QString> vect(4);
    QString *data =  vect.data();
    QList<CClientes>:: iterator it;
    int i=0;
    for(it = codcliente.begin() ; it!= codcliente.end(); ++it)
            data[i++]= (*it).getPath();

    //QMessageBox::warning(this,"codcliente", data[0]);



    QString Origem = ui->lineEdit->text();
    QString Destino = ui->lineEdit_2->text();

    CdataBase novo;
    CRota rota;

    if(novo.travel(Origem, Destino, rota))
    {
        int aux1 = rota.getRotaId();
        stringstream ss;
        ss << aux1;
        QString aux2 = QString::fromStdString(ss.str());
        close();
        nova = new Pesquisar(aux2,data[0]);
        nova->show();
    }
    else QMessageBox::warning(this,"origem ou destino incorrecto!","\n") ;



}



void Consultar::on_Sair_clicked()
{
    close();
}
