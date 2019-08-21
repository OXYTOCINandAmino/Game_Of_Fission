#include <iostream>>
#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QTime>
#include <math.h>

using namespace std;


extern rectPos center[400][400];
rectPos set_Rect_Pos(double x, double y);
QPointF transformCoords(rectPos point);
void set_Rect_Center();
static rectPos hex1 = set_Rect_Pos(0,0);
static rectPos hex2 = set_Rect_Pos(0,1);
static rectPos hex3 = set_Rect_Pos(1,2);
static rectPos hex4 = set_Rect_Pos(2,2);
static rectPos hex5 = set_Rect_Pos(2,1);
static rectPos hex6 = set_Rect_Pos(1,0);


QPointF transformCoords(rectPos point){
    return QPointF(10*(point.rect_x - 0.5*point.rect_y),10*(sqrt(3)/2*point.rect_y));
}

void set_Rect_Center(){
    for (int i=0;i<400;i++){
        for (int j=0;j<400;j++){
            if(j%2==0){
                center[i][j]=set_Rect_Pos(3*i+j/2-200,j-200);
            }
            else {
               center[i][j]=set_Rect_Pos(3*i+2+j/2-200,j-200);
            }
        }
    }
}

MyItem::MyItem()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    Num = qrand() % 5;
    brushColor = QColor(51*Num,51*Num,51*Num);
    setFlag(QGraphicsItem::ItemIsFocusable);
}


QRectF MyItem::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-20-adjust,-17.3-adjust,40+adjust,40+adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter -> setBrush(brushColor);

    static const QPointF points[6] =
    {
        transformCoords(hex1),
        transformCoords(hex2),
        transformCoords(hex3),
        transformCoords(hex4),
        transformCoords(hex5),
        transformCoords(hex6),
    };
    painter->drawPolygon(points, 6);

    }

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setFocus();
    setCursor(Qt::ClosedHandCursor);

}


rectPos set_Rect_Pos(double x, double y){
    rectPos point;
    point.rect_x=x;
    point.rect_y=y;
    return point;
}
