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
int col = 40;
int row = 80;
double sideLength = 30;

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;

   set_Rect_Center();

   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

   for(int i=0; i<col;i++){
       for(int j=0; j<row;j++){
           QPointF hex_Pos = transformCoords(center[i][j]);
           Hive[i][j].setPos(hex_Pos);
           Hive[i][j].set_i_and_j(i,j);
           int Num = qrand()%(MaxValue+1);
           Hive[i][j].setNum(Num);
           Hive[i][j].setColor(QColor(255-(Num*255/MaxValue),255-(Num*255/MaxValue),255-(Num*255/MaxValue)));
           scene.addItem(&Hive[i][j]);
       }
   }

   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}


