#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDir>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>

class NoteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NoteWidget(QWidget *parent = nullptr);
    //显示窗口标志
    bool noteFlag = false;
    QListWidget *listWidget;
    QString notePath=QDir::currentPath().append("/note/");
    QTextEdit *textEdit;
    QWidget *widget;
    QFile *file;
    QPushButton *saveButton;

signals:

};

#endif // NOTEWIDGET_H
