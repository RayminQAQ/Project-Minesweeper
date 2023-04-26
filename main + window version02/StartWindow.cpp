#pragma execution_character_set("utf-8")

#include "StartWindow.h"

StartWindow::StartWindow(QWidget* parent)
    : QWidget(parent), comboBox_index(0)
{
    this->setWindowTitle("MineSweeper Start Window");

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
        combo_txt0 = new QLabel(QString::fromUtf8("盤面檔位置："));

        // LineEdit
        lineEdit0 = new QLineEdit;

        // Button
        btn_comboLoad = new QPushButton("Load");
        
        // add connection when btn_comboLoad clicked
        connect(btn_comboLoad, &QPushButton::clicked, lineEdit0, [=]() {
            this->fileLocate = this->lineEdit0->text(); 
            this->comboBox_index = 0;
            qDebug() << fileLocate; // FOR DEBUG
            });

    hcombo_Index0->addWidget(combo_txt0);
    hcombo_Index0->addWidget(lineEdit0);
    hcombo_Index0->addWidget(btn_comboLoad);
    vLayout->addLayout(hcombo_Index0);

    /********* TO BE DONE: For comboBox->addItem("指定炸彈數量盤面"); // Index1 : loadramdomCount *********/
    // by default is hide
    QHBoxLayout* hcombo_Index1 = new QHBoxLayout;

        // QString (spinBox1_txt1) + spinBox1_row
        spinBox1_txt1 = new QLabel(QString::fromUtf8("Rows: "));
        spinBox1_row = new QSpinBox();
        spinBox1_row->setMinimum(2);

        // QString (spinBox1_txt2) + spinBox1_col
        spinBox1_txt2 = new QLabel(QString::fromUtf8("Cols: "));
        spinBox1_col = new QSpinBox();
        spinBox1_col->setMinimum(2);

        // QString (spinBox1_txt3) + number of bomb (spinBox1_bombtotal)
        spinBox1_txt3 = new QLabel(QString::fromUtf8("炸彈數量 "));
        spinBox1_bombtotal = new QSpinBox();

        // Load button (spinBox1_btnLoad)
        spinBox1_btnLoad = new QPushButton(QString::fromUtf8("Load"));

        // Add connection with spinBox1_btnLoad
        connect(spinBox1_btnLoad, &QPushButton::clicked,[=]() {
            this->rows = this->spinBox1_row->value();
            this->cols = this->spinBox1_col->value();
            this->index1_bombTotal = this->spinBox1_bombtotal->value();
            this->comboBox_index = 1;
            qDebug() << rows << " " << cols << " " << index1_bombTotal;  // FOR DEBUG
        });

        // By default is hidden
        show_hcombo_Index1(false);

    hcombo_Index1->addWidget(spinBox1_txt1);
    hcombo_Index1->addWidget(spinBox1_row);
    hcombo_Index1->addWidget(spinBox1_txt2);
    hcombo_Index1->addWidget(spinBox1_col);
    hcombo_Index1->addWidget(spinBox1_txt3);
    hcombo_Index1->addWidget(spinBox1_bombtotal);
    hcombo_Index1->addWidget(spinBox1_btnLoad);
    vLayout->addLayout(hcombo_Index1);

    /********* TO BE DONE: For comboBox->addItem("指定炸彈生成率盤面"); // Index2 : loadramdomRate *********/
        // by default is hide
    QHBoxLayout* hcombo_Index2 = new QHBoxLayout;

        // QString (spinBox2_txt1) + spinBox_row (spinBox2_row)
        spinBox2_txt1 = new QLabel(QString::fromUtf8("Rows: "));
        spinBox2_row = new QSpinBox();
        spinBox2_row->setMinimum(2);

        // QString (spinBox2_txt2) + spinbox_col (spinBox2_col)
        spinBox2_txt2 = new QLabel(QString::fromUtf8("Cols: "));
        spinBox2_col = new QSpinBox();
        spinBox2_col->setMinimum(2);

        // QString (spinBox2_txt3) + number of bomb (spinBox2_bombRate)
        spinBox2_txt3 = new QLabel(QString::fromUtf8("炸彈生成機率 "));
        spinBox2_bombRate = new QDoubleSpinBox();
        spinBox2_bombRate->setRange(0, 1);
        spinBox2_bombRate->setDecimals(2);
        spinBox2_bombRate->setSingleStep(0.05);

        // Load button (spinBox2_btnLoad)
        spinBox2_btnLoad = new QPushButton(QString::fromUtf8("Load"));

        // Add connection with spinBox2_btnLoad
        connect(spinBox2_btnLoad, &QPushButton::clicked, [=]() {
            this->rows = this->spinBox2_row->value();
            this->cols = this->spinBox2_col->value();
            this->index2_bombRate = this->spinBox2_bombRate->value();
            this->comboBox_index = 2;
            qDebug() << rows << " " << cols << " " << index2_bombRate;  // FOR DEBUG
            });

        // By default is hidden
       show_hcombo_Index2(false);

    hcombo_Index2->addWidget(spinBox2_txt1);
    hcombo_Index2->addWidget(spinBox2_row);
    hcombo_Index2->addWidget(spinBox2_txt2);
    hcombo_Index2->addWidget(spinBox2_col);
    hcombo_Index2->addWidget(spinBox2_txt3);
    hcombo_Index2->addWidget(spinBox2_bombRate);
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
    switch (index) {
    case 0: // Index0 : loadboardfile
        qDebug() << "DEBUG: onComboBoxIndexChanged 0 " << endl; // FOR DEBUG
        show_hcombo_Index0(true);
        show_hcombo_Index1(false);
        show_hcombo_Index2(false);
        break;
    case 1: // Index1 : loadramdomCount
        qDebug() << "DEBUG: onComboBoxIndexChanged 1 " << endl;  // FOR DEBUG
        show_hcombo_Index0(false);
        show_hcombo_Index1(true);
        show_hcombo_Index2(false);
        break;
    case 2: // Index2 : loadramdomRate
        qDebug() << "DEBUG: onComboBoxIndexChanged 2 " << endl;  // FOR DEBUG
        show_hcombo_Index0(false);
        show_hcombo_Index1(false);
        show_hcombo_Index2(true);
        break;
    default:
        break;
    }
}

// button connect -> TO BE DONE WITH MainWindow
void StartWindow::mousePressEvent_PrintGameBoard() { print("GameBoard");}
void StartWindow::mousePressEvent_PrintGameAnswer() { print("GameAnswer"); }
void StartWindow::mousePressEvent_PrintGameState() { print("GameState"); }
void StartWindow::mousePressEvent_PrintGameStart() { 
    /********************           等待寫        ********************/
    state = State::Playing; // Optional

    // 概念:根據現在載入的資料成員，以及最終的玩家選擇的模式，去開始遊戲

    qDebug() << "DEBUG: mousePressEvent_PrintGameStart" << endl;  /* FOR DEBUG */ 

}

// Layout hide & show for combox index = 0
void StartWindow::show_hcombo_Index0(bool state) {
    this->combo_txt0->setVisible(state);
    this->lineEdit0->setVisible(state);
    this->btn_comboLoad->setVisible(state);
}

// Layout hide & show for combox index = 1
void StartWindow::show_hcombo_Index1(bool state) {
    this->spinBox1_txt1->setVisible(state);
    this->spinBox1_row->setVisible(state);
    this->spinBox1_txt2->setVisible(state);
    this->spinBox1_col->setVisible(state);
    this->spinBox1_txt3->setVisible(state);
    this->spinBox1_bombtotal->setVisible(state);
    this->spinBox1_btnLoad->setVisible(state);
}

// Layout hide & show for combox index = 2
void StartWindow::show_hcombo_Index2(bool state) {
    this->spinBox2_txt1->setVisible(state);
    this->spinBox2_row->setVisible(state);
    this->spinBox2_txt2->setVisible(state);
    this->spinBox2_col->setVisible(state);
    this->spinBox2_txt3->setVisible(state);
    this->spinBox2_bombRate->setVisible(state);
    this->spinBox2_btnLoad->setVisible(state);
}

/*
// signal to MainWindow -> TO BE DONE WITH MainWindow
void StartWindow::signal_Windows_Game_Start(){
    // Turn the Game state
    state = State::Standby;

    // close the window & emit the message
    emit StartWindow::signal_Windows_Game_Start();
    this->close();
}
*/