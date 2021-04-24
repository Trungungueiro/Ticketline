DROP DATABASE IF EXISTS MyCP;
CREATE DATABASE MyCP;
USE MyCP;


#-------------------------------------------------------------------------------------------------------
#------------------------------------------- TABELAS ---------------------------------------------------
#-------------------------------------------------------------------------------------------------------

CREATE TABLE Clientes
(
 cliente_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 nome VARCHAR(150) NOT NULL,
 morada VARCHAR(150),
 sexo CHAR(1) CHECK(sexo IN ('M','F')),
 bi INT UNSIGNED UNIQUE,
 nif INT UNSIGNED UNIQUE,
 data_nasc DATE,
 e_mail CHAR(30) NOT NULL UNIQUE,
 palavra_passe CHAR(30) NOT NULL,
 
 PRIMARY KEY(cliente_id)
);

CREATE TABLE Tipo_Cartao
(
 tipo_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 modalidade CHAR(8),
 desconto_cartao DOUBLE,
 mensalidade DOUBLE,
 
 PRIMARY KEY(tipo_id)
);

CREATE TABLE Cartoes
(
 cartao_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 data_emissao DATE,
 data_validade DATE,
 tipo INT UNSIGNED NOT NULL,
 cliente INT UNSIGNED NOT NULL,
 
CHECK(data_emissao < data_validade),
 PRIMARY KEY(cartao_id)
);

CREATE TABLE Promocoes
(
 promocao_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 desconto_promocao DOUBLE,
 codigo_promocao VARCHAR(30),
 
 PRIMARY KEY(promocao_id)
);

CREATE TABLE Cidades
(
 cidade_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 nome_cidade VARCHAR(30),
 estacao VARCHAR(30),
 
 PRIMARY KEY(cidade_id)
);

CREATE TABLE Rotas
(
 rota_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 origem INT UNSIGNED NOT NULL,
 destino INT UNSIGNED NOT NULL,
 
 PRIMARY KEY(rota_id)
);

CREATE TABLE Viagens
(
 viagem_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 rota INT UNSIGNED NOT NULL,
 partidas_as VARCHAR(15),
 chegadas_as VARCHAR(15),
 data_de_ida DATE,
 data_de_volta DATE,
 preco DOUBLE,
 
 PRIMARY KEY(viagem_id)
);

CREATE TABLE Compras
(
 compra_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
 viagem INT UNSIGNED NOT NULL, 
 cliente INT UNSIGNED NOT NULL,
 promocao INT UNSIGNED NOT NULL,
 desconto DOUBLE, 
 data_compra DATE,
 custo DOUBLE,
 custo_total DOUBLE,
 
PRIMARY KEY(compra_id)
);

#-------------------------------------------------------------------------------------------------------
#------------------------------------------- VIEWS---------------------------------------------------
#-------------------------------------------------------------------------------------------------------

CREATE VIEW Top_Origem
AS(
    SELECT R.origem, COUNT(*)
    FROM Rotas R, Compras C, Viagem V
    WHERE R.rota_id = V.rota AND V.viagem_id = C.viagem
    GROUP BY(origem)
    
)

CREATE VIEW Top_Destino
AS(
    SELECT R.destino, COUNT(*)
    FROM Rotas R, Compras C, Viagem V
    WHERE R.rota_id = V.rota AND V.viagem_id = C.viagem
    GROUP BY(destino)
    
)



#-------------------------------------------------------------------------------------------------------
#------------------------------------------- PROCEDIMENTOS ---------------------------------------------------
#-------------------------------------------------------------------------------------------------------
DELIMITER //
CREATE PROCEDURE Registrar(IN Nome VARCHAR(150), Morada VARCHAR(150), Sexo CHAR(1), Nif INT, BI INT, Data_Nasc DATE, E_mail CHAR(30), Palavra_Passe CHAR(30))
BEGIN 
INSERT INTO Clientes(nome,morada,sexo,bi,nif,data_nasc, e_mail, palavra_passe) VALUE (Nome, Morada, Sexo, Nif, BI, Data_Nasc, E_mail, Palavra_Passe); COMMIT;
END //

CREATE PROCEDURE Criar_Cartao(IN Cliente INT, Tipo Int)
BEGIN
 INSERT INTO Cartoes
 SET cliente_id = Cliente,
 Tipo = tipo_id,
 data_emissao = current_date(),
 data_validade = (SELECT ADDDATE(current_date(), INTERVAL 4 YEAR )); 
 END//
 
CREATE PROCEDURE Ver_Conta(IN Cliente INT)
BEGIN
SELECT nome, morada, sexo, bi, nif,data_nasc, e_mail
FROM Clientes 
WHERE Cliente = cliente_id;
END//

CREATE PROCEDURE Todos_Clientes()
BEGIN 
SELECT cliente_id, nome, morada, sexo, bi, nif, e_mail, palavra_passe 
FROM Clientes;
END// 

CREATE PROCEDURE Ver_Cartao(IN Cliente INT, Cartao INT)
BEGIN
SELECT Tipo, data_emissao, data_validade
FROM Cartoes
WHERE Cliente = cliente and Cartao = cartao_id;
END//
 
CREATE PROCEDURE Apagar_Conta(IN Cliente INT)
BEGIN
DELETE FROM Clientes
WHERE Cliente = cliente_id;
END//

CREATE PROCEDURE Apagar_Cartao(IN Cliente INT, Cartao INT)
BEGIN
DELETE FROM Cartoes
WHERE Cliente =cliente and Cartao = cartao_id;
END//

CREATE PROCEDURE Entrar(IN E_mail CHAR(30), Palavra_Passe CHAR(30))
BEGIN 
SELECT A.cliente_id, A.nome, A.morada, A.sexo, A.nif, A.bi, A.data_nasc
FROM Clientes A
WHERE E_mail = A.e_mail and Palavra_Passe = A.palavra_passe;
END//

CREATE PROCEDURE Consultar_Estacoes(IN Nome_Cidade VARCHAR(30))
BEGIN 
SELECT cidade_id, nome_cidade, estacao
FROM Cidades
WHERE Nome_Cidade = nome_cidade
ORDER BY estacao;
END//


CREATE  PROCEDURE Consultar_Viagens(IN Origem VARCHAR(30), Destino VARCHAR(30))
BEGIN
SELECT  D.partidas_as, A.nome_cidade, A.estacao, D.chegadas_as, B.nome_cidade, B.estacao, D.data_de_ida, D.preco
FROM Cidades A, Cidades B,Rotas C, Viagens D
WHERE Origem = A.nome_cidade and  Destino = B.nome_cidade and C.origem = A.cidade_id and C.destino = B.cidade_id
                                                                    and C.rota_id = D.rota 
                                                                    ORDER BY D.partidas_as;
END//


CREATE PROCEDURE Comprar_Bilhete(IN Cliente INT, Viagem INT, Promocao INT)
BEGIN
INSERT INTO Compras
SET cliente = (SELECT A.cliente_id FROM Clientes A WHERE Cliente = A.cliente_id),
desconto = (SELECT Desconto_Total(Viagem, Promocao)),
custo = (SELECT Preco_Viagem(Viagem)),
promocao = Promocao,
viagem = Viagem,
data_compra = now(),
custo_total = custo - desconto;
COMMIT;
SELECT B.partidas_as, D.nome_cidade, D.estacao, B.chegadas_as, E.nome_cidade, E.estacao, B.preco, (IFNULL(A.desconto,0)), A.custo_total, A.data_compra
FROM Compras A, Viagens B, Rotas C, Cidades D, Cidades E
WHERE A.viagem = B.viagem_id and B.rota = C.rota_id and C.origem = D.cidade_id and C.destino = E.cidade_id;
END//




#-------------------------------------------------------------------------------------------------------
#------------------------------------------- FUNÇÕES ---------------------------------------------------
#-------------------------------------------------------------------------------------------------------

CREATE FUNCTION Desconto_Total(Cartao INT, Promocao INT)
RETURNS DOUBLE
BEGIN
DECLARE Desconto_Cartao DOUBLE;
DECLARE Desconto_Promocao DOUBLE;
SET Desconto_Cartao = (SELECT desconto_cartao FROM Tipo_Cartao WHERE tipo_id IN(
                                                                               SELECT tipo 
                                                                               FROM Cartoes
                                                                               WHERE Cartao = cartao_id));
SET Desconto_Promocao = (SELECT desconto_promocao FROM Promocoes WHERE Promocao = promocao_id);
RETURN(IFNULL(Desconto_Cartao,0) + IFNULL(Desconto_Promocao,0));
END//

CREATE FUNCTION Preco_Viagem(Viagem INT)
RETURNS DOUBLE 
BEGIN
RETURN(SELECT preco FROM Viagens WHERE Viagem = viagem_id);
END//
DELIMITER ;
 
#-------------------------------------------------------------------------------------------------------
#------------------------------------------- ALTERAR TABELAS ---------------------------------------------------
#-------------------------------------------------------------------------------------------------------
 

ALTER TABLE Cartoes ADD FOREIGN KEY(tipo) REFERENCES Tipo_Cartao(tipo_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT;  
ALTER TABLE Cartoes ADD FOREIGN KEY(cliente) REFERENCES Clientes(cliente_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT; 
ALTER TABLE Rotas ADD FOREIGN KEY(origem) REFERENCES Cidades(cidade_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT; 
ALTER TABLE Rotas ADD FOREIGN KEY(destino) REFERENCES Cidades(cidade_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT; 
ALTER TABLE Viagens ADD FOREIGN KEY(rota) REFERENCES Rotas(rota_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT;
ALTER TABLE Compras ADD FOREIGN KEY(viagem) REFERENCES Viagens(viagem_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT;  
ALTER TABLE Compras ADD FOREIGN KEY(cliente) REFERENCES Clientes(cliente_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT;
ALTER TABLE Compras ADD FOREIGN KEY(promocao) REFERENCES Promocoes(promocao_id) ON UPDATE CASCADE ON DELETE CASCADE; COMMIT;



#-------------------------------------------------------------------------------------------------------
#------------------------------------------- INSERIR TABELAS ---------------------------------------------------
#-------------------------------------------------------------------------------------------------------



INSERT INTO Clientes(nome,morada,sexo,bi,nif,data_nasc, e_mail, palavra_passe) VALUE ('Angelo Nhaga', 'Combatentes','M', 72853, 35827, 05/06/1975, 'Nhaga@cp.pt', 'CVNhaga75'); COMMIT;
INSERT INTO Clientes(nome,morada,sexo,bi,nif,data_nasc, e_mail, palavra_passe) VALUE ('Eladio Munar', 'Azurem', 'M',  69370, 7396, 28/10/1993,'Munar@cp.pt', 'ANGMunar75'); COMMIT;
INSERT INTO Clientes(nome,morada,sexo,bi,nif,data_nasc, e_mail, palavra_passe) VALUE ('Fidel Kussunga', 'Azurem', 'M', 72671, 17627, 11/11/1975,'Fidel@cp.pt', 'ANGMunar75'); COMMIT;

INSERT INTO Tipo_Cartao(modalidade, desconto_cartao, mensalidade) VALUE('Gold', 5.0, 50.0); COMMIT;
INSERT INTO Tipo_Cartao(modalidade, desconto_cartao, mensalidade) VALUE('Silver',3.5,35.0); COMMIT;
INSERT INTO Tipo_Cartao(modalidade, desconto_cartao, mensalidade) VALUE('Bronze',1.5, 15.0); COMMIT;

INSERT INTO Cartoes(data_emissao,data_validade, tipo,cliente) VALUE(02/06/2016, 02/06/2020,1, 3); COMMIT;
INSERT INTO Cartoes(data_emissao,data_validade, tipo,cliente) VALUE(02/06/2016, 02/06/2020,3, 2); COMMIT;
INSERT INTO Cartoes(data_emissao,data_validade, tipo,cliente) VALUE(02/06/2016, 02/06/2020, 1, 1); COMMIT;

INSERT INTO Promocoes(codigo_promocao, desconto_promocao) VALUE('Natal', 1.50); COMMIT;
INSERT INTO Promocoes(codigo_promocao, desconto_promocao) VALUE('Aniversario', 2.50); COMMIT;
INSERT INTO Promocoes(codigo_promocao, desconto_promocao) VALUE('Pascoa', 1.35); COMMIT;

INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Lisboa', 'Sete Rios'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Lisboa', 'Oriente'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Porto', 'Sao Bento'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Porto', 'Campanha'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Guimaraes', 'Guimaraes'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Algarve', 'Faro'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Algarve', 'Portimao'); COMMIT;
INSERT INTO Cidades(nome_cidade, estacao) VALUE ('Braga', 'Braga'); COMMIT; 


INSERT INTO Rotas(origem,destino) VALUE (1,2 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (1,3 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (1,4 ); COMMIT; 
INSERT INTO Rotas(origem,destino) VALUE (1,5 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (1,6 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (1,7 ); COMMIT; 
INSERT INTO Rotas(origem,destino) VALUE (2,1 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (2,3 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (2,4 ); COMMIT; 
INSERT INTO Rotas(origem,destino) VALUE (2,5 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (2,6 ); COMMIT;
INSERT INTO Rotas(origem,destino) VALUE (2,7 ); COMMIT; 


INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (1, '07:30', '07:45', 3.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (1, '12:30', '12:45', 3.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (1, '18:15', '18:35', 3.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (1, '21:50', '22:05', 3.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (2, '08:30', '11:45', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (2, '13:30', '16:45', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (2, '16:15', '19:00', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (2, '21:50', '00:05', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (3, '08:30', '11:55', 15.25 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (3, '13:30', '16:55', 15.25 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (3, '16:15', '19:10', 15.25 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (3, '21:50', '00:15', 15.25 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (4, '07:15', '13:25', 21.05 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (4, '14:30', '19:40', 21.05 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (4, '18:05', '23:15', 21.05 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (5, '08:30', '11:45', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (5, '13:30', '16:45', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (5, '16:15', '19:00', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (5, '21:50', '00:05', 14.95 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (6, '08:30', '12:15', 16.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (6, '13:30', '17:15', 16.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (6, '16:15', '19:25', 16.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (6, '21:50', '00:30', 16.45 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (7, '09:15', '12:25', 18.15 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (7, '13:30', '16:40', 18.15 ); COMMIT;
INSERT INTO Viagens(rota, partidas_as, chegadas_as, preco) VALUE (7, '19:05', '21:15', 18.15 ); COMMIT;




#-------------------------------------------------------------------------------------------------------
#----------------------------------------  MAIN -----------------------------------------------
#-------------------------------------------------------------------------------------------------------

/*CALL Registrar('Nuno Cardoso', 'Braga', 'M', 12345, 54321, 25/12/1978, 'linuno@cp.pt', 'ATC2HACKER');
CALL Entrar('Munar@cp.pt','ANGMunar75');
CALL Consultar_Estacoes('Lisboa');
/*CALL Consultar_Viagens(1,11/06/2016);*/
CALL Todos_Clientes();
#CALL Consultar_Viagens('Lisboa', 'Porto');
CALL Comprar_Bilhete(1, 7, 2);


