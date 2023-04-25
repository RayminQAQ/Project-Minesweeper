#pragma once
#include "Block.h"
#include <string>
#include <fstream>

extern int rowSize, colSize;
extern Block board[20][20];

enum class State
{
	Standby,
	Playing,
	Gameover
};
extern State state;

// For GUI
extern bool is_win;