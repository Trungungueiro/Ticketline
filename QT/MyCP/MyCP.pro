#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T17:01:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyCP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pesquisar.cpp \
    registar.cpp \
    perfil.cpp \
    consultar.cpp \
    Classes/cclientes.cpp \
    Classes/cdatabase.cpp \
    Classes/ctipocartao.cpp \
    Classes/ccartao.cpp \
    Classes/cpromocao.cpp \
    Classes/ccidade.cpp \
    Classes/crota.cpp \
    Classes/cviagem.cpp \
    Classes/ccompra.cpp \
    comprar.cpp \
    Auxiliar/cvalid.cpp \
    administrador.cpp \
    top_origem.cpp

HEADERS  += mainwindow.h \
    pesquisar.h \
    registar.h \
    perfil.h \
    consultar.h \
    Classes/cclientes.h \
    Classes/cdatabase.h \
    Classes/ctipocartao.h \
    Classes/ccartao.h \
    Classes/cpromocao.h \
    Classes/ccidade.h \
    Classes/crota.h \
    Classes/cviagem.h \
    Classes/ccompra.h \
    comprar.h \
    Auxiliar/cvalid.h \
    administrador.h \
    top_origem.h

FORMS    += mainwindow.ui \
    pesquisar.ui \
    registar.ui \
    perfil.ui \
    consultar.ui \
    comprar.ui \
    administrador.ui \
    top_origem.ui
