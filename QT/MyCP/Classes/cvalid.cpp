#include "cvalid.h"

CValid::CValid()
{

}

void CValid::Validar(QString s1, QString s2)
{
    if(s1 != s2)
        QMessageBox::warning(cC,"Senhas diferentes!!!", "\n");
    if(s1 <6)
        QMessageBox::warning(this,"Senhas demasiada curta!!!", "\n");
    string aux = s2.toStdString();
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
        QMessageBox::warning(this,"Introduz pelo menos 1 digito!!!", "\n");
}

