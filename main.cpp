#include <iostream>
#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>

using namespace std;

rectPos center[400][400];
MyItem Hive[400][400];

void set_Rect_Center();
QPointF transformCoords(rectPos point);
<<<<<<< HEAD


=======
void change_cell(int i,int j);

rectPos center[10][10];
int MaxValue = 5;
MyItem Hive[10][10];
>>>>>>> f44f3e9ef731c85f715360f353174cadeab68848

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;

   scene.setSceneRect(-200,-150,400,300);
   set_Rect_Center();

<<<<<<< HEAD
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   for(int i=0; i<400;i++){
       for(int j=0; j<400;j++){
           QPointF hex_Pos = transformCoords(center[i][j]);
           Hive[i][j].setPos(hex_Pos);
           int Num = qrand()%5;
           Hive[i][j].Num = Num;
           Hive[i][j].brushColor = QColor(255-(Num*51),255-(Num*51),255-(Num*51));
=======
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
>>>>>>> f44f3e9ef731c85f715360f353174cadeab68848
           scene.addItem(&Hive[i][j]);
       }
   }





   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}

