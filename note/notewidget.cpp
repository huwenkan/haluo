#include "notewidget.h"

#include <QDebug>

NoteWidget::NoteWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(450,0,200,200);
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

    QDir dir(notePath);
    QStringList filters;
    filters << "*.txt";
    QStringList fileList = dir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString fileName, fileList)
    {
        fileName = fileName.split(".")[0];
        QListWidgetItem* fileItem = new QListWidgetItem(fileName);
        listWidget->addItem(fileItem);
    }

    widget = new QWidget(listWidget);
    widget->close();
    textEdit = new QTextEdit(widget);
    textEdit->close();

    textEdit->resize(widget->width(),widget->height());
    widget->setWindowModality(Qt::WindowModal);
    widget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    widget->resize(400,400);

    //布局
    QVBoxLayout *textLayout =new QVBoxLayout();
    textLayout->addWidget(textEdit);
    saveButton = new QPushButton("Save",widget);
    textLayout->addWidget(saveButton);
    widget->setLayout(textLayout);

    connect(openButton,&QPushButton::clicked,[&](){
        if(listWidget->currentItem() != nullptr){
            textEdit->show();
            widget->setWindowTitle(listWidget->currentItem()->text());
            QString fileName=listWidget->currentItem()->text().append(".txt").insert(0,notePath);

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
            widget->show();
        }
    });

    connect(saveButton,&QPushButton::clicked,[&](){
        if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(nullptr, "Error", "Failed to save file: " + file->errorString());
        }
        QTextStream out(file);
        out << textEdit->toPlainText();
        file->close();
        widget->close();
    });
    //默认关闭
    close();
}
