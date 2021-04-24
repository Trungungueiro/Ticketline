#ifndef CCOMPRA_H
#define CCOMPRA_H
#include "Classes/cclientes.h"
#include "Classes/cviagem.h"
#include "Classes/cpromocao.h"

class CCompra
{
    int m_iCompraId;
    double m_dDesconto;
    double m_dCusto;
    double m_dCustoTotal;
    QString m_qsDataCompra;
    QString path;

public:
    CCompra();
    CCompra(QString);
    void setPath(QString aux)
    {
        path = aux;
    }
    QString getPath()
    {
        return path;
    }


    void setCompraId(int compra)
    {
        m_iCompraId = compra;
    }
    void setDesconto(double desconto)
    {
        m_dDesconto = desconto;
    }
    void setCusto(double custo)
    {
        m_dCusto = custo;
    }
    void setCustoTotal(double custoT)
    {
        m_dCustoTotal = custoT;
    }
    void setData(QString data)
    {
        m_qsDataCompra = data;
    }
    int getCompraId()
    {
        return m_iCompraId;
    }
    double getDesconto()
    {
        return m_dDesconto;
    }
    double getCusto()
    {
        return m_dCusto;
    }
    double getCustoTotal()
    {
        return m_dCustoTotal;
    }
    QString getData()
    {
        return m_qsDataCompra;
    }



};

#endif // CCOMPRA_H
