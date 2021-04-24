#include "top_origem.h"
#include "ui_top_origem.h"

Top_Origem::Top_Origem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Top_Origem)
{
    ui->setupUi(this);
    QPixmap pix("C:/TBD/ATC2/MyCP/CP4008_Gondomar.jpg");
    ui->Fundo->setPixmap(pix);
    ui->Fundo->showFullScreen();
}

Top_Origem::~Top_Origem()
{
    delete ui;
}
