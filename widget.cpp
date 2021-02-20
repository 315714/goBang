#include "widget.h"
#include "ui_widget.h"
#include <QPainter>//创建画家类
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("五子棋");
    this->resize(375,375);
    //去边框
    //5this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    isblack = false;
    iswhile = false;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    //创建画家
    QPainter painter(this);
    //定义线条颜色
    painter.setPen(QPen(Qt::white));
    //画线条
    for(int i=0;i<15;i++)
    {
        painter.drawLine(0,y,375,y+=25);
    }
    for(int j=0;j<15;j++)
    {
        painter.drawLine(x,0,x+=25,375);
    }
    x = 0;
    y = 0;

    //定义黑棋画刷
    QBrush blackbrush(Qt::black);
    //定义白棋画刷
    QBrush whilebrush(Qt::white);
    //设置抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    //循环已下过的棋子
    for(int i=0;i<point.count();i++)
    {
        //画圆
        if(i%2==0)//单数画黑棋，双数画白棋
        {
            //画圆
            painter.setBrush(blackbrush);
            painter.drawEllipse(point.at(i),10,10);

        }
        else
        {
            painter.setBrush(whilebrush);
            painter.drawEllipse(point.at(i),10,10);
        }
    }

    //画黑子
    if(isblack)
    {
        //利用画家画圆
        QPainter newpainter(this);
        //设置背景
        QBrush brush(Qt::black);
        newpainter.setBrush(brush);
        qDebug()<< blackpoint;
        newpainter.setRenderHint(QPainter::Antialiasing);
        point.append(blackpoint-QPoint(8,31)-this->frameGeometry().topLeft());
        newpainter.drawEllipse(blackpoint-QPoint(8,31)-this->frameGeometry().topLeft(),10,10);
        qDebug()<<"画黑子";
        isblack = false;
    }
    if(iswhile)//画白子
    {
        //利用画家画圆
        QPainter newpainter(this);
        //设置背景
        QBrush brush(Qt::white);
        newpainter.setBrush(brush);
        newpainter.setRenderHint(QPainter::Antialiasing);
        point.append(whilepoint-QPoint(8,31)-this->frameGeometry().topLeft());
        newpainter.drawEllipse(whilepoint-QPoint(8,31)-this->frameGeometry().topLeft(),10,10);
        qDebug()<<"画白子";
        iswhile = false;

    }
    //qDebug()<< "执行画家";
}

//鼠标事件
void Widget::mousePressEvent(QMouseEvent *event)
{

    if(event->buttons() == Qt::LeftButton)
    {
        blackpoint = event->globalPos();
        qDebug()<< "黑子单击";
        isblack = true;
        update();
    }
    if(event->buttons() == Qt::RightButton)
    {
        //获取鼠标坐标
        whilepoint = event->globalPos();
        qDebug()<< "白子单击";
        iswhile = true;
        update();
    }
}
