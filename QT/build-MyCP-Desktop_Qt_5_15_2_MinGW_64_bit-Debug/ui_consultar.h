/********************************************************************************
** Form generated from reading UI file 'consultar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTAR_H
#define UI_CONSULTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Consultar
{
public:
    QLabel *Fundo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *Pesquisar;
    QPushButton *Sair;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;

    void setupUi(QDialog *Consultar)
    {
        if (Consultar->objectName().isEmpty())
            Consultar->setObjectName(QString::fromUtf8("Consultar"));
        Consultar->resize(758, 475);
        Fundo = new QLabel(Consultar);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(6, 10, 1011, 461));
        label = new QLabel(Consultar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 110, 141, 31));
        label_2 = new QLabel(Consultar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 110, 131, 21));
        label_3 = new QLabel(Consultar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 240, 141, 21));
        label_4 = new QLabel(Consultar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 240, 141, 21));
        lineEdit = new QLineEdit(Consultar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 150, 211, 31));
        lineEdit_2 = new QLineEdit(Consultar);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(360, 150, 211, 31));
        Pesquisar = new QPushButton(Consultar);
        Pesquisar->setObjectName(QString::fromUtf8("Pesquisar"));
        Pesquisar->setGeometry(QRect(360, 360, 61, 31));
        Sair = new QPushButton(Consultar);
        Sair->setObjectName(QString::fromUtf8("Sair"));
        Sair->setGeometry(QRect(280, 360, 61, 31));
        dateEdit = new QDateEdit(Consultar);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(90, 280, 211, 31));
        dateEdit_2 = new QDateEdit(Consultar);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(370, 280, 211, 31));

        retranslateUi(Consultar);

        QMetaObject::connectSlotsByName(Consultar);
    } // setupUi

    void retranslateUi(QDialog *Consultar)
    {
        Consultar->setWindowTitle(QCoreApplication::translate("Consultar", "Dialog", nullptr));
        Fundo->setText(QString());
        label->setText(QCoreApplication::translate("Consultar", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#aa0000;\">Origem</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Consultar", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#aa0000;\">Destino</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Consultar", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#aa0000;\">Data de ida</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Consultar", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#aa0000;\">Data de volta</span></p></body></html>", nullptr));
        Pesquisar->setText(QCoreApplication::translate("Consultar", "Pesquisar", nullptr));
        Sair->setText(QCoreApplication::translate("Consultar", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Consultar: public Ui_Consultar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTAR_H
