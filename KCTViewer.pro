#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T00:17:48
#
#-------------------------------------------------

QT       += core gui webkitwidgets qml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KCTViewer
TEMPLATE = app

SOURCES += main.cpp \
	KVMainWindow.cpp \
	KVProxyServer.cpp

HEADERS  += KVMainWindow.h \
	KVProxyServer.h

RESOURCES += resources.qrc
