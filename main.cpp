#include <iostream>
#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>

using namespace std;

void set_Rect_Center();
QPointF transformCoords(rectPos point);
void change_cell(int i,int j);

rectPos center[10][10];
int MaxValue = 5;
MyItem Hive[10][10];

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;

   scene.setSceneRect(-200,-150,400,300);
   set_Rect_Center();

   for(int i=0; i<10;i++){
       for(int j=0; j<10;j++){
//           Hive[i][j].Num=0;
           int color = 51*(MaxValue-Hive[i][j].Num);
           Hive[i][j].brushColor = QColor(color,color,color);
           QPointF hex_Pos = transformCoords(center[i][j]);
           Hive[i][j].setPos(hex_Pos);
           scene.addItem(&Hive[i][j]);
       }
   }
      change_cell(3,3);
      change_cell(3,3);
      change_cell(3,3);
      change_cell(3,3);
      change_cell(3,3);
      change_cell(3,3);
   for(int i=0; i<10;i++){
       for(int j=0; j<10;j++){
//           Hive[i][j].Num=0;
           int color = 51*(MaxValue-Hive[i][j].Num);
           Hive[i][j].brushColor = QColor(color,color,color);
           QPointF hex_Pos = transformCoords(center[i][j]);
           Hive[i][j].setPos(hex_Pos);
           scene.addItem(&Hive[i][j]);
       }
   }

   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

//   for(int i=0; i<10; i++){
//       for(int j=0; j<20; j++){
//           Hive[i][j].Num = 0;
////           int color = 51*Hive[10][10].Num;
////           Hive[i][j].brushColor = QColor(color,color,color);
//           if(j%2 == 0){Hive[i][j].setPos(i*60, j*17.3);}
//           else{Hive[i][j].setPos(i*60+30, j*17.3);}
//           scene.addItem(&Hive[i][j]);
//       }
//   }

   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}

