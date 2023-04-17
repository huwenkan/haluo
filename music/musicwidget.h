#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

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
    QString fileName;//当前播放的歌曲
    QMediaPlaylist *playList;
signals:

};

#endif // MUSICWIDGET_H
