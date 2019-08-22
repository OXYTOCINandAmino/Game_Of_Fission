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
int row = 8;
int col = 4;
double sideLength = 30;

void set_Rect_Center();
QPointF transformCoords(rectPos point);
rectPos get_i_and_j();
MyItem get_Item_From_i_and_j(int x,int y);

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
//           int Num = qrand()%5;
//           Hive[i][j].Num = Num;
//           Hive[i][j].brushColor = QColor(255-(Num*51),255-(Num*51),255-(Num*51));
           Hive[i][j].setColor();
           scene.addItem(&Hive[i][j]);
       }
   }



//   MyItem *hive = new MyItem;
//   hive = get_Item_From_i_and_j(2,3);
//   hive.setNum(2);

   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}

MyItem get_Item_From_i_and_j(int x,int y){
//    for(int i=0;i<col;i++){
//        for(int j=0; j<row;j++){
//            rectPos Pos = Hive[i][j].get_i_and_j();
//            if(Pos.rect_x == x && Pos.rect_y == y){
//                return Hive[i][j];
//            }
//        }
//    }
    return Hive[1][1];
}
