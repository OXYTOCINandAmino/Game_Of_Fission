#include <iostream>
#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QTime>
#include <math.h>

using namespace std;
//----------------------------------global variable------------------------------------//

extern rectPos center[100][100];
extern int row;
extern int col;
extern int MaxValue;
extern double sideLength;
rectPos set_Rect_Pos(double x, double y);
QPointF transformCoords(rectPos point);
void set_Rect_Center();

static rectPos hex1 = set_Rect_Pos(0,0);
static rectPos hex2 = set_Rect_Pos(0,1);
static rectPos hex3 = set_Rect_Pos(1,2);
static rectPos hex4 = set_Rect_Pos(2,2);
static rectPos hex5 = set_Rect_Pos(2,1);
static rectPos hex6 = set_Rect_Pos(1,0);

rectPos set_Rect_Pos(double x, double y){
    rectPos point;
    point.rect_x=x;
    point.rect_y=y;
    return point;
}

QPointF transformCoords(rectPos point){
    return QPointF(sideLength*(point.rect_x - 0.5*point.rect_y),sideLength*(sqrt(3)/2*point.rect_y));
}

void set_Rect_Center(){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if(j%2==0){
                center[i][j]=set_Rect_Pos(3*i+j/2-row/2,j-col/2);
            }
            else {
               center[i][j]=set_Rect_Pos(3*i+2+j/2-row/2,j-col/2);
            }
        }
    }
}


//-----------------------------------------------------------------------------------------------------//
MyItem::MyItem()
{
    //generate random number
    Num = 0;
    brushColor = Qt::white;
    setFlag(QGraphicsItem::ItemIsFocusable);
}


QRectF MyItem::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-sideLength/2-adjust,0-adjust,sideLength*2+adjust,sqrt(3)*sideLength+adjust);
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

    if(Num < MaxValue){
        Num++;
//        brushColor = QColor(255-(Num*51),255-(Num*51),255-(Num*51));
    }
    else{
        Num = 0;
//        brushColor = Qt::white;
    }
    setColor();
    setRotation(360);
    return;
}

void MyItem::setColor(){
    brushColor = QColor(255-(Num*51),255-(Num*51),255-(Num*51));
}


