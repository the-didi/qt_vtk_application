#include "hardware_infomation.h"

#include<QPainter>
#include<QVector>

void hardware_infomation::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    int W=this->width();
    int H=this->height();
    QPen pen;
    pen.setWidth(20);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashDotDotLine);
    pen.setJoinStyle(Qt::RoundJoin);
    QRect rect(W/4,H/4,W/4,H/4);
    painter.drawRect(rect);

}

int hardware_infomation::powerLeve() const
{
    return mPowerLeve;
}

void hardware_infomation::setPowerLeve(int newPowerLeve)
{
    mPowerLeve = newPowerLeve;
}

hardware_infomation::hardware_infomation(QWidget *parent):QWidget(parent)
{

}
