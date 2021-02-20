#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //定位点坐标
    int x =0;
    int y =0;

private:
    Ui::Widget *ui;

    //创建定时器
    //void timerEvent(QTimerEvent *event);

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);


    bool iswhile;//白子
    bool isblack;//黑子
    QPoint whilepoint;//白子坐标
    QPoint blackpoint;//黑子坐标
    //棋盘所处坐标
    //QPoint checkerboard;

    //定义数组，记录所有棋子的坐标
    QList<QPoint> point;

};

#endif // WIDGET_H
