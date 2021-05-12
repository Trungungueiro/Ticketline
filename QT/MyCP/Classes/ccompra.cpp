#include "ccompra.h"

CCompra::CCompra()
    :m_iCompraId(0), m_dDesconto(0.0),
      m_dCusto(0.0), m_dCustoTotal(0.0), m_qsDataCompra(" "),path(" ")
{

}

CCompra::CCompra(QString aux)
    :path(aux)
{

}

