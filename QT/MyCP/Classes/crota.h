#ifndef CROTA_H
#define CROTA_H
#include <QString>

class CRota
{
    int m_iRotaId;
public:
    CRota();
    void setRotaId(int rota)
    {
        m_iRotaId = rota;
    }
    int getRotaId()
    {
        return m_iRotaId;
    }
};

#endif // CROTA_H
