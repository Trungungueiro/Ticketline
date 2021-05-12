#include "pesquisar.h"
#include "ui_pesquisar.h"

Pesquisar::Pesquisar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pesquisar)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();
}

Pesquisar::Pesquisar(const QString &path1,const QString &path2, QWidget *parent)
    :QDialog(parent)
    ,m_qsPath1(path1)
    ,m_qsPath2(path2)
    , ui(new Ui::Pesquisar)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();

    QPixmap pix1("C:/TBD/ATC2/MyCP/fundo_branco.jpg");
    ui->Fundo2->setPixmap(pix1);
    ui->Fundo2->showFullScreen();



    CdataBase novo;
    CViagem viagem;
    CClientes cliente;
    CCompra compra;

    QVector <QString> vect(4);
    QString *data =  vect.data();

    QList <CViagem>::Iterator it;
    int i= 0;
     if(novo.travel_list(path1, listaviagem))
     {
         for(it= listaviagem.begin() ; it!= listaviagem.end() ; ++it)
         {
           data[i++] = (*it).getPath();
           compra.setPath((*it).getPath());
           listacompra.push_back(compra);
         }
     }

    ui->radioButton->setText(data[0]);
    ui->radioButton_2->setText(data[1]);
    ui->radioButton_3->setText(data[2]);
    ui->radioButton_4->setText(data[3]);

     cliente.setPath(path2);
     listacliente.push_front(cliente);
}





Pesquisar::~Pesquisar()
{
    delete ui;
}




void Pesquisar::on_Sair_clicked()
{
    close();
}

void Pesquisar::on_Comprar_clicked()
{

    QList<CCompra>:: iterator it;
    QVector<QString> vect(5);
    QString *data =  vect.data();
    QString ida;
    int i = 0;
    for(it= listacompra.begin() ; it!= listacompra.end(); ++it)
          data[i++] = (*it).getPath();

    if(ui->radioButton->isChecked())
    {
        ida = data[0].mid(0,2);
    }
    else if(ui->radioButton_2->isChecked())
    {
        ida = data[1].mid(0,2);
    }

    else if(ui->radioButton_3->isChecked())
    {
        ida = data[2].mid(0,2);
    }
    else if(ui->radioButton_4->isChecked())
    {
        ida = data[3].mid(0,2);
    }


    QVector <QString> vect1(4);
    QString *data1 =  vect1.data();
    QList<CClientes>:: iterator it2;
    int j=0;
    for(it2 = listacliente.begin() ; it2!= listacliente.end(); ++it2)
            data1[j++] = (*it2).getPath();

    nova_compra = new Comprar(data1[0], ida);
    nova_compra->show();


}
