
#include "MainWindowGUI.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    MainWindowGUI w;

    w.show(); 
    return a.exec();
}
