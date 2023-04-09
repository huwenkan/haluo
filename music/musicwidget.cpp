#include "musicwidget.h"


#include <QDebug>

//音乐播放窗口模块
MusicWidget::MusicWidget(QWidget *parent) : QWidget(parent)
{
    //设置音乐窗口
    listWidget = new QListWidget(this);

    QDir dir(musicPath);
    QStringList filters;
    filters << "*.txt"<<"*.mp3"<<"*.wav";

    QStringList fileList = dir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString fileName, fileList)
    {
        fileName = fileName.split(".")[0];
        QListWidgetItem* fileItem = new QListWidgetItem(fileName);
        listWidget->addItem(fileItem);
    }

    //添加音乐，模态窗口
    //修改favico

    //添加删除按钮
    QPushButton* addButton = new QPushButton("添加", this);
    QPushButton* deleteButton = new QPushButton("删除", this);
    connect(addButton, &QPushButton::clicked, [&]() {
        QString filePath = QFileDialog::getOpenFileName(this,
                                                            tr("Select Music File"),
                                                            QDir::homePath(),
                                                            tr("Music Files (*.mp3 *.wav *.ogg)"));
        //文件复制到music目录
        QFile sourceFile(filePath);
        QFile destinationFile(musicPath);
        sourceFile.open(QIODevice::ReadOnly);
        destinationFile.open(QIODevice::WriteOnly);
        destinationFile.write(sourceFile.readAll());
        sourceFile.close();
        destinationFile.close();
        //文件添加到播放列表上
        QStringList list = filePath.split("/");
        QString fileName = list.at(list.size()-1);
        fileName = fileName.split(".")[0];

        QListWidgetItem* newItem = new QListWidgetItem(fileName);
        listWidget->addItem(newItem);

        qDebug() << fileName;
    });
    connect(deleteButton, &QPushButton::clicked, [&]() {
        QList<QListWidgetItem*> selectedItems = listWidget->selectedItems();
        foreach(QListWidgetItem* item, selectedItems) {
            listWidget->takeItem(listWidget->row(item));
            delete item;
        }
    });
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    setLayout(layout);
    setGeometry(400,0,150,200);

   //设置音乐播放器
    player = new QMediaPlayer(listWidget);
    connect(listWidget,&QListWidget::itemClicked,[&](){
        if(!playerFlag){
            QString fileName = listWidget->currentItem()->text();
            fileName.append(".mp3");
            qDebug()<<QUrl::fromLocalFile("D:\\QTProject\\build-haluo-Desktop_Qt_5_12_10_MinGW_32_bit-Debug\\debug\\music\\I_Really_Want_to_Stay_At_Your_House.mp3");
            player->setMedia(QUrl::fromLocalFile(fileName));
            player->setVolume(50);
            player->play();
            playerFlag = true;
        } else {
            player->pause();
            playerFlag = false;
        }

    });
    //默认关闭
    close();
}
