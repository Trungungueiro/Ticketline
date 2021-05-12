#ifndef CCIDADE_H
#define CCIDADE_H
#include <QString>
#include <QVector>


using namespace std;
class CCidade
{
    int m_iCidadeId;
    QString m_qsNomeCidade;
    QString m_qsEstacao;
    QVector <QString> estacao;
    QVector <QString> cidade;

public:
    CCidade();
    void vetsetEstacao(QVector<QString> aux)
    {
        estacao = aux;
    }
    void vetsetCidade(QVector<QString> aux)
    {
        cidade = aux;
    }
    QVector<QString> vetgetEstacao()
    {
        return estacao;
    }
    QVector<QString> vetgetCidade()
    {
        return cidade;
    }


    void setCidadeId(int cidade)
    {
        m_iCidadeId = cidade;
    }
    void setNomeCidade(QString NomeCidade)
    {
        m_qsNomeCidade = NomeCidade;
    }
    void setEstacao(QString Estacao)
    {
        m_qsEstacao = Estacao;
    }
    int getCidadeID()
    {
        return m_iCidadeId;
    }
    QString getNomeCidade()
    {
        return m_qsNomeCidade;
    }
    QString getEstacao()
    {
        return m_qsEstacao;
    }
};

#endif // CCIDADE_H
