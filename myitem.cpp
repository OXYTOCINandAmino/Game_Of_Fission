#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QMenu>

MyItem::MyItem()
{
    brushColor = Qt::white;
    Num = 0;
    setFlag(QGraphicsItem::ItemIsFocusable);
}


QRectF MyItem::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(0-adjust,0-adjust,20+adjust,20+adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter -> setBrush(brushColor);
    static const QPointF points[6] =
    { QPointF(-20.0, 0.0),
      QPointF(-10.0, 17.3),
      QPointF(10.0, 17.3),
      QPointF(20.0, 0.0)    };

    }

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setFocus();
    setCursor(Qt::ClosedHandCursor);

}

