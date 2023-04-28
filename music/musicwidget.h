#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include "haluoshow.h"

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout >
#include <QDir>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioFormat>
#include <QLabel>
#include <QMediaPlaylist>
#include <QMovie>

class MusicWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MusicWidget(QWidget *parent = nullptr);
    //显示窗口标志
    bool musicFlag = false;
    QString musicPath=QDir::currentPath().append("/music/");
    QMediaPlayer *player;
    QListWidget *listWidget;
    QMediaPlaylist *playList;
    QMovie *movie;

signals:

};

#endif // MUSICWIDGET_H
