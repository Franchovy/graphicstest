#ifndef WIRE_H
#define WIRE_H

#include <QGraphicsItem>



class Wire : public QGraphicsItem
{
public:
    Wire() = default;

    //TODO Static elements of Wire class, like the effect chain.

    // Wires (and their UI) otherwise are NON-STATIC !

    QLineF wire;
    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem* option,
               QWidget *widget);


    /*  These could potentially take in/outputSlots instead of points as
     *  inputs/outputs. It would make checking validity easier and simpler.
     */
    void startDragging();
    void dragging();
    void stopDragging();

};

#endif // WIRE_H
