/********************************************************************************
** Form generated from reading UI file 'perfil.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFIL_H
#define UI_PERFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Perfil
{
public:
    QLabel *Fundo;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QPushButton *Sair;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Perfil)
    {
        if (Perfil->objectName().isEmpty())
            Perfil->setObjectName(QString::fromUtf8("Perfil"));
        Perfil->resize(745, 475);
        Fundo = new QLabel(Perfil);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(0, 10, 721, 451));
        label = new QLabel(Perfil);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 110, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(Perfil);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 120, 241, 16));
        label_2 = new QLabel(Perfil);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 150, 81, 31));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(Perfil);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 160, 241, 16));
        label_3 = new QLabel(Perfil);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 60, 241, 31));
        label_3->setFont(font);
        label_4 = new QLabel(Perfil);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 190, 91, 31));
        label_4->setFont(font);
        lineEdit_3 = new QLineEdit(Perfil);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 200, 241, 16));
        label_7 = new QLabel(Perfil);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 220, 91, 31));
        label_7->setFont(font);
        lineEdit_4 = new QLineEdit(Perfil);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 230, 241, 16));
        Sair = new QPushButton(Perfil);
        Sair->setObjectName(QString::fromUtf8("Sair"));
        Sair->setGeometry(QRect(240, 300, 51, 31));
        pushButton = new QPushButton(Perfil);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 300, 131, 31));
        pushButton_2 = new QPushButton(Perfil);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 302, 101, 31));

        retranslateUi(Perfil);

        QMetaObject::connectSlotsByName(Perfil);
    } // setupUi

    void retranslateUi(QDialog *Perfil)
    {
        Perfil->setWindowTitle(QCoreApplication::translate("Perfil", "Dialog", nullptr));
        Fundo->setText(QString());
        label->setText(QCoreApplication::translate("Perfil", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">NOME</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Perfil", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">MORADA</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Perfil", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#aa0000;\">INFORMA\303\207\303\225ES DO CLIENTE</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Perfil", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">ID CLIENTE</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Perfil", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">E-MAIL</span></p></body></html>", nullptr));
        Sair->setText(QCoreApplication::translate("Perfil", "Sair", nullptr));
        pushButton->setText(QCoreApplication::translate("Perfil", "Consultar Viagens", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Perfil", "Apagar Conta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Perfil: public Ui_Perfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFIL_H
