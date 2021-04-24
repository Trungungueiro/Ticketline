#ifndef CPROMOCAO_H
#define CPROMOCAO_H
#include <QString>

using namespace std;
class CPromocao
{
    int m_ipromocao;
    double m_dDescontoPromocao;
    QString m_qsPromocao;


public:
    CPromocao();
    void setPromocao(int promo)
    {
        m_ipromocao = promo;
    }
    int getPromocao()
    {
        return m_ipromocao;
    }
};

#endif // CPROMOCAO_H
