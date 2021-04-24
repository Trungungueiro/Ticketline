#include "apagarconta.h"
#include "ui_apagarconta.h"

ApagarConta::ApagarConta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApagarConta)
{
    ui->setupUi(this);
}

ApagarConta::~ApagarConta()
{
    delete ui;
}
