QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card_properties.cpp \
    choosestate.cpp \
    core_algorithm.cpp \
    course.cpp \
    cutscene.cpp \
    diycard.cpp \
    gacha_1_time.cpp \
    gacha_5_scene.cpp \
    gacha_5_times.cpp \
    gacha_scene.cpp \
    main.cpp \
    mypushbutton.cpp \
    password.cpp \
    random.cpp \
    setting.cpp \
    shop.cpp \
    shoppushbutton.cpp \
    theend.cpp \
    to_start.cpp \
    trueend.cpp \
    widget.cpp \
    card.cpp \
    character.cpp \
    news.cpp \
    yourrestart.cpp

HEADERS += \
    card_properties.h \
    choosestate.h \
    core_algorithm.h \
    course.h \
    cutscene.h \
    diycard.h \
    gacha_1_time.h \
    gacha_5_scene.h \
    gacha_5_times.h \
    gacha_scene.h \
    mypushbutton.h \
    password.h \
    random.h \
    setting.h \
    shop.h \
    shoppushbutton.h \
    theend.h \
    to_start.h \
    trueend.h \
    widget.h \
    card.h \
    character.h \
    news.h \
    yourrestart.h

FORMS += \
    card_properties.ui \
    choosestate.ui \
    course.ui \
    cutscene.ui \
    diycard.ui \
    gacha_1_time.ui \
    gacha_5_scene.ui \
    gacha_5_times.ui \
    gacha_scene.ui \
    password.ui \
    random.ui \
    setting.ui \
    shop.ui \
    theend.ui \
    to_start.ui \
    trueend.ui \
    widget.ui \
    yourrestart.ui

TRANSLATIONS += \
    big_homework_test1_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data.qrc \
    pictures.qrc \
    sound.qrc

DISTFILES += \
    ../build-Game_Life-Desktop_Qt_6_5_1_MinGW_64_bit-Debug/card1.txt \
    ../build-Game_Life-Desktop_Qt_6_5_1_MinGW_64_bit-Debug/mycard.txt \
    ../build-Game_Life-Desktop_Qt_6_5_1_MinGW_64_bit-Debug/news1.txt \
    ../build-Game_Life-Desktop_Qt_6_5_1_MinGW_64_bit-Debug/savedata.txt \
    pictures/news_background.png
