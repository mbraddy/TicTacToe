#pragma once

#include <iostream>

using namespace std;

//	List of all possible square states
enum SquareState { blank = ' ', X = 'X', O = 'O' };
enum LineDirection { horizontal = 1, vertical = 2, diagonal = 3};

class BoardState {
private:
	const int HEIGHT;
	const int WIDTH;
	int* BoardStatePointer;

public:
	//	Constructor and Deconstructor
	BoardState();
	~BoardState();

	//	Method Prototypes
	void setX(int h, int w);
	void setO(int h, int w);
	bool validateMove(int h, int w);
	SquareState victoryCheck();
	SquareState checkLine(SquareState squareState, LineDirection ld);
	void display();
};