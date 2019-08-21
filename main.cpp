#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>
#include <QTimer>


int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;
   scene.setSceneRect(-200,-150,400,300);
   MyItem *item = new MyItem;
   item -> setPos(0, 0);
   scene.addItem(item);
   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}
