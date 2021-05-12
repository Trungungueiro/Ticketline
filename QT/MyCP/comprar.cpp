#include "comprar.h"
#include "ui_comprar.h"

Comprar::Comprar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Comprar)
{
    ui->setupUi(this);
}

Comprar::Comprar(const QString &path1, const QString &path2, QWidget *parent)
    :QDialog(parent),
      m_qsPath1(path1),
      m_qsPath2(path2),
      ui(new Ui::Comprar)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();


    CClientes cliente;
    cliente.setPath(path1);
    listacliente.push_front(cliente);

    CViagem viagem;
    viagem.setPath(path2);
    listaviagem.push_front(viagem);


}

Comprar::~Comprar()
{
    delete ui;
}

void Comprar::on_pushButton_clicked()
{
    QList<CClientes>::iterator it;
    QVector<QString> vect(2);
    QString *data = vect.data();
    int i= 0;
    for(it = listacliente.begin(); it!= listacliente.end(); ++it)
        data[i++] = (*it).getPath();

    QList<CViagem>::iterator it1;
    QVector<QString> vect1(2);
    QString *data1 = vect1.data();
    int j= 0;
    for(it1 = listaviagem.begin(); it1!= listaviagem.end(); ++it1)
        data1[j++] = (*it1).getPath();

        CdataBase ndb;
        CCompra compra;
        CViagem viagem;
        QString promo = ui->lineEdit->text();

        if(ndb.buy_ticket(data[0],data1[0],promo,compra, viagem))
        {
           double aux1 = viagem.getPreco();
           stringstream s1;
           s1 << aux1;
           QString preco = QString::fromStdString(s1.str());

           double aux2 = compra.getDesconto();
           stringstream s2;
           s2 << aux2;
           QString desconto = QString::fromStdString(s2.str());

           double aux3 = compra.getCustoTotal();
           stringstream s3;
           s3 << aux3;
           QString custo = QString::fromStdString(s3.str());

           ui->textBrowser->append("MyCP \n\n Bilheteria\n\n\n\n");
           ui->textBrowser->append("Partida as: " + viagem.getPartida() + "    " + "Chegada as: " + viagem.getChegada() +"\n");
           //ui->textBrowser->append("Origem : " +  cidade.getNomeCidade()+ "    " + "Destino : " + cidade.getEstacao() +"\n");
           ui->textBrowser->append("Preco: "+ preco + " €" + "\n");
           ui->textBrowser->append("Desconto: "+ desconto+ " €" + "\n");
           ui->textBrowser->append("Custo Total: "+ custo +" €" + "\n");
           ui->textBrowser->append("               Muito Obrigado pela preferencia");


        }
        else QMessageBox::warning(this, "erro ", data[0] +" " +data1[0]+ " "+ promo);




}
