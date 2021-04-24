#include "cvalid.h"

CValid::CValid()
{

}

bool CValid::validtravel(QString aux, CViagem &viagem)
{
  if(aux.size() == 0)
      return false;

  QString traco = "-";

  viagem.setViagemId(aux.mid(0,aux.indexOf(traco)).toInt());
  return true;

}

