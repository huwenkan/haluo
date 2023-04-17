#include "musicwidget.h"


#include <QDebug>

//音乐播放窗口模块
MusicWidget::MusicWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(450,0,400,400);
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
    palette.setColor(QPalette::Text, Qt::white);
    listWidget->setPalette(palette);
    //设置图片背景
    listWidget->setStyleSheet("background-image: url(:/background/gunda.jpg);background-position: center;background-repeat: no-repeat;");
//    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
//    opacityEffect->setOpacity(0.7);
//    listWidget->setGraphicsEffect(opacityEffect);

    //添加删除按钮
    QPushButton* addButton = new QPushButton("添加", this);
    QPushButton* deleteButton = new QPushButton("删除", this);
    QPushButton* playButton = new QPushButton("播放", this);
    QPushButton* pauseButton = new QPushButton("暂停", this);

    //布局
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(addButton);
    hLayout1->addWidget(deleteButton);

    QHBoxLayout *hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(playButton);
    hLayout2->addWidget(pauseButton);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(listWidget);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);

    setLayout(vLayout);

    //设置音乐播放列表
    player = new QMediaPlayer(listWidget);

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
        //文件添加到播放列表上
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
    connect(playButton, &QPushButton::clicked, [&]() {
        QString file = listWidget->currentItem()->text();
        if(fileName.compare(file)==0){
            if (QMediaPlayer::PausedState == player->state() || QMediaPlayer::StoppedState == player->state()) {
                player->play();
            }
        } else {
            fileName = listWidget->currentItem()->text();
            player->setMedia(QUrl::fromLocalFile(musicPath + fileName));
            player->setVolume(50);
            player->play();
        }
    });
    connect(pauseButton, &QPushButton::clicked, [&]() {
        if(QMediaPlayer::PlayingState == player->state()){
            player->pause();
        }
    });
    //默认关闭
    close();
}
