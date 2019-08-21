#include <iostream>
#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>

using namespace std;
//----------------global variable------------------------//
rectPos center[100][100];
MyItem Hive[100][100];
int MaxValue = 5;
int row = 40;
int col = 80;
double sideLength = 30;

void set_Rect_Center();
QPointF transformCoords(rectPos point);


int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;

   set_Rect_Center();

   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   for(int i=0; i<row;i++){
       for(int j=0; j<col;j++){
           QPointF hex_Pos = transformCoords(center[i][j]);
           Hive[i][j].setPos(hex_Pos);
           int Num = qrand()%5;
           Hive[i][j].Num = Num;
//           Hive[i][j].brushColor = QColor(255-(Num*51),255-(Num*51),255-(Num*51));
           Hive[i][j].setColor();
           scene.addItem(&Hive[i][j]);
       }
   }

   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}

