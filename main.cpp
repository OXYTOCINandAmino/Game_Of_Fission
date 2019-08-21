#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>


MyItem Hive[10][20];

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   QGraphicsScene scene;
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

   for(int i=0; i<10; i++){
       for(int j=0; j<20; j++){
           Hive[i][j].Num = 0;
//           int color = 51*Hive[10][10].Num;
//           Hive[i][j].brushColor = QColor(color,color,color);
           if(j%2 == 0){Hive[i][j].setPos(i*60, j*17.3);}
           else{Hive[i][j].setPos(i*60+30, j*17.3);}
           scene.addItem(&Hive[i][j]);
       }
   }

   MyView view;
   view.setScene(&scene);
   view.show();
   return app.exec();
}
