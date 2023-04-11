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
    //布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    layout->addWidget(openButton);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    setLayout(layout);

    //新增记事本窗口
    addNoteWidget = new QWidget(this);
    addNoteWidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    addNoteWidget->setWindowTitle("请输入文件名");
    noteNameTextEdit = new QLineEdit(addNoteWidget);
    noteNameTextEdit->setReadOnly(false);
    addNoteWidget->resize(350,100);
//    noteNameTextEdit = new QLineEdit(addNoteWidget);
//    noteNameTextEdit->setPlaceholderText("请输入...");
//    noteNameTextEdit->setAttribute(Qt::WA_InputMethodEnabled);
//    noteNameTextEdit->setFocus();
//    addNoteWidget->resize(350,100);
//    // 获取屏幕的宽度和高度
//    QScreen *screen = QGuiApplication::primaryScreen();
//    QRect screenGeometry = screen->geometry();
//    int screenWidth = screenGeometry.width();
//    int screenHeight = screenGeometry.height();
//    // 获取窗口的宽度和高度
//    int width = addNoteWidget->width();
//    int height = addNoteWidget->height();
//    // 将窗口移动到屏幕的中心
//    addNoteWidget->move((screenWidth - width) / 2, (screenHeight - height) / 2);

    QPushButton *confirmButton = new QPushButton("确认",addNoteWidget);
    QPushButton *cancerButton = new QPushButton("取消",addNoteWidget);
    connect(confirmButton,&QPushButton::clicked,[&](){
        QString fileName=noteNameTextEdit->text();
        QFile file(notePath+fileName);
        file.open(QIODevice::WriteOnly);
        file.close();
        addNoteWidget->close();
        listWidget->addItem(fileName);
    });
    connect(cancerButton,&QPushButton::clicked,[&](){
        addNoteWidget->close();
    });
    //设置新增布局
    QVBoxLayout *confirmAndCancerLayout = new QVBoxLayout();
    confirmAndCancerLayout->addWidget(noteNameTextEdit);
    confirmAndCancerLayout->addWidget(confirmButton);
    confirmAndCancerLayout->addWidget(cancerButton);
    addNoteWidget->setLayout(confirmAndCancerLayout);

    QDir dir(notePath);
    QStringList fileList = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    foreach (QString fileName, fileList)
    {
        QListWidgetItem* fileItem = new QListWidgetItem(fileName);
        listWidget->addItem(fileItem);
    }

    openWidget = new QWidget(listWidget);
    openWidget->close();
    textEdit = new QTextEdit(openWidget);
    textEdit->close();

    textEdit->resize(openWidget->width(),openWidget->height());
    openWidget->setWindowModality(Qt::WindowModal);
    openWidget->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    openWidget->resize(400,400);

    //布局
    QVBoxLayout *textLayout =new QVBoxLayout();
    textLayout->addWidget(textEdit);
    saveButton = new QPushButton("Save",openWidget);
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
        addNoteWidget->show();
    });
    //默认关闭
    close();
}
