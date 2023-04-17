#include "musicwidget.h"


#include <QDebug>

//音乐播放窗口模块
MusicWidget::MusicWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(450,0,400,500);
    //设置音乐窗口
    listWidget = new QListWidget(this);

    QDir dir(musicPath);
    QStringList fileList = dir.entryList( QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString fileName, fileList)
    {
        QListWidgetItem* fileItem = new QListWidgetItem(fileName);
        listWidget->addItem(fileItem);
    }

    //添加音乐，模态窗口
    //设置字体颜色
    QPalette palette = listWidget->palette();
    palette.setColor(QPalette::Text, Qt::black);
    listWidget->setPalette(palette);
    //设置图片背景
    listWidget->setStyleSheet("background-image: url(:/background/gundahuahai.jpg);background-position: center;background-repeat: no-repeat;");

    //添加删除按钮
    QPushButton* addButton = new QPushButton("添加", this);
    QPushButton* deleteButton = new QPushButton("删除", this);
    QPushButton* playButton = new QPushButton("播放", this);
    QPushButton* pauseButton = new QPushButton("暂停", this);
    QPushButton* addPlayerListButton = new QPushButton("添加至播放列表", this);

    //布局
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(addButton);
    hLayout1->addWidget(deleteButton);

    QHBoxLayout *hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(playButton);
    hLayout2->addWidget(pauseButton);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(listWidget);
    vLayout->addWidget(addPlayerListButton);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);

    setLayout(vLayout);

    //音乐播放展示列表
    player = new QMediaPlayer(listWidget);
    //音乐播放列表
    playList = new QMediaPlaylist();
    //设置循环播放
    playList->setPlaybackMode(QMediaPlaylist::Sequential);
    player->setPlaylist(playList);

    //设置按钮信号
    connect(addButton, &QPushButton::clicked, [&]() {
        QString filePath = QFileDialog::getOpenFileName(this,
                                                            tr("Select Music File"),
                                                            QDir::homePath());
        //文件复制到music目录
        QFile sourceFile(filePath);

        QStringList list = filePath.split("/");
        QString fileName = list.at(list.size()-1);

        QFile destinationFile(musicPath + fileName);
        sourceFile.open(QIODevice::ReadOnly);
        destinationFile.open(QIODevice::WriteOnly);

        destinationFile.write(sourceFile.readAll());
        sourceFile.close();
        destinationFile.close();
        //文件添加到展示列表上
        QListWidgetItem *newItem = new QListWidgetItem(fileName);
        listWidget->addItem(newItem);
    });
    connect(deleteButton, &QPushButton::clicked, [&]() {
        QList<QListWidgetItem*> selectedItems = listWidget->selectedItems();
        foreach(QListWidgetItem* item, selectedItems) {
            QString fileName = listWidget->currentItem()->text();
            QString filePath = musicPath + fileName;
            QFile file(filePath);
            file.remove();
            listWidget->takeItem(listWidget->row(item));
            delete item;
        }
    });
    connect(addPlayerListButton, &QPushButton::clicked, [&](){
            QString fileName = listWidget->currentItem()->text();
            QString filePath = musicPath + fileName;
            playList->addMedia(QUrl::fromLocalFile(filePath));
    });
    connect(playButton, &QPushButton::clicked, [&]() {
        QString file = listWidget->currentItem()->text();
        if(fileName.compare(file)==0){
            if (QMediaPlayer::PausedState == player->state() || QMediaPlayer::StoppedState == player->state()) {
                player->play();
            }
        } else {
            fileName = file;
            QUrl musicFile = QUrl::fromLocalFile(musicPath + fileName);
            player->setMedia(musicFile);
            player->setVolume(50);
            playList->addMedia(musicFile);
            player->play();
        }
    });
    connect(pauseButton, &QPushButton::clicked, [&]() {
        if(QMediaPlayer::PlayingState == player->state()){
            player->pause();
        }
    });
    //检测音乐播放完毕，自动播放播放列表中的下一首
    connect(player, &QMediaPlayer::stateChanged, [=](QMediaPlayer::State state) {
        if (state == QMediaPlayer::StoppedState) {
            player->play();
        }
    });
    //默认关闭
    close();
}
