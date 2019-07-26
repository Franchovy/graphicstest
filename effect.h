#ifndef EFFECT_H
#define EFFECT_H

#include <QGraphicsItem>



class Effect : public QGraphicsItem
{
public:
    Effect();

    QRectF effectBox;

    //Temporary input and output system for all "Effects".
    QRectF inputSlot;
    QRectF outputSlot;

    /*
     * To write your own graphics item, you first create a subclass of QGraphicsItem,
     * and then start by implementing its two pure virtual public functions: boundingRect(),
     * which returns an estimate of the area painted by the item, and paint(),
     * which implements the actual painting.
    */

    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem* option,
               QWidget *widget);


};

#endif // EFFECT_H
