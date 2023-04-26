#pragma once

class Block {
private:
	bool isBlank, isBomb, isFlag, isQMark, isOpen;
	int nearBomb;

public:
	// Constructor
	Block();

	// get function
	bool getBlank(void) { return this->isBlank; }
	bool getBomb(void) { return this->isBomb; }
	bool getFlag(void) { return this->isFlag; }
	bool getQMark(void) { return this->isQMark; }
	bool getOpen(void) { return this->isOpen; }
	int getnearBomb(void) { return this->nearBomb; }

	// set function
	void setBlank(bool state) { this->isBlank = state; }
	void setBomb(bool state) { this->isBomb = state; }
	void setFlag(bool state) { this->isFlag = state; }
	void setQMark(bool state) { this->isQMark = state; }
	void setOpen(bool state) { this->isOpen = state; }
	void setnearBomb(int num) { this->nearBomb = num; }

public:
	// function
};


// Question: Need to Optimize for the setBomb and setBlank?