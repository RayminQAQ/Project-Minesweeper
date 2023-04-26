#pragma once
// for file
#include "RestartWindow.h"
#include "StartWindow.h"
// GameWindow

// for QT
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <QtCore/QDebug>
#include <QString>
#include <QLabel>

// for c++ standard
#include <string>

class MainWindowGUI : public QWidget {

	Q_OBJECT

public:
	MainWindowGUI(QWidget* parent = nullptr);

public slots:
	void open_StartWindow();
	void open_GameWindow();
	// openRestart

private:
	RestartWindow* window_restart = nullptr;
	StartWindow* window_start = nullptr;
	// GameWindow* 
};
