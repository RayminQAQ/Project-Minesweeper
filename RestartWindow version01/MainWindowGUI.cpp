#include "MainWindowGUI.h"

MainWindowGUI::MainWindowGUI(QWidget* parent) 
	: QWidget(parent)
{
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	
	RestartWindow* re = new RestartWindow;

	vLayout->addWidget(re);
}
