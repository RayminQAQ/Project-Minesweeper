#pragma once
#pragma execution_character_set("utf-8")

#include "StartWindow.h"

StartWindow::StartWindow(QWidget* parent)
    : QWidget(parent)
{
    // The window
    QVBoxLayout* vLayout = new QVBoxLayout(this);

    QHBoxLayout* hTextLayout = new QHBoxLayout;
    QHBoxLayout* hLoadLayout = new QHBoxLayout;
    QHBoxLayout* hPrintLayout = new QHBoxLayout;
    QHBoxLayout* hStartGameLayout = new QHBoxLayout;

    /********* For TextLayout *********/
    QString text = QString::fromStdString("GameState: Standby");
    QLabel* label_txt = new QLabel(text);
        label_txt->setStyleSheet("QLabel{background-color:yellow; color:black; border:1px solid #4000FF99; max-height: 1em; max-width:248px; padding: gray}");
        label_txt->setAlignment(Qt::AlignCenter);
        hTextLayout->addWidget(label_txt);

    // add layout
    vLayout->addLayout(hTextLayout);

    /********* For LoadLayout & different require setting Info -> TO BE DONE *********/
    QString text2 = QString::fromUtf8("載入類型：");
    QLabel* label_txt2 = new QLabel(text2);
        label_txt2->setStyleSheet("QLabel{max-height: 1em; max-width:9em; padding: gray}");
        label_txt2->setAlignment(Qt::AlignLeft);
        hLoadLayout->addWidget(label_txt2);

    QComboBox* comboBox = new QComboBox;
    comboBox->addItem("盤面檔"); // Index0 : loadboardfile
    comboBox->addItem("指定炸彈數量盤面"); // Index1 : loadramdomCount
    comboBox->addItem("指定炸彈生成率盤面"); // Index2 : loadramdomRate
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));
    // add layout
    hLoadLayout->addWidget(comboBox);
    vLayout->addLayout(hLoadLayout); 

    /********* TO BE DONE: For comboBox->addItem("盤面檔"); // Index0 : loadboardfile *********/
        // by default is show
    QHBoxLayout* hcombo_Index1 = new QHBoxLayout;

    /********* TO BE DONE: For comboBox->addItem("指定炸彈數量盤面"); // Index1 : loadramdomCount *********/
        // by default is hide
    QHBoxLayout* hcombo_Index2 = new QHBoxLayout;

    /********* TO BE DONE: For comboBox->addItem("指定炸彈生成率盤面"); // Index2 : loadramdomRate *********/
        // by default is hide
    QHBoxLayout* hcombo_Index3 = new QHBoxLayout;






    /*********  For Print button *********/
    QPushButton* btn_GameBoard = new QPushButton("Print GameBoard");
        connect(btn_GameBoard, SIGNAL(clicked()), this, SLOT(mousePressEvent_PrintGameBoard())); // connect
        btn_GameBoard->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
        hPrintLayout->addWidget(btn_GameBoard);

    QPushButton* btn_GameAnswer = new QPushButton("Print GameAnswer");
        connect(btn_GameAnswer, SIGNAL(clicked()), this, SLOT(mousePressEvent_PrintGameAnswer())); // connect
        btn_GameAnswer->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
        hPrintLayout->addWidget(btn_GameAnswer);

    QPushButton* btn_GameState = new QPushButton("Print GameState");
        connect(btn_GameState, SIGNAL(clicked()), this, SLOT(mousePressEvent_PrintGameState())); // connect
        btn_GameState->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
        hPrintLayout->addWidget(btn_GameState);

    // add layout
    vLayout->addLayout(hPrintLayout); // add layout

    /********* For Start Game *********/
    QPushButton* btn_GameStart = new QPushButton("GameStart");
        connect(btn_GameStart, SIGNAL(clicked()), this, SLOT(mousePressEvent_PrintGameStart())); // connect
        btn_GameStart->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
        hStartGameLayout->addWidget(btn_GameStart);

    // add layout
    vLayout->addLayout(hStartGameLayout);
}

// comboBox connect
void StartWindow::onComboBoxIndexChanged(int index) {
    qDebug() << "DEBUG: GO TO onComboBoxIndexChanged" << endl;
    switch (index) {
    case 0: // Index0 : loadboardfile
        qDebug() << "DEBUG: onComboBoxIndexChanged 0 " << endl;
        break;
    case 1: // Index1 : loadramdomCount
        qDebug() << "DEBUG: onComboBoxIndexChanged 1 " << endl;
        break;
    case 2: // Index2 : loadramdomRate
        qDebug() << "DEBUG: onComboBoxIndexChanged 2 " << endl;
        break;
    default:
        break;
    }
}

// button connect -> TO BE DONE WITH MainWindow
void StartWindow::mousePressEvent_PrintGameBoard() { qDebug() << "DEBUG: mousePressEvent_PrintGameBoard" << endl; }
void StartWindow::mousePressEvent_PrintGameAnswer() { qDebug() << "DEBUG: mousePressEvent_PrintGameAnswer" << endl; }
void StartWindow::mousePressEvent_PrintGameState() { qDebug() << "DEBUG: mousePressEvent_PrintGameState" << endl; }
void StartWindow::mousePressEvent_PrintGameStart() { qDebug() << "DEBUG: mousePressEvent_PrintGameStart" << endl; }

// signal to MainWindow -> TO BE DONE WITH MainWindow
// void StartWindow::signal_Windows_Game_Start(){}