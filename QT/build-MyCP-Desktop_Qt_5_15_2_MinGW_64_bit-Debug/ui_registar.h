/********************************************************************************
** Form generated from reading UI file 'registar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTAR_H
#define UI_REGISTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Registar
{
public:
    QLabel *Fundo;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QPushButton *Registar_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *Sair;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *Registar)
    {
        if (Registar->objectName().isEmpty())
            Registar->setObjectName(QString::fromUtf8("Registar"));
        Registar->resize(752, 403);
        Fundo = new QLabel(Registar);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(10, 12, 731, 381));
        lineEdit = new QLineEdit(Registar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 80, 241, 16));
        label = new QLabel(Registar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 70, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(Registar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 100, 81, 31));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(Registar);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 110, 241, 16));
        label_3 = new QLabel(Registar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 130, 61, 31));
        label_3->setFont(font);
        lineEdit_3 = new QLineEdit(Registar);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(300, 140, 241, 16));
        label_4 = new QLabel(Registar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 160, 81, 31));
        label_4->setFont(font);
        lineEdit_4 = new QLineEdit(Registar);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(300, 170, 241, 16));
        label_5 = new QLabel(Registar);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 190, 81, 31));
        label_5->setFont(font);
        label_6 = new QLabel(Registar);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 220, 91, 31));
        label_6->setFont(font);
        label_7 = new QLabel(Registar);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 250, 91, 31));
        label_7->setFont(font);
        lineEdit_6 = new QLineEdit(Registar);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(300, 260, 241, 16));
        label_8 = new QLabel(Registar);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 280, 81, 31));
        label_8->setFont(font);
        lineEdit_7 = new QLineEdit(Registar);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(300, 290, 241, 16));
        label_9 = new QLabel(Registar);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 310, 111, 31));
        label_9->setFont(font);
        lineEdit_8 = new QLineEdit(Registar);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(300, 320, 241, 16));
        Registar_2 = new QPushButton(Registar);
        Registar_2->setObjectName(QString::fromUtf8("Registar_2"));
        Registar_2->setGeometry(QRect(570, 320, 75, 23));
        radioButton = new QRadioButton(Registar);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(300, 190, 82, 17));
        radioButton_2 = new QRadioButton(Registar);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(360, 190, 82, 17));
        Sair = new QPushButton(Registar);
        Sair->setObjectName(QString::fromUtf8("Sair"));
        Sair->setGeometry(QRect(680, 360, 51, 31));
        lineEdit_5 = new QLineEdit(Registar);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(300, 230, 241, 16));

        retranslateUi(Registar);

        QMetaObject::connectSlotsByName(Registar);
    } // setupUi

    void retranslateUi(QDialog *Registar)
    {
        Registar->setWindowTitle(QCoreApplication::translate("Registar", "Dialog", nullptr));
        Fundo->setText(QString());
        label->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">NOME</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">MORADA</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">NIF</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">BI</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">GENERO</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">DATA NASC</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">E-MAIL</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-weight:600; color:#aa0000;\">SENHA</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Registar", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">REPETE SENHA </span></p></body></html>", nullptr));
        Registar_2->setText(QCoreApplication::translate("Registar", "Registar", nullptr));
        radioButton->setText(QCoreApplication::translate("Registar", "M", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Registar", "F", nullptr));
        Sair->setText(QCoreApplication::translate("Registar", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registar: public Ui_Registar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTAR_H
