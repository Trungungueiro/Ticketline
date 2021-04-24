/********************************************************************************
** Form generated from reading UI file 'top_origem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOP_ORIGEM_H
#define UI_TOP_ORIGEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Top_Origem
{
public:
    QLabel *Fundo;

    void setupUi(QDialog *Top_Origem)
    {
        if (Top_Origem->objectName().isEmpty())
            Top_Origem->setObjectName(QString::fromUtf8("Top_Origem"));
        Top_Origem->resize(748, 466);
        Fundo = new QLabel(Top_Origem);
        Fundo->setObjectName(QString::fromUtf8("Fundo"));
        Fundo->setGeometry(QRect(6, 2, 731, 461));

        retranslateUi(Top_Origem);

        QMetaObject::connectSlotsByName(Top_Origem);
    } // setupUi

    void retranslateUi(QDialog *Top_Origem)
    {
        Top_Origem->setWindowTitle(QCoreApplication::translate("Top_Origem", "Dialog", nullptr));
        Fundo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Top_Origem: public Ui_Top_Origem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOP_ORIGEM_H
