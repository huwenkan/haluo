#ifndef HALUOSHOWLABEL_H
#define HALUOSHOWLABEL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class HaluoShowLabel : public QLabel
{
    Q_OBJECT
public:
    explicit HaluoShowLabel(QWidget *parent = nullptr);

    int haluoStaticNum=0;
    int haluoTouchNum=0;
    QTimer *haluoStaticTimer;
    QTimer *haluoTouchTimer;

    QPixmap *haluoStaticPixmap[8];
    QPixmap *haluoTouchPixmap[8];
    QPixmap *haluoStaticBlackPixmap[8];
    QPixmap *haluoTouchBlackPixmap[8];

    QPixmap *staticShowPixmap[8];
    QPixmap *touchShowPixmap[8];

    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
signals:

private:
};

#endif // HALUOSHOWLABEL_H
