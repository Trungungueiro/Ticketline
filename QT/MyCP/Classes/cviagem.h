#ifndef CVIAGEM_H
#define CVIAGEM_H
#include <QString>

class CViagem
{
    int m_ViagemId;
    QString m_qsPartida;
    QString m_qsChegada;
    QString m_qsDataIda;
    QString m_qsDataVolta;
    double m_dPreco;
    QString path;


public:
    CViagem();
    CViagem(QString);
    QString getPath()
    {
        return path;
    }
    void setPath(QString aux)
    {
        path = aux;
    }
    void setViagemId(int viagem)
    {
        m_ViagemId = viagem;
    }
    void setPartida(QString partida)
    {
        m_qsPartida = partida;
    }
    void setChegada(QString chegada)
    {
        m_qsChegada = chegada;
    }
    void setPreco(double preco)
    {
        m_dPreco = preco;
    }
    int getViagemId()
    {
        return m_ViagemId;
    }
    QString getPartida()
    {
        return m_qsPartida;
    }
    QString getChegada()
    {
        return m_qsChegada;
    }
    double getPreco()
    {
        return m_dPreco;
    }
};

#endif // CVIAGEM_H
