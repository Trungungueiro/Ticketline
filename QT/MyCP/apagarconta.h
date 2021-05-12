#ifndef APAGARCONTA_H
#define APAGARCONTA_H

#include <QDialog>

namespace Ui {
class ApagarConta;
}

class ApagarConta : public QDialog
{
    Q_OBJECT

public:
    explicit ApagarConta(QWidget *parent = 0);
    ~ApagarConta();

private:
    Ui::ApagarConta *ui;
};

#endif // APAGARCONTA_H
