#include "linqedinwidget.h"
#include <QApplication>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    LinqedinWidget w;
    w.show();
    return a.exec();

}//main
