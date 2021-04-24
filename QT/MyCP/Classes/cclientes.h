#ifndef CCLIENTES_H
#define CCLIENTES_H
#include <QString>



using namespace std;

class CClientes
{
    int m_iClienteId;
    QString m_qsNome;
    QString m_qsMorada;
    QString m_qsSexo;
    int m_iBi;
    int m_iNif;
    QString m_qsDataNasc;
    QString m_qsEmail;
    QString m_qsSenha;
    QString path;


public:
    CClientes();
    CClientes(QString);
    void setPath(QString aux)
    {
        path = aux;
    }
    QString getPath()
    {
        return path;
    }

    void setCliente_id(int cliente_id)
    {
        m_iClienteId = cliente_id;
    }
    void setNome(QString nome)
    {
        m_qsNome = nome;
    }
    void setMorada(QString morada)
    {
        m_qsMorada = morada;
    }
    void setSexo(QString sexo)
    {
        m_qsSexo = sexo;
    }
    void setBi(int bi)
    {
        m_iBi = bi;
    }
    void setNif(int nif)
    {
        m_iNif = nif;
    }
    void setDataNasc(QString data)
    {
        m_qsDataNasc = data;
    }
    void setEmail(QString e_mail)
    {
        m_qsEmail = e_mail;
    }
    void setPassword(QString password)
    {
        m_qsSenha = password;
    }
    int getCliente_id()
    {
        return m_iClienteId;
    }
    QString getNome()
    {
        return m_qsNome;
    }
    QString getMorada()
    {
        return m_qsMorada;
    }
    QString getSexo()
    {
        return m_qsSexo;
    }
    int getBi()
    {
        return m_iBi;
    }
    int getNif()
    {
        return m_iNif;
    }
    QString getDataNasc()
    {
        return m_qsDataNasc;
    }
    QString getEmail()
    {
        return m_qsEmail;
    }
    QString getSenha()
    {
        return m_qsSenha;
    }


};

#endif // CCLIENTES_H
