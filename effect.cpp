#include "effect.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>

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

    // Changing pen either seems to not work or completely crash the app. Figure this out!
    painter->drawRect(inputSlot);
    painter->drawRect(outputSlot);

    if (activeLine != nullptr){
        painter->drawLine(*activeLine);
    }
}

void Effect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (inputSlot.contains(event->pos())){
        qDebug() << "Start line draw";
        activeLine = new QLineF(inputSlot.center(),event->pos());
        drawing = true;
    } else {
        event->ignore();
    }
}

void Effect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (drawing){
        activeLine->setP2(event->pos());
        qDebug() << "Drawing Line to point: " << activeLine->p2();
        update();
    }
}

void Effect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    drawing = false;
    activeLine = nullptr; //CHANGEME no garbage disposal.
}

