#pragma once
#include "RestartWindow.h"


RestartWindow::RestartWindow(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hTextLayout = new QHBoxLayout;
    QHBoxLayout* hBtnLayout = new QHBoxLayout;

    // Text Layout into hTextLayout
    QString text;
    if (is_win) { text = QString::fromStdString("You win the game!!!"); }
    else { text = QString::fromStdString("You loss the game!!!"); }

    QLabel* label_txt = new QLabel(text);
    label_txt->setAlignment(Qt::AlignHCenter);
    hTextLayout->addWidget(label_txt);
    vLayout->addLayout(hTextLayout);

    // Text Layout into hTextLayout
    QPushButton* btn_Replay = new QPushButton("Replay");
    btn_Replay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(btn_Replay, &QPushButton::clicked, this, &RestartWindow::mousePressEvent_Replay);
    //connect(btn_Replay, SIGNAL(&RestartWindow::mousePressEvent_Replay), this, SLOT());
    QPushButton* btn_Close = new QPushButton("Close Game");
    btn_Close->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(btn_Close, &QPushButton::clicked, this, [=]() { qApp->quit(); });
    
    hBtnLayout->addWidget(btn_Replay);
    hBtnLayout->addWidget(btn_Close);
    vLayout->addLayout(hBtnLayout);
    // (&sender,&Sender::foo,&receiver,&Receiver::bar);
}

void RestartWindow::mousePressEvent_Replay() {
    // close the window
    emit RestartWindow::signal_Windows_Game_restart();
    this->close();
}