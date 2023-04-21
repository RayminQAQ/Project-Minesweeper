#pragma once
#pragma execution_character_set("utf-8")

#include "StartWindow.h"

StartWindow::StartWindow(QWidget* parent)
    : QWidget(parent), index(0)
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
    // hcombo_Index0 : by default is show
    QHBoxLayout* hcombo_Index0 = new QHBoxLayout;

        // QString
        QLabel* combo_txt0 = new QLabel(QString::fromUtf8("盤面檔位置："));
        hcombo_Index0->addWidget(combo_txt0);

        // LineEdit
        QLineEdit* lineEdit0 = new QLineEdit;
        hcombo_Index0->addWidget(lineEdit0);

        // Button
        QPushButton* btn_comboLoad = new QPushButton("Load");
        hcombo_Index0->addWidget(btn_comboLoad);

    vLayout->addLayout(hcombo_Index0);

    /********* TO BE DONE: For comboBox->addItem("指定炸彈數量盤面"); // Index1 : loadramdomCount *********/
    // by default is hide
    QHBoxLayout* hcombo_Index1 = new QHBoxLayout;

        // QString (spinBox1_txt1) + spinBox1_row
        QLabel* spinBox1_txt1 = new QLabel(QString::fromUtf8("Rows: "));
        hcombo_Index1->addWidget(spinBox1_txt1);

        QSpinBox* spinBox1_row = new QSpinBox();
        spinBox1_row->setMinimum(2);
        hcombo_Index1->addWidget(spinBox1_row);

        // QString (spinBox1_txt2) + spinBox1_col
        QLabel* spinBox1_txt2 = new QLabel(QString::fromUtf8("Cols: "));
        hcombo_Index1->addWidget(spinBox1_txt2);

        QSpinBox* spinBox1_col = new QSpinBox();
        spinBox1_col->setMinimum(2);
        hcombo_Index1->addWidget(spinBox1_col);

        // QString (spinBox1_txt3) + number of bomb (spinBox1_bombtotal)
        QLabel* spinBox1_txt3 = new QLabel(QString::fromUtf8("炸彈數量 "));
        hcombo_Index1->addWidget(spinBox1_txt3);

        QSpinBox* spinBox1_bombtotal = new QSpinBox();
        hcombo_Index1->addWidget(spinBox1_bombtotal);

        // Load button (spinBox1_btnLoad)
        QPushButton* spinBox1_btnLoad = new QPushButton(QString::fromUtf8("Load"));
        hcombo_Index1->addWidget(spinBox1_btnLoad);

    vLayout->addLayout(hcombo_Index1);

    /********* TO BE DONE: For comboBox->addItem("指定炸彈生成率盤面"); // Index2 : loadramdomRate *********/
        // by default is hide
    QHBoxLayout* hcombo_Index2 = new QHBoxLayout;

        // QString (spinBox2_txt1) + spinBox_row (spinBox2_row)
        QLabel* spinBox2_txt1 = new QLabel(QString::fromUtf8("Rows: "));
        hcombo_Index2->addWidget(spinBox2_txt1);

        QSpinBox* spinBox2_row = new QSpinBox();
        spinBox2_row->setMinimum(2);
        hcombo_Index2->addWidget(spinBox2_row);

        // QString (spinBox2_txt2) + spinbox_col (spinBox2_col)
        QLabel* spinBox2_txt2 = new QLabel(QString::fromUtf8("Cols: "));
        hcombo_Index2->addWidget(spinBox2_txt2);

        QSpinBox* spinBox2_col = new QSpinBox();
        spinBox2_col->setMinimum(2);
        hcombo_Index2->addWidget(spinBox2_col);

        // QString (spinBox2_txt3) + number of bomb (spinBox2_bombtotal)
        QLabel* spinBox2_txt3 = new QLabel(QString::fromUtf8("炸彈生成機率 "));
        hcombo_Index2->addWidget(spinBox2_txt3);

        QSpinBox* spinBox2_bombtotal = new QSpinBox();
        hcombo_Index2->addWidget(spinBox2_bombtotal);

        // Load button (spinBox2_btnLoad)
        QPushButton* spinBox2_btnLoad = new QPushButton(QString::fromUtf8("Load"));
        hcombo_Index2->addWidget(spinBox2_btnLoad);

    vLayout->addLayout(hcombo_Index2);

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

// Layout hide & show
    // btn_comboLoad->setVisible(false); // For hiding
     // btn_comboLoad->setVisible(show); // For hiding
void StartWindow::show_hcombo_Index0() {}
void StartWindow::show_hcombo_Index1() {}
void StartWindow::show_hcombo_Index2() {}
void StartWindow::hide_hcombo_Index0() {}
void StartWindow::hide_hcombo_Index1() {}
void StartWindow::hide_hcombo_Index2() {}

// signal to MainWindow -> TO BE DONE WITH MainWindow
// void StartWindow::signal_Windows_Game_Start(){}