#include "notewidget.h"

#include <QDebug>

//记事本窗口模块
NoteWidget::NoteWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(450,0,400,500);
    //记事本列表
    listWidget = new QListWidget(this);
    //设置字体
    QPalette listWidgetPalette = listWidget->palette();
    listWidgetPalette.setColor(QPalette::Text, Qt::black);
    listWidget->setPalette(listWidgetPalette);
    //设置背景
    listWidget->setStyleSheet("background-image: url(:/background/qnengtianshi.jpg);background-position: center;background-repeat: no-repeat;");
    //设置功能按钮
    QPushButton *openButton = new QPushButton("打开", this);
    QPushButton *addButton = new QPushButton("新建", this);
    QPushButton *deleteButton = new QPushButton("删除", this);
    QPushButton *modifyFileNameButton = new QPushButton("修改文件名", this);
    //布局
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(openButton);
    hLayout1->addWidget(addButton);
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->addWidget(deleteButton);
    hLayout2->addWidget(modifyFileNameButton);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    layout->addLayout(hLayout1);
    layout->addLayout(hLayout2);
    setLayout(layout);

    //新增记事本窗口
    addNoteWidget = new QWidget(this);
    addNoteWidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    addNoteWidget->setWindowTitle("请输入文件名");
    addNoteWidget->setWindowIcon(QIcon(":/ico/haluo_blue.ico"));
    addNoteNameTextEdit = new QLineEdit(addNoteWidget);
    addNoteNameTextEdit->setReadOnly(false);
    addNoteWidget->resize(350,100);

    //创建新文件&修改文件名
    QPushButton *confirmButton = new QPushButton("确认",addNoteWidget);
    QPushButton *cancelButton = new QPushButton("取消",addNoteWidget);
    connect(confirmButton,&QPushButton::clicked,[&](){
        QString fileName=addNoteNameTextEdit->text();
        QFile file(notePath+fileName);
        file.open(QIODevice::WriteOnly);
        file.close();
        addNoteWidget->close();
        listWidget->addItem(fileName);
    });
    connect(cancelButton,&QPushButton::clicked,[&](){
        addNoteWidget->close();
    });
    //设置新增布局
    QVBoxLayout *confirmAndCancerLayout = new QVBoxLayout();
    confirmAndCancerLayout->addWidget(addNoteNameTextEdit);
    confirmAndCancerLayout->addWidget(confirmButton);
    confirmAndCancerLayout->addWidget(cancelButton);
    addNoteWidget->setLayout(confirmAndCancerLayout);

    QDir dir(notePath);
    QStringList fileList = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString fileName, fileList)
    {
        QListWidgetItem* fileItem = new QListWidgetItem(fileName);
        listWidget->addItem(fileItem);
    }

    //创建文本框载体窗口
    openWidget = new QWidget(listWidget);
    openWidget->setStyleSheet("background-image: url(:/background/nengtianshi.jpg);background-position: center;background-repeat: no-repeat;");
    openWidget->setWindowIcon(QIcon(":/ico/haluo_blue.ico"));
    //默认关闭
    openWidget->close();

    //设置输入文本框窗口
    textEdit = new QTextEdit(openWidget);
    QPalette textEditPalette = textEdit->palette();
    textEditPalette.setColor(QPalette::Text, Qt::black);
    textEdit->setPalette(textEditPalette);
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(textEdit);
    opacityEffect->setOpacity(0.7);
    textEdit->setGraphicsEffect(opacityEffect);
    //默认关闭
    textEdit->close();

    textEdit->resize(openWidget->width(),openWidget->height());
    openWidget->setWindowFlags(Qt::Window);
    openWidget->resize(500,500);

    //设置输入文本框的保存按钮的文本颜色
    saveButton = new QPushButton("保存",openWidget);
    QPalette saveButtonPalette = saveButton->palette();
    saveButtonPalette.setColor(QPalette::ButtonText, Qt::white);
    saveButton->setPalette(saveButtonPalette);

    //输入文本框布局
    QVBoxLayout *textLayout =new QVBoxLayout();
    textLayout->addWidget(textEdit);
    textLayout->addWidget(saveButton);
    openWidget->setLayout(textLayout);

    connect(openButton,&QPushButton::clicked,[&](){
        if(listWidget->currentItem() != nullptr){
            textEdit->show();
            openWidget->setWindowTitle(listWidget->currentItem()->text());
            fileName=notePath + listWidget->currentItem()->text();

            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(nullptr, "Error", "Failed to open file: " + file.errorString());
            }
            QTextStream in(&file);
            textEdit->setText(in.readAll());
            //光标定位到末尾
            QTextCursor cursor = textEdit->textCursor();
            cursor.movePosition(QTextCursor::End);
            textEdit->setTextCursor(cursor);
            textEdit->setFocus();
            file.close();
            openWidget->show();
        }
    });

    connect(saveButton,&QPushButton::clicked,[&](){
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(nullptr, "Error", "Failed to save file: " + file.errorString());
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
        openWidget->close();
    });

    connect(deleteButton,&QPushButton::clicked,[&](){
       QString fileName =  listWidget->currentItem()->text();
       QString filePath = notePath + fileName;
       QFile file(filePath);
       file.remove();
       QListWidgetItem *item = listWidget->currentItem();
       listWidget->takeItem(listWidget->row(item));
       delete item;
    });

    connect(addButton,&QPushButton::clicked,[&](){
        addNoteNameTextEdit->clear();
        addNoteWidget->show();
    });

    modifyNoteNameWidget = new QWidget(this);
    modifyNoteNameWidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    modifyNoteNameWidget->setWindowTitle("请输入文件名");
    modifyNoteNameWidget->setWindowIcon(QIcon(":/ico/haluo_blue.ico"));
    modifyNoteNameWidget->resize(350,100);
    modifyNoteNameTextEdit = new QLineEdit(modifyNoteNameWidget);
    modifyNoteNameTextEdit->setReadOnly(false);

    QPushButton *ModifyconfirmButton = new QPushButton("确认",modifyNoteNameWidget);
    QPushButton *ModifycancelButton = new QPushButton("取消",modifyNoteNameWidget);
    //设置修改文件名窗口布局
    QVBoxLayout *modifyConfirmAndCancerLayout = new QVBoxLayout();
    modifyConfirmAndCancerLayout->addWidget(modifyNoteNameTextEdit);
    modifyConfirmAndCancerLayout->addWidget(ModifyconfirmButton);
    modifyConfirmAndCancerLayout->addWidget(ModifycancelButton);
    modifyNoteNameWidget->setLayout(modifyConfirmAndCancerLayout);

    connect(modifyFileNameButton,&QPushButton::clicked,[&](){
        modifyNoteNameTextEdit->clear();
        modifyNoteNameWidget->show();
    });
    connect(ModifyconfirmButton,&QPushButton::clicked,[&](){
        if(listWidget->currentItem()!=nullptr){
            QString fileName =  listWidget->currentItem()->text();
            QString filePath = notePath + fileName;
            QFile file(filePath);
            fileName=modifyNoteNameTextEdit->text();
            listWidget->currentItem()->setText(fileName);
            file.rename(notePath+fileName);
            file.close();
            modifyNoteNameWidget->close();
        }
    });
    connect(ModifycancelButton,&QPushButton::clicked,[&](){
        modifyNoteNameWidget->close();
    });
    //默认关闭
    close();
}
