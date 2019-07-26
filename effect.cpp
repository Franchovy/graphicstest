#include "effect.h"

#include <QPainter>
#include <QPen>

Effect::Effect()
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);

    effectBox = QRectF(0,0,100,100);
    inputSlot = QRectF(10,50,10,10);
    outputSlot = QRectF(80,50,10,10);
}

QRectF Effect::boundingRect() const
{
    return effectBox;
}


void Effect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->drawRect(rect);

    //painter->setPen(inPen);
    painter->drawRect(inputSlot);
    //QPen outPen(Qt::blue, 3);
    //painter->setPen(outPen);
    painter->drawRect(outputSlot);

}
