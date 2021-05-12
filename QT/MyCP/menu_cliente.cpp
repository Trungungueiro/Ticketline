#include "menu_cliente.h"
#include "ui_menu_cliente.h"

Menu_Cliente::Menu_Cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_Cliente)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("MyCP");
    db.setUserName("root");
    db.setPassword("Eladiomy14");

       if(db.open())
       {
          // ui->lineEdit_3->setText("Connected to Database");
       }
       else
    {
       // ui->lineEdit_3->setText("Not Connected to Database");
    }
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();


}

Menu_Cliente::Menu_Cliente(const QString &path, QWidget *parent)
    :QDialog(parent)
    ,m_qsPath(path)
    ,ui(new Ui::Menu_Cliente)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();

}


Menu_Cliente::~Menu_Cliente()
{
    delete ui;
}


/*void Menu_Cliente::on_Perfil_clicked(QString &path)
{
    QSqlQuery query;

    const QString Menu("SELECT A.id_cliente FROM Clientes A WHERE A.id_cliente=\'"+ path +"\';");

    if(query.exec(Menu))
    {
        if(query.next())
        {
            QString aux  = query.value(0).toString();
            Perfil novo;
            novo.on_pushButton_clicked(aux);
            //novo.show();
            novo_perfil = new Perfil;
            novo_perfil->show();
        }
    }


}*/

void Menu_Cliente::on_Sair_clicked()
{
    close();
}

/*void Menu_Cliente::setPath(QString &path)
{
    m_qsPath = path;
}*/

void Menu_Cliente::on_Perfil_clicked(QString &path)
{
    QSqlQuery query;

    const QString Menu("SELECT A.id_cliente FROM Clientes A WHERE A.id_cliente=\'"+ path +"\';");

    if(query.exec(Menu))
    {
        if(query.next())
        {
            QString aux  = query.value(0).toString();
            Perfil novo;
            novo.on_pushButton_clicked(aux);
            //novo.show();
            novo_perfil = new Perfil;
            novo_perfil->show();
        }
    }

}
