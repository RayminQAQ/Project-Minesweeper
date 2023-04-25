#include "Command.h"
#include "variable.h"
#include "main.h"
#include<fstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int bombCount = 0;
int flagCount = 0;
int openBlankCount = 0;
int remainBlankCount = 0;

void initialBoard() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			board[i][j].setBlank(0);
			board[i][j].setBomb(0);
			board[i][j].setFlag(0);
			board[i][j].setQMark(0);
			board[i][j].setOpen(0);
			board[i][j].setnearBomb(0);
		}
	}
	bombCount = 0;
	flagCount = 0;
	openBlankCount = 0;
	remainBlankCount = 0;
}

void loadBoardFile(string filename) {
	initialBoard();
	//open the file
	fstream in;
	in.open(filename, ios::in);

	//store the row and column size of the board
	string row, col;
	in >> row >> col;
	int tempRow = 0;
	int count = 1;
	for (int i = row.size() - 1; i >= 0; i--) {
		tempRow += (row[i] - '0') * count;
		count *= 10;
	}
	int tempCol = 0;
	count = 1;
	for (int i = col.size() - 1; i >= 0; i--) {
		tempCol += (col[i] - '0') * count;
		count *= 10;
	}
	rowSize = tempRow;
	colSize = tempCol;

	// set the board (blank and bomb)
	in.ignore();
	for (int i = 0; i < rowSize; i++) {
		string line;
		getline(in, line);
		for (int j = 0; j < colSize; j++) {
			if (line[j] == 'O') {
				board[i][j].setBlank(true);
				remainBlankCount++;
			}
			else if (line[j] == 'X') {
				board[i][j].setBomb(true);
				bombCount++;
			}
		}
	}

	// set the board (nearBomb)
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (board[i][j].getBomb()) {
				for (int m = -1; m <= 1; m++) {
					for (int n = -1; n <= 1; n++) {
						int di = i + m;
						int dj = j + n;
						if (isInBoard(di, dj)) {
							if (board[di][dj].getBlank()) {
								int nearbomb = board[di][dj].getnearBomb();
								nearbomb += 1;
								board[di][dj].setnearBomb(nearbomb);
							}
						}
					}
				}
			}
		}
	}

	in.close();
}

void loadRandomCount(int m, int n, int count) {
	initialBoard();
	srand(time(NULL));

	// initialize row size and column size
	rowSize = m;
	colSize = n;

	// random place the bomb
	for (int i = 0; i < count; i++) {
		int drow, dcol;
		do {
			drow = rand() % rowSize;
			dcol = rand() % colSize;
		} while (board[drow][dcol].getBomb());
		board[drow][dcol].setBomb(1);
		bombCount++;
	}

	// set the board(blank and bomb)
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (!board[i][j].getBomb()) {
				board[i][j].setBlank(1);
				remainBlankCount++;
			}
		}
	}

	// set the board(near bomb)
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (board[i][j].getBomb()) {
				for (int m = -1; m <= 1; m++) {
					for (int n = -1; n <= 1; n++) {
						int di = i + m;
						int dj = j + n;
						if (isInBoard(di, dj)) {
							if (board[di][dj].getBlank()) {
								int nearbomb = board[di][dj].getnearBomb();
								nearbomb += 1;
								board[di][dj].setnearBomb(nearbomb);
							}
						}
					}
				}
			}
		}
	}
}

void loadRandomRate(int m, int n, double rate) {
	srand(time(NULL));
	initialBoard();

	rowSize = m;
	colSize = n;
	rate *= 100;

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			int randomNumber = rand() % 100 + 1;
			if (randomNumber <= rate) {
				board[i][j].setBomb(1);
				bombCount++;
			}
			else {
				board[i][j].setBlank(1);
				remainBlankCount++;
			}
		}
	}

	// set the board(near bomb)
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (board[i][j].getBomb()) {
				for (int m = -1; m <= 1; m++) {
					for (int n = -1; n <= 1; n++) {
						int di = i + m;
						int dj = j + n;
						if (isInBoard(di, dj)) {
							if (board[di][dj].getBlank()) {
								int nearbomb = board[di][dj].getnearBomb();
								nearbomb += 1;
								board[di][dj].setnearBomb(nearbomb);
							}
						}
					}
				}
			}
		}
	}
}

void print(string info) {
	if (info == "GameBoard") { // print game board
		cout << endl;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (board[i][j].getOpen()) {
					cout << board[i][j].getnearBomb() << ' ';
				}
				else {
					if (board[i][j].getFlag()) {
						cout << 'f' << ' ';
					}
					else if (board[i][j].getQMark()) {
						cout << "? ";
					}
					else {
						cout << '#' << ' ';
					}
				}
			}
			cout << endl;
		}
	}
	else if (info == "GameState") { // print game state
		if (state == State::Standby) {
			cout << "Standby\n";
		}
		else if (state == State::Playing) {
			cout << "Playing\n";
		}
		else if (state == State::Gameover) {
			cout << "Gameover\n";
		}
	}
	else if (info == "GameAnswer") { // print game answer
		cout << endl;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (board[i][j].getBlank()) {
					cout << board[i][j].getnearBomb() << ' ';
				}
				else if (board[i][j].getBomb()) {
					cout << 'X' << ' ';
				}
			}
			cout << endl;
		}
	}
	else if (info == "BombCount") { // print the number of the bombs
		cout << bombCount << endl;
	}
	else if (info == "FlagCount") { // print the number of the flags
		cout << flagCount << endl;
	}
	else if (info == "OpenBlankCount") {// print the number of the opened blanks
		cout << openBlankCount << endl;
	}
	else if (info == "RemainBlankCount") { // print the number of the remain blanks
		cout << remainBlankCount << endl;
	}

	//out.close();
}

void print(string info, fstream& out) {
	if (info == "GameBoard") { // print game board
		cout << endl;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (board[i][j].getOpen()) {
					out << board[i][j].getnearBomb() << ' ';
				}
				else {
					if (board[i][j].getFlag()) {
						out << 'f' << ' ';
					}
					else if (board[i][j].getQMark()) {
						out << "? ";
					}
					else {
						out << '#' << ' ';
					}
				}
			}
			out << endl;
		}
	}
	else if (info == "GameState") { // print game state
		if (state == State::Standby) {
			out << "Standby\n";
		}
		else if (state == State::Playing) {
			out << "Playing\n";
		}
		else if (state == State::Gameover) {
			out << "Gameover\n";
		}
	}
	else if (info == "GameAnswer") { // print game answer
		cout << endl;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				if (board[i][j].getBlank()) {
					out << board[i][j].getnearBomb() << ' ';
				}
				else if (board[i][j].getBomb()) {
					out << 'X' << ' ';
				}
			}
			out << endl;
		}
	}
	else if (info == "BombCount") { // print the number of the bombs
		out << bombCount << endl;
	}
	else if (info == "FlagCount") { // print the number of the flags
		out << flagCount << endl;
	}
	else if (info == "OpenBlankCount") {// print the number of the opened blanks
		out << openBlankCount << endl;
	}
	else if (info == "RemainBlankCount") { // print the number of the remain blanks
		out << remainBlankCount << endl;
	}

}

void leftClick(int row, int col)
{
	if (board[row][col].getBomb()) {
		board[row][col].setOpen(1);
		state = State::Gameover;
	}
	else if (board[row][col].getnearBomb() != 0) {
		board[row][col].setOpen(1);
		openBlankCount++;
		remainBlankCount--;
	}
	else {
		board[row][col].setOpen(1);
		openBlankCount++;
		remainBlankCount--;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				int drow = row + i;
				int dcol = col + j;

				if (drow >= 0 && drow < rowSize && dcol >= 0 && dcol < colSize && !board[drow][dcol].getOpen() && !board[drow][dcol].getFlag()) {
					leftClick(drow, dcol);
				}
			}
		}
	}
	if (remainBlankCount == 0) {
		state = State::Gameover;
	}
}

void rightClick(int row, int col)
{
	if (!board[row][col].getFlag() && !board[row][col].getQMark()) {// if not flag neither question mark, set flag
		board[row][col].setFlag(true);
		flagCount++;
	}
	else if (board[row][col].getFlag()) { // if flag, set question mark and unset flag
		board[row][col].setQMark(true);
		board[row][col].setFlag(false);
		flagCount--;
	}
	else if (board[row][col].getQMark()) { // if question mark, unset question mark
		board[row][col].setQMark(false);
	}
}

bool winOrNot() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (board[i][j].getOpen() && board[i][j].getBomb()) {
				return false;
			}
			if (board[i][j].getBlank()) {
				return false;
			}
		}
	}
	return true;
}
