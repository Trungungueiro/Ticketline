/********************************************************************************
** Form generated from reading UI file 'pesquisar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PESQUISAR_H
#define UI_PESQUISAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Pesquisar
{
public:
    QLabel *Fundo;
    QGroupBox *groupBox;
    QLabel *Fundo2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label;
    QGroupBox *groupBox_2;
    QPushButton *Comprar;
    QPushButton *Sair;

    void setupUi(QDialog *Pesquisar)
    {
        if (Pesquisar->objectName().isEmpty())
            Pesquisar->setObjectName(QString::fromUtf8("Pesquisar"));
        Pesquisar->resize(803, 531);
        Fundo = new QLabel(Pesquisar);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(6, 20, 791, 501));
        groupBox = new QGroupBox(Pesquisar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 381, 221));
        Fundo2 = new QLabel(groupBox);
        Fundo2->setObjectName(QString::fromUtf8("Fundo2"));
        Fundo2->setGeometry(QRect(6, 10, 371, 261));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 60, 341, 21));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 100, 341, 21));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 140, 341, 21));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 180, 341, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 341, 16));
        groupBox_2 = new QGroupBox(Pesquisar);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 90, 361, 221));
        Comprar = new QPushButton(Pesquisar);
        Comprar->setObjectName(QString::fromUtf8("Comprar"));
        Comprar->setGeometry(QRect(430, 350, 75, 23));
        Sair = new QPushButton(Pesquisar);
        Sair->setObjectName(QString::fromUtf8("Sair"));
        Sair->setGeometry(QRect(320, 350, 75, 23));
        Fundo->raise();
        groupBox->raise();
        groupBox_2->raise();
        Comprar->raise();
        Sair->raise();

        retranslateUi(Pesquisar);

        QMetaObject::connectSlotsByName(Pesquisar);
    } // setupUi

    void retranslateUi(QDialog *Pesquisar)
    {
        Pesquisar->setWindowTitle(QCoreApplication::translate("Pesquisar", "Dialog", nullptr));
        Fundo->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Pesquisar", "Horario de Ida", nullptr));
        Fundo2->setText(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        label->setText(QCoreApplication::translate("Pesquisar", "Partida   Cidade    Estacao    Chegada     Cidade      Estacao    Preco", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Pesquisar", "Horario de Volta", nullptr));
        Comprar->setText(QCoreApplication::translate("Pesquisar", "Selecionar", nullptr));
        Sair->setText(QCoreApplication::translate("Pesquisar", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pesquisar: public Ui_Pesquisar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PESQUISAR_H
