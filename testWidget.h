#ifndef WIDGET_H
#define WIDGET_H

#include "colorpicker.h"

#include <QWidget>

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    TestWidget(QWidget *parent = 0);
    ~TestWidget();
private:
    QColor color;
    ColorPicker *colorPicker;
protected:
    void paintEvent(QPaintEvent *e);
};

#endif // WIDGET_H
