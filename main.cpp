#include <iostream>
#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>
#include <QTimer>

using namespace std;

void set_Rect_Center();
QPointF transformCoords(rectPos point);
rectPos center[400][400];

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;
   scene.setSceneRect(-200,-150,400,300);
   set_Rect_Center();

   for(int i=0; i<400;i++){
       for(int j=0; j<400;j++){
           MyItem *item = new MyItem;
           QPointF hex_Pos = transformCoords(center[i][j]);
           item -> setPos(hex_Pos);
           scene.addItem(item);
       }
   }


   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}

