#include "notewidget.h"

#include <QDebug>

NoteWidget::NoteWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(400,0,200,200);
    //记事本列表
    listWidget = new QListWidget(this);
    QPushButton *openButton = new QPushButton("打开", this);
    QPushButton *addButton = new QPushButton("新建", this);
    QPushButton *deleteButton = new QPushButton("删除", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    layout->addWidget(openButton);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    setLayout(layout);
    setGeometry(400,0,150,200);

    QDir dir(notePath);
    QStringList filters;
    filters << "*.txt";
    QStringList fileList = dir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString fileName, fileList)
    {
        fileName = fileName.split(".")[0];
        QListWidgetItem* fileItem = new QListWidgetItem(fileName);
//        qDebug()<<fileName;
        listWidget->addItem(fileItem);
    }

    widget = new QWidget(listWidget);
    widget->close();
    textEdit = new QTextEdit(widget);
    textEdit->close();

    widget->setWindowModality(Qt::WindowModal);
    widget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    widget->resize(400,400);

    QVBoxLayout *layout1 =new QVBoxLayout();
    layout->addWidget(textEdit);
    QPushButton *saveButton = new QPushButton("Save",widget);
    layout->addWidget(saveButton);
    widget->setLayout(layout1);

    connect(openButton,&QPushButton::clicked,[&](){
        if(listWidget->currentItem() != nullptr){
            textEdit->show();
//            widget->setWindowModality(Qt::WindowModal);
//            widget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
//            widget->resize(400,400);
            widget->setWindowTitle(listWidget->currentItem()->text());
            QString fileName=listWidget->currentItem()->text().append(".txt").insert(0,"/debug/note/").insert(0,QDir::currentPath());

            file = new QFile(fileName);
            if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(nullptr, "Error", "Failed to open file: " + file->errorString());
            }
            QTextStream in(file);
            textEdit->setText(in.readAll());
            //光标定位到末尾
            QTextCursor cursor = textEdit->textCursor();
            cursor.movePosition(QTextCursor::End);
            textEdit->setTextCursor(cursor);
            textEdit->setFocus();
            file->close();
            if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::warning(nullptr, "Error", "Failed to save file: " + file->errorString());
            }

            //布局
//            QVBoxLayout *layout =new QVBoxLayout();
//            layout->addWidget(textEdit);
//            QPushButton *saveButton = new QPushButton("Save");
//            layout->addWidget(saveButton);
//            widget->setLayout(layout);
            textEdit->resize(widget->width(),widget->height());
            widget->show();
            connect(saveButton,&QPushButton::clicked,[&](){
                QTextStream out(file);
//                qDebug()<<textEdit->toPlainText();
                out << textEdit->toPlainText();
                file->close();
                widget->close();
            });
        }
    });
    //默认关闭
    close();
}
