#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>

struct rectPos{
    double rect_x;
    double rect_y;
};



class MyItem : public QGraphicsItem
{

private:
    QColor brushColor;
    int Num = 0;
    int i;
    int j;

public:
    MyItem();
    MyItem(QColor color,int num,int x,int y);
    MyItem(const MyItem &item);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void set_Rect_Center();
    void setNum(int num);
    void set_i_and_j(int x, int y);
    void setColor();
    rectPos get_i_and_j();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYITEM_H
