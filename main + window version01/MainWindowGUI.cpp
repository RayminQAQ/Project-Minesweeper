#include "MainWindowGUI.h"
#include "RestartWindow.h"

#include <iostream>
MainWindowGUI::MainWindowGUI(QWidget* parent) 
	: QWidget(parent)
{
	QVBoxLayout* vLayout = new QVBoxLayout(this);

	RestartWindow* re = new RestartWindow;
	connect(re, &RestartWindow::signal_Windows_Game_restart, this, &MainWindowGUI::open_StartWindow);

	vLayout->addWidget(re);
}

// TO DO: StartWindow
void MainWindowGUI::open_StartWindow() {
	qDebug() << "Open open_StartWindow" << endl;
}

void MainWindowGUI::open_GameWindow() {
	qDebug() << "Open open_GameWindow" << endl;
}




