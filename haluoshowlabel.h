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

    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
signals:

private:
    QPixmap *haluoStaticPixmap[8];
    QPixmap *haluoTouchPixmap[8];
    QTimer *haluoStaticTimer;
    QTimer *haluoTouchTimer;
    int haluoStaticNum=0;
    int haluoToucNum=0;

};

#endif // HALUOSHOWLABEL_H
