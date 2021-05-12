#ifndef CTIPOCARTAO_H
#define CTIPOCARTAO_H
#include <QString>

using namespace std;
class CTipoCartao
{
    int m_iTipoId;
    QString m_qsmodalidade;
    double m_dDescontoCartao;
    double m_dmensalidade;


public:
    CTipoCartao();
    void setTipoId(int tipo)
    {
        m_iTipoId = tipo;
    }
    int getTipoId()
    {
        return m_iTipoId;
    }
};

#endif // CTIPOCARTAO_H
