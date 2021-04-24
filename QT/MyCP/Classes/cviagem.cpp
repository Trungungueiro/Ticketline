#include "cviagem.h"

CViagem::CViagem()
    :m_ViagemId(0), m_qsPartida(" "), m_qsChegada(" "), m_qsDataIda(" "),
      m_qsDataVolta(" "), m_dPreco(0.0), path(" ")
{

}

CViagem::CViagem(QString aux)
    :path(aux)
{

}


