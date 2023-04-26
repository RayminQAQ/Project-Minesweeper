#pragma once
#include "Block.h"
#include <string>
#include <fstream>

void loadBoardFile(std::string filename);
void loadRandomCount(int m, int n, int count);
void loadRandomRate(int m, int n, double rate);
void print(std::string info, std::fstream& out);
void print(std::string infot);
void leftClick(int x, int y);
void rightClick(int x, int y);
bool winOrNot();
