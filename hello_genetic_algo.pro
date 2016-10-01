QT += core gui charts

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hello_genetic_algo

TEMPLATE = app

SOURCES += \
    main.cpp \
    Controller.cpp \
    Worker.cpp \
    Chart.cpp

HEADERS += \
    Controller.hpp \
    Worker.hpp \
    Chart.hpp
