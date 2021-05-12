#include "cdatabase.h"

CdataBase::CdataBase()
{

}

bool CdataBase::login(QString e_mail, QString password, CClientes &cliente)
{

    const QString aux("SELECT D.nome, D.e_mail, D.morada, D.bi, D.nif, D.data_nasc, cliente_id\
                       FROM Clientes D\
                       WHERE D.e_mail =\'" + e_mail + "\'AND D.palavra_passe =\'" + password +"\';");

    QSqlQuery query;
    if(query.exec(aux))
    {
        if(query.next())
        {
           // cliente.setNome(query.value(0).toS);
            cliente.setCliente_id(query.value(6).toInt());

            return true;
        }

    }

    return false;
}

bool CdataBase::sign_in(CClientes &cliente)
{

    const QString registrar("CALL Registrar(?, ?, ?, ?, ?, ?, ?, ?)");
    QSqlQuery query;
    if(query.prepare(registrar))
    {
        query.addBindValue(cliente.getNome());
        query.addBindValue(cliente.getMorada());
        query.addBindValue(cliente.getSexo());
        int aux1 = cliente.getBi();
        stringstream s1;
        s1 << aux1;
        QString aux2 = QString::fromStdString(s1.str());
        query.addBindValue(aux2);
        int aux3 = cliente.getNif();
        stringstream s2;
        s2 << aux3;
        QString aux4 = QString::fromStdString(s1.str());
        query.addBindValue(aux4);
        query.addBindValue(cliente.getDataNasc());
        query.addBindValue(cliente.getEmail());
        query.addBindValue(cliente.getSenha());
        query.exec();
        return true;
    }
 return false;

}



bool CdataBase::travel(QString Origem, QString Destino, CRota &rota)
{
    const QString aux("SELECT  C.rota_id\
                              FROM Cidades A, Cidades B,Rotas C, Viagens D\
                              WHERE A.nome_cidade=\'" + Origem  + "\' AND B.nome_cidade=\'"+ Destino + "\' AND C.origem = A.cidade_id AND C.destino = B.cidade_id AND C.rota_id = D.rota ORDER BY D.partidas_as");
            QSqlQuery query;
            if(query.exec(aux))
             {
                 if(query.next())
                 {
                      rota.setRotaId(query.value(0).toInt());
                      return true;
                 }
             }



  return false;

}

bool CdataBase::show_user(QString User, CClientes &cliente)
{


    const QString perfil("SELECT A.nome, A.morada, A.cliente_id, A.e_mail\
                        FROM Clientes A\
                        WHERE A.cliente_id=\'"+ User +"\';");
    QSqlQuery query;

            if(query.exec(perfil))
            {
                if(query.next())
                {
                    cliente.setNome(query.value(0).toString());
                    cliente.setMorada(query.value(1).toString());
                    cliente.setCliente_id(query.value(2).toInt());
                    cliente.setEmail(query.value(3).toString());
                    return true;
                }
            }

       return false;

}

bool CdataBase::delete_user(QString user)
{
    const QString aux("CALL Apagar_Conta(?)");
    //const QString aux1(" DELETE FROM Clientes A WHERE A.cliente_id=\'"+ user + "\';");

     QSqlQuery query;
    if(query.prepare(aux))
    {
        query.addBindValue(user);
        if(query.exec())
        {
            return true;
        }

    }
    return false;
}

bool CdataBase::update_user(QString user)
{
    return false;
}

bool CdataBase::travel_list(QString travel, QList<CViagem>& listaviagem)
{
    const QString aux("SELECT D.partidas_as, A.nome_cidade, A.estacao, D.chegadas_as, B.nome_cidade, B.estacao, D.preco, D.viagem_id\
                             FROM Cidades A, Cidades B,Rotas C, Viagens D\
                             WHERE C.rota_id=\'" + travel +"\'AND C.origem = A.cidade_id AND C.destino = B.cidade_id\
                             AND C.rota_id = D.rota\
                             ORDER BY D.partidas_as");

    QSqlQuery query;
    if(query.exec(aux))
    {

        while(query.next())
        {
           CViagem viagem;
           viagem.setPreco(query.value(6).toDouble());
           double aux1 = viagem.getPreco();
           stringstream ss;
           ss << aux1;
           QString aux2 = QString::fromStdString(ss.str());

           viagem.setPartida(query.value(0).toString());
           QString aux3 = query.value(1).toString();
           QString aux4 = query.value(2).toString();
           viagem.setChegada(query.value(3).toString());
           QString aux5= query.value(4).toString();
           QString aux6 = query.value(5).toString();
           viagem.setViagemId(query.value(7).toInt());
           int aux7 = viagem.getViagemId();
           stringstream s1;
           s1 << aux7;
           QString aux8 = QString::fromStdString(s1.str());
           viagem.setPath(aux8 + " - "+viagem.getPartida()+ " - " +aux3 + " - " + aux4 + " - " +
                      viagem.getChegada()+ " - " + aux5+ " - " + aux6+ " - " +
                       aux2 + "€");
           listaviagem.push_back(viagem);
        }

      return true;
    }


    return false;
}

bool CdataBase::top_user()
{


return true;
}

bool CdataBase::top_source(CCidade &cidade)
{
    const QString aux1("SELECT * FROM Top_Origem;");
    //const QString aux2("SELECT * FROM Top_Destino;");

    QSqlQuery query1;
    if(query1.exec(aux1))
    {
        if(query1.next())
        {
            cidade.setNomeCidade(query1.value(0).toString());
            cidade.setEstacao(query1.value(1).toString());
            return true;
        }

    }

    return false;

}

bool CdataBase::buy_ticket(QString cliente, QString viagem, QString promocao, CCompra &compra, CViagem &viagem2)
{

    const QString aux1("INSERT INTO Compras\
                        SET cliente = (SELECT A.cliente_id FROM Clientes A WHERE A.cliente_id = ?),\
                        desconto = (SELECT Desconto_Total(?, ?)),\
                        custo = (SELECT Preco_Viagem(?)),\
                        promocao = ?,\
                        data_compra = now(),\
                        custo_total = custo - desconto;");



   const  QString aux2("SELECT B.partidas_as, B.chegadas_as, B.preco, (IFNULL(A.desconto,0)), A.custo_total, A.data_compra\
                       FROM Compras A, Viagens B, Rotas C, Cidades D, Cidades E\
                       WHERE A.viagem = B.viagem_id and B.rota = C.rota_id and C.origem = D.cidade_id and C.destino = E.cidade_id;");

   QSqlQuery query;
   if(query.prepare(aux1))
   {
     query.addBindValue(cliente);
     query.addBindValue(viagem);
     query.addBindValue(promocao);
     query.addBindValue(viagem);
     query.addBindValue(promocao);
     if(query.exec(aux2))
     {
        if(query.next())
        {
             viagem2.setPartida(query.value(0).toString());
             viagem2.setChegada(query.value(1).toString());
             viagem2.setPreco(query.value(2).toDouble());
             compra.setDesconto(query.value(3).toDouble());
             compra.setCustoTotal(query.value(4).toDouble());
             compra.setData(query.value(5).toString());
             return true;

         }
     }

   }
    return false;

}

