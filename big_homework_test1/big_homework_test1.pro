QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card_properties.cpp \
    cutscene.cpp \
    gacha_1_time.cpp \
    gacha_5_times.cpp \
    main.cpp \
    to_start.cpp \
    widget.cpp

HEADERS += \
    card_properties.h \
    cutscene.h \
    gacha_1_time.h \
    gacha_5_times.h \
    to_start.h \
    widget.h

FORMS += \
    card_properties.ui \
    cutscene.ui \
    gacha_1_time.ui \
    gacha_5_times.ui \
    to_start.ui \
    widget.ui

TRANSLATIONS += \
    big_homework_test1_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
