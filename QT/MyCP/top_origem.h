#ifndef TOP_ORIGEM_H
#define TOP_ORIGEM_H

#include <QDialog>

namespace Ui {
class Top_Origem;
}

class Top_Origem : public QDialog
{
    Q_OBJECT

public:
    explicit Top_Origem(QWidget *parent = 0);
    ~Top_Origem();

private:
    Ui::Top_Origem *ui;
};

#endif // TOP_ORIGEM_H
