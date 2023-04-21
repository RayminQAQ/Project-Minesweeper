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
#include <QComboBox>
#include <QMouseEvent>

// for c++ standard
#include <string>

class StartWindow : public QWidget {

    Q_OBJECT

public:
    // Constructor
    StartWindow(QWidget* parent = nullptr);

    // Press Event for button
    void mousePressEvent_LoadBoard();

private slots:
    void onComboBoxIndexChanged(int index);
    void mousePressEvent_PrintGameBoard();
    void mousePressEvent_PrintGameAnswer();
    void mousePressEvent_PrintGameState();
    void mousePressEvent_PrintGameStart();
/*
signals:
    void signal_Windows_Game_Start();*/
};
