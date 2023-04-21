// For window
#include "MainWindowGUI.h"
#include "StartWindow.h"

// For extern variable
#include "variable.h"

// For this file
#include <QApplication>

bool is_win = false;

int main(int argc, char* argv[])
{
    /*
    QApplication a(argc, argv);
    
    MainWindowGUI w;

    w.show(); 
    return a.exec();
    */

    // TEST AREA
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}
