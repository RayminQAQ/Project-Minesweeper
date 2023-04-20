
#include "MainWindowGUI.h"
#include "variable.h"
#include <QApplication>

bool is_win = false;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    MainWindowGUI w;

    w.show(); 
    return a.exec();
}
