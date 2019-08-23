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
    int getNum();
    void setNum(int num);
    void set_i_and_j(int x, int y);
    void setColor();
    void setColor(QColor color);
    rectPos get_i_and_j();
    MyItem* get_surroundings(int s_n);
    void changeColor();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};



rectPos set_Rect_Pos(double x, double y);
QPointF transformCoords(rectPos point);
void set_Rect_Center();
MyItem* get_Item_From_i_and_j(int x,int y);

#endif // MYITEM_H
