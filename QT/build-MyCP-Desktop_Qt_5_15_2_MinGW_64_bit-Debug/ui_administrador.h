/********************************************************************************
** Form generated from reading UI file 'administrador.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRADOR_H
#define UI_ADMINISTRADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Administrador
{
public:
    QLabel *Fundo;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *Administrador)
    {
        if (Administrador->objectName().isEmpty())
            Administrador->setObjectName(QString::fromUtf8("Administrador"));
        Administrador->resize(727, 469);
        Fundo = new QLabel(Administrador);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(6, 2, 711, 461));
        pushButton = new QPushButton(Administrador);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 40, 231, 61));
        pushButton_2 = new QPushButton(Administrador);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 140, 231, 61));
        pushButton_3 = new QPushButton(Administrador);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 230, 231, 61));
        pushButton_4 = new QPushButton(Administrador);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 320, 231, 61));
        pushButton_5 = new QPushButton(Administrador);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(310, 410, 61, 31));

        retranslateUi(Administrador);

        QMetaObject::connectSlotsByName(Administrador);
    } // setupUi

    void retranslateUi(QDialog *Administrador)
    {
        Administrador->setWindowTitle(QCoreApplication::translate("Administrador", "Dialog", nullptr));
        Fundo->setText(QString());
        pushButton->setText(QCoreApplication::translate("Administrador", "TOP CLIENTE", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Administrador", "TOP VIAGENS", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Administrador", "VENDA", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Administrador", "ESTATISTICA", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Administrador", "SAIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Administrador: public Ui_Administrador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRADOR_H
