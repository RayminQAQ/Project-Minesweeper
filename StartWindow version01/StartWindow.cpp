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

    // For TextLayout
    QString text = QString::fromStdString("GameState: Standby");
    QLabel* label_txt = new QLabel(text);
    label_txt->setStyleSheet("QLabel{background-color:yellow; color:black; border:1px solid #4000FF99; max-height: 1em; max-width:248px; padding: gray}");
    label_txt->setAlignment(Qt::AlignCenter);
    hTextLayout->addWidget(label_txt);

    // add layout
    vLayout->addLayout(hTextLayout);

    // For LoadLayout & different require setting Info -> TO BE DONE
    QString text2 = QString::fromUtf8("載入類型：");
    QLabel* label_txt2 = new QLabel(text2);
    label_txt2->setStyleSheet("QLabel{max-height: 1em; max-width:9em; padding: gray}");
    label_txt2->setAlignment(Qt::AlignLeft);
    hLoadLayout->addWidget(label_txt2);

    QComboBox* comboBox = new QComboBox;
    comboBox->addItem("盤面檔"); // loadboardfile
    comboBox->addItem("指定炸彈數量盤面"); // loadramdomCount
    comboBox->addItem("指定炸彈生成率盤面"); // loadramdomRate
    hLoadLayout->addWidget(comboBox);

    // add layout
    vLayout->addLayout(hLoadLayout); 

    // For Print button
    QPushButton* btn_GameBoard = new QPushButton("Print GameBoard");
    btn_GameBoard->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
    hPrintLayout->addWidget(btn_GameBoard);

    QPushButton* btn_GameAnswer = new QPushButton("Print GameAnswer");
    btn_GameAnswer->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
    hPrintLayout->addWidget(btn_GameAnswer);

    QPushButton* btn_GameState = new QPushButton("Print GameState");
    btn_GameState->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
    hPrintLayout->addWidget(btn_GameState);

    // add layout
    vLayout->addLayout(hPrintLayout); // add layout

    // For Start Game
    QPushButton* btn_GameStart = new QPushButton("Print GameState");
    btn_GameStart->setStyleSheet("QPushButton:hover{background-color: #1e90ff;color: yellow;}");
    hStartGameLayout->addWidget(btn_GameStart);

    // add layout
    vLayout->addLayout(hStartGameLayout);
}






/*
class StartWindow : public QWidget {

public:
    // Constructor
    StartWindow(QWidget* parent = nullptr);
    // Press Event for button
    void mousePressEvent_LoadBoard();
    void mousePressEvent_PrintGameBoard();
    void mousePressEvent_PrintGameAnswer();
    void mousePressEvent_PrintGameState();
    
    
    // Slection Event for QCombobox
    void onComboxSelect();
private:
    int index = 0; // by default
};
*/
