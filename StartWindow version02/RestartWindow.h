#pragma once

// include file
#include "variable.h"

// for QT
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <QtCore/QDebug>
#include <QString>
#include <QLabel>
#include <QProcess>

// for c++ standard
#include <string>

class RestartWindow : public QWidget {

    Q_OBJECT

public:
    // Constructor
    RestartWindow(QWidget* parent = nullptr);
    
    // Press Event.
    void mousePressEvent_Replay();

signals:
     void signal_Windows_Game_restart();
};
