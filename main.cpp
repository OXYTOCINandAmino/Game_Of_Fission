#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>
#include <QTimer>

MyItem Hive[10][10];

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   for(int i=0; i<10; i++){
       MyItem *item = new MyItem;
       item->Num = qrand() % 5;
       item->brushColor = QColor(item->Num*51,item->Num*51,item->Num*51);
       item->setPos(i*40, 0);
       scene.addItem(item);
   }

   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}
