/********************************************************************************
** Form generated from reading UI file 'comprar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPRAR_H
#define UI_COMPRAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Comprar
{
public:
    QLabel *Fundo;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *Comprar)
    {
        if (Comprar->objectName().isEmpty())
            Comprar->setObjectName(QString::fromUtf8("Comprar"));
        Comprar->resize(747, 476);
        Fundo = new QLabel(Comprar);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(10, 10, 731, 461));
        lineEdit = new QLineEdit(Comprar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 80, 211, 31));
        label = new QLabel(Comprar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 40, 211, 31));
        textBrowser = new QTextBrowser(Comprar);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(175, 151, 351, 251));
        pushButton = new QPushButton(Comprar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 430, 75, 23));

        retranslateUi(Comprar);

        QMetaObject::connectSlotsByName(Comprar);
    } // setupUi

    void retranslateUi(QDialog *Comprar)
    {
        Comprar->setWindowTitle(QCoreApplication::translate("Comprar", "Dialog", nullptr));
        Fundo->setText(QString());
        label->setText(QCoreApplication::translate("Comprar", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#aa0000;\">Codigo Promocional</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Comprar", "Comprar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Comprar: public Ui_Comprar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPRAR_H
