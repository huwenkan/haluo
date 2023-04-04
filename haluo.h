#ifndef HALUO_H
#define HALUO_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class haluo; }
QT_END_NAMESPACE

class haluo : public QWidget
{
    Q_OBJECT

public:
    haluo(QWidget *parent = nullptr);
    ~haluo();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::haluo *ui;
};
#endif // HALUO_H
