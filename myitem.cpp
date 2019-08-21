#include "myitem.h"
#include <QPainter>
#include <QCursor>

MyItem::MyItem()
{
    //generate random number
    Num = 0;
    brushColor = Qt::black;
    setFlag(QGraphicsItem::ItemIsFocusable);
}


QRectF MyItem::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-20-adjust,-17.3-adjust,40+adjust,40+adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter -> setBrush(brushColor);
    static const QPointF points[6] =
    { QPointF(-20.0, 0.0),
      QPointF(-10.0,17.3),
      QPointF(10.0, 17.3),
      QPointF(20.0, 0.0),
      QPointF(10.0, -17.3),
      QPointF(-10.0,-17.3),
    };
    painter->drawPolygon(points, 6);

    }

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setFocus();
    setCursor(Qt::ClosedHandCursor);

}

