#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QPen>
#include <QPainter>


class MyItem : public QGraphicsItem
{
public:
    MyItem();

    /*
     * To write your own graphics item, you first create a subclass of QGraphicsItem,
     * and then start by implementing its two pure virtual public functions: boundingRect(),
     * which returns an estimate of the area painted by the item, and paint(),
     * which implements the actual painting.
    */

    QRectF boundingRect() const;

    // overriding paint
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem* option,
               QWidget * widget);

    bool Pressed; // Item state

protected:
    //overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MYITEM_H
