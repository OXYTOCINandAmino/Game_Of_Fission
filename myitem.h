#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>

struct rectPos{
    double rect_x;
    double rect_y;
};



class MyItem : public QGraphicsItem
{

public:
    QColor brushColor;
    int    Num = 0;
    MyItem();

    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void set_Rect_Center();
    void setColor();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYITEM_H
