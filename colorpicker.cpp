#include "colorpicker.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
ColorPicker::ColorPicker(QWidget *parent)
    : QWidget(parent)
    , mousedropper(new MouseDropper(this))
{
     resize(QApplication::desktop()->screen()->size());
     this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);      //设置为无边框窗口
     this->setAttribute(Qt::WA_TranslucentBackground);
     this->setCursor(QCursor(QPixmap("./res/ico/取色笔.png"),0,19));
}

void ColorPicker::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(rect(),QColor(255,255,255,1));
}

void ColorPicker::mousePressEvent(QMouseEvent *e)
{
    emit colorSelect(mousedropper->getColor());
    close();
}
