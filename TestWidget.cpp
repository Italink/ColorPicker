#include "testwidget.h"

#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
TestWidget::TestWidget(QWidget *parent)
    : QWidget(parent)
    , colorPicker(new ColorPicker())
{
    resize(200,200);
    QPushButton *openPicker=new QPushButton("打开取色器",this);
    connect(openPicker,&QPushButton::pressed,[this](){
        colorPicker->show();
    });
    connect(colorPicker,&ColorPicker::colorSelect,[this](const QColor& c){      //根据信号量修改窗口背景颜色
        this->color=c;
        this->update();
    });

}

TestWidget::~TestWidget()
{

}

void TestWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(rect(),color);
}
