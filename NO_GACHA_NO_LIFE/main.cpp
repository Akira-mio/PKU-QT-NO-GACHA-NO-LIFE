#include "widget.h"
#include "to_start.h"
#include "core_algorithm.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QDir>
#include<QMediaPlayer>
#include<QMediaDevices>
#include<QSoundEffect>
#include<QAudioOutput>
#include<QVideoWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "big_homework_test1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
}

    QMediaPlayer *player=new QMediaPlayer();
    QAudioOutput audioOutput; // chooses the default audio routing
    player->setAudioOutput(&audioOutput);
    player->setSource(QUrl("qrc:/This game.mp3"));
    player->setLoops(-1);
    player->play();
    to_start starting(player);
    starting.show();

    return a.exec();
}
