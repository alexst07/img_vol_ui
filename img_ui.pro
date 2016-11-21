#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T19:10:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = img_ui
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp\
        img_utils.cpp

INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += "/home/alex/Unicamp/img/volimg/include"
INCLUDEPATH += "/home/alex/Unicamp/img/libmc920/include"

LIBS += -L/usr/local/lib\
     -lopencv_calib3d\
     -lopencv_core\
     -lopencv_features2d \
     -lopencv_imgcodecs \
     -lopencv_flann\
     -lopencv_highgui\
     -lopencv_imgproc\
     -lopencv_ml\
     -lopencv_objdetect\
     -lopencv_photo\
     -lopencv_stitching\
     -lopencv_superres\
     -lopencv_video\
     -lopencv_videostab

LIBS += -L"/home/alex/Unicamp/img/volimg/build/" -lvolimg


HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
