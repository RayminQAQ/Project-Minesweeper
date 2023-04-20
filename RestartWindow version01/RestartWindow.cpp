#pragma once
#include "RestartWindow.h"

RestartWindow::RestartWindow(QWidget* parent/*/, bool is_win*/)
    : QWidget(parent)
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hTextLayout = new QHBoxLayout;
    QHBoxLayout* hBtnLayout = new QHBoxLayout;

    // Text Layout into hTextLayout
    QString text = QString::fromStdString("deBug");
    /*if (is_win) { text = QString::fromStdString("You win the game!!!"); }
    else { text = QString::fromStdString("You loos the game!!!"); }*/

    QLabel* label_txt = new QLabel(text);
    label_txt->setAlignment(Qt::AlignHCenter);
    hTextLayout->addWidget(label_txt);
    vLayout->addLayout(hTextLayout);

    // Text Layout into hTextLayout
    QPushButton* btn_Replay = new QPushButton("Replay");
    btn_Replay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton* btn_Close = new QPushButton("Close Window");
    btn_Close->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    hBtnLayout->addWidget(btn_Replay);
    hBtnLayout->addWidget(btn_Close);
    vLayout->addLayout(hBtnLayout);
}


/*
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <QtCore/QDebug>

class RestartWindow : public QWidget {

    Q_OBJECT

public:
    // Constructor
    RestartWindow(QWidget* parent = nullptr, bool is_win);

    // Press Event
    void mousePressEvent_Replay(QMouseEvent* event);
    void mousePressEvent_close(QMouseEvent* event);

signals:
    void signal_Windows_close();
    void signal_Windows_Game_restart();
};*/
