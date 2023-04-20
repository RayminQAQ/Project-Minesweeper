#pragma once

// for QT
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <QtCore/QDebug>
#include <QString>
#include <QLabel>

// for c++ standard
#include <string>

class RestartWindow : public QWidget {

    Q_OBJECT

public:
    // Constructor
    RestartWindow(QWidget* parent = nullptr);
    //RestartWindow(QWidget* parent, bool is_win);
    /*
        // Press Event
        void mousePressEvent_Replay(QMouseEvent* event);
        void mousePressEvent_close(QMouseEvent* event);

    signals:
        void signal_Windows_close();
        void signal_Windows_Game_restart();*/
};
