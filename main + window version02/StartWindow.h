#pragma once

// include file
#include "variable.h"
#include "command.h"

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
#include <QSizePolicy>
#include <QDoubleSpinBox>

// for c++ standard
#include <string>

class StartWindow : public QWidget {

    Q_OBJECT

public:
    // Constructor
    StartWindow(QWidget* parent = nullptr);

    // Press Event for button
    void mousePressEvent_LoadBoard();

    // Hide & Show QWidget because of comboBox Item(0~2) have different input
    void show_hcombo_Index0(bool state);
    void show_hcombo_Index1(bool state);
    void show_hcombo_Index2(bool state);

private slots:
    void onComboBoxIndexChanged(int index);
    void mousePressEvent_PrintGameBoard();
    void mousePressEvent_PrintGameAnswer();
    void mousePressEvent_PrintGameState();
    void mousePressEvent_PrintGameStart();
/*
signals:
    void signal_Windows_Game_Start();
*/

private: // For QComboBox hide & show
    /* Index0 Item*/
    QLabel* combo_txt0;
    QLineEdit* lineEdit0;
    QPushButton* btn_comboLoad;

    /* Index1 Item*/
    QLabel* spinBox1_txt1;
    QSpinBox* spinBox1_row;
    QLabel* spinBox1_txt2;
    QSpinBox* spinBox1_col;
    QLabel* spinBox1_txt3;
    QSpinBox* spinBox1_bombtotal;
    QPushButton* spinBox1_btnLoad;

    /* Index2 Item*/
    QLabel* spinBox2_txt1;
    QSpinBox* spinBox2_row;
    QLabel* spinBox2_txt2;
    QSpinBox* spinBox2_col;
    QLabel* spinBox2_txt3;
    QDoubleSpinBox* spinBox2_bombRate;
    QPushButton* spinBox2_btnLoad;
    
private:
    // For Loading mode, by default is 0
    int comboBox_index = -1;
    QString fileLocate; // Note: convert into string use obj.toStdString()

    // Index1 and Index2 : loadramdomCount & loadramdomRate
    int rows = -1, cols = -1, index1_bombTotal = -1;
    double index2_bombRate = -1;
};
