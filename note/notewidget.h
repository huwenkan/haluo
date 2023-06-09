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
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QApplication>
#include <QScreen>
#include <QGraphicsOpacityEffect>

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
    QWidget *openWidget;
    QString  fileName;
    QPushButton *saveButton;
    QWidget *addNoteWidget;
    QWidget *modifyNoteNameWidget;
    QLineEdit *addNoteNameTextEdit;
    QLineEdit *modifyNoteNameTextEdit;

signals:

};

#endif // NOTEWIDGET_H
