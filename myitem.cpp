#include <iostream>
#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QTime>
#include <math.h>

using namespace std;
//----------------------------------global variable------------------------------------//

extern rectPos center[100][100];
extern MyItem Hive[100][100];
extern int row;
extern int col;
extern int MaxValue;
extern double sideLength;


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
    for (int i=0;i<col;i++){
        for (int j=0;j<row;j++){
            if(j%2==0){
                center[i][j]=set_Rect_Pos(3*i+2+j/2-row/2,j-col/2);
            }
            else {
               center[i][j]=set_Rect_Pos(3*i+(j+1)/2-row/2,j-col/2);
            }
        }
    }
}


//-----------------------------------------------------------------------------------------------------//
MyItem::MyItem()
{
    //generate random number
    Num = 0;
    i = 0;
    j = 0;
    brushColor = Qt::white;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

MyItem::MyItem(QColor color,int num,int x,int y){
    brushColor = color;
    Num = num;
    i = x;
    j = y;
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
    changeColor();
    this->setColor();
    setRotation(360);
    return;
}

void MyItem::setColor(){
    this->brushColor = QColor(255-(Num*255/MaxValue),255-(Num*255/MaxValue),255-(Num*255/MaxValue));
}

void MyItem::set_i_and_j(int x, int y){
    this->i = x;
    this->j = y;
}

int MyItem::getNum(){
    return this->Num;
}

void MyItem::setNum(int num){
    this->Num = num;
}

rectPos MyItem::get_i_and_j(){
    rectPos Pos;
    Pos.rect_x = this->i;
    Pos.rect_y = this->j;
    return Pos;
}

MyItem* MyItem::get_surroundings(int s_n){
    int i = this->get_i_and_j().rect_x;
    int j = this->get_i_and_j().rect_y;
    MyItem *s1,*s2,*s3,*s4,*s5,*s6;
    s1 = get_Item_From_i_and_j(i,j+2);
    s4 = get_Item_From_i_and_j(i,j-2);

    if(j%2!=0){
        s2 = get_Item_From_i_and_j(i,j+1);
        s3 = get_Item_From_i_and_j(i,j-1);
        s5 = get_Item_From_i_and_j(i-1,j-1);
        s6 = get_Item_From_i_and_j(i-1,j+1);
    }
    else{
        s2 = get_Item_From_i_and_j(i+1,j+1);
        s3 = get_Item_From_i_and_j(i+1,j-1);
        s5 = get_Item_From_i_and_j(i,j-1);
        s6 = get_Item_From_i_and_j(i,j+1);
    }

    switch(s_n) {
    case 1:
        return s1;
    case 2:
        return s2;
    case 3:
        return s3;
    case 4:
        return s4;
    case 5:
        return s5;
    case 6:
        return s6;
    default:
        return nullptr;
    }

}

MyItem* get_Item_From_i_and_j(int x,int y){
    for(int i=0;i<col;i++){
        for(int j=0; j<row;j++){
            rectPos Pos = Hive[i][j].get_i_and_j();
            if(Pos.rect_x == x && Pos.rect_y == y){
                return &Hive[i][j];
            }
        }
    }
    return nullptr;
}

void MyItem::changeColor(){
    int num = this->getNum();
    if(num<MaxValue){
        this->setNum(num+1);
        this->setColor();
    }
    else{
        this->setNum(0);
        this->setColor();
        for(int i=1;i<=6;i++){
            MyItem* item = this->get_surroundings(i);
            if(item==nullptr)
                return;
            item->changeColor();
            item->setRotation(360);
        }
    }
}
