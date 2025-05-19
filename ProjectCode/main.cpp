#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the main window
    
    MainWindow w;

     //Shows the parent being the main window, which automatically shows the children
    w.show();

    
    return a.exec();
}



