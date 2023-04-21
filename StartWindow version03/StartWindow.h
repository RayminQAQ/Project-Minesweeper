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
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSpinBox>

// for c++ standard
#include <string>

class StartWindow : public QWidget {

    Q_OBJECT

public:
    // Constructor
    StartWindow(QWidget* parent = nullptr);

    // Press Event for button
    void mousePressEvent_LoadBoard();

    // Hide&Show QWidget because of comboBox Item(0~2) have different input
    void show_hcombo_Index0();
    void show_hcombo_Index1();
    void show_hcombo_Index2();
    void hide_hcombo_Index0();
    void hide_hcombo_Index1();
    void hide_hcombo_Index2();


private slots:
    void onComboBoxIndexChanged(int index);
    void mousePressEvent_PrintGameBoard();
    void mousePressEvent_PrintGameAnswer();
    void mousePressEvent_PrintGameState();
    void mousePressEvent_PrintGameStart();
/*
signals:
    void signal_Windows_Game_Start();*/

private:
    // For Loading mode
    int index = -1;
    std::string fileLocate;

    // Index1 and Index2 : loadramdomCount & loadramdomRate
    int rows = -1, cols = -1, index1_bombTotal = -1, index2_bombRate = -1;;
};
