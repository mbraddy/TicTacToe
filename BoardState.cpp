#include "BoardState.h"

BoardState::BoardState() : HEIGHT(3), WIDTH(3) {
	//	Dynamically Allocate Board and Initiallize blanks
	BoardStatePointer = new int[9];
	for (int i = 0; i < 9; i++)
		* (BoardStatePointer + i) = blank;
}

BoardState::~BoardState() {
	//	Free allocated memory
	delete[](BoardStatePointer);
}

//	Place X's
void BoardState::setX(int h, int w) {
	*(BoardStatePointer + h * HEIGHT + w) = X;
}

//	Place O's
void BoardState::setO(int h, int w) {
	*(BoardStatePointer + h * HEIGHT + w) = O;
}

//	Makes sure move possible
bool BoardState::validateMove(int h, int w) {
	return *(BoardStatePointer + h * HEIGHT + w) == ' ';
}

//	Check all possible Tic Tac Toes
SquareState BoardState::victoryCheck() {
	SquareState victoryFlag = blank;
	
	if (checkLine(X, horizontal) == X || checkLine(X, vertical) == X || checkLine(X, diagonal) == X)
		victoryFlag = X;

	else if (checkLine(O, horizontal) == O || checkLine(O, vertical) == O || checkLine(O, diagonal) == O)
		victoryFlag = O;

	return victoryFlag;
}

SquareState BoardState::checkLine(SquareState squareState, LineDirection ld) {
	switch (ld) {
	case horizontal:
		if (*BoardStatePointer == squareState && *(BoardStatePointer + 1) == squareState && *(BoardStatePointer + 2) == squareState)
			return squareState;
		else if (*(BoardStatePointer + 3) == squareState && *(BoardStatePointer + 4) == squareState && *(BoardStatePointer + 5) == squareState)
			return squareState;
		else if (*(BoardStatePointer + 6) == squareState && *(BoardStatePointer + 7) == squareState && *(BoardStatePointer + 8) == squareState)
			return squareState;
		break;
	case vertical:
		if (*BoardStatePointer == squareState && *(BoardStatePointer + 3) == squareState && *(BoardStatePointer + 6) == squareState)
			return squareState;
		else if (*(BoardStatePointer + 1) == squareState && *(BoardStatePointer + 4) == squareState && *(BoardStatePointer + 7) == squareState)
			return squareState;
		else if (*(BoardStatePointer + 2) == squareState && *(BoardStatePointer + 5) == squareState && *(BoardStatePointer + 8) == squareState)
			return squareState;
		break;
	case diagonal:
		if (*BoardStatePointer == squareState && *(BoardStatePointer + 4) == squareState && *(BoardStatePointer + 8) == squareState)
			return squareState;
		else if (*(BoardStatePointer + 2) == squareState && *(BoardStatePointer + 4) == squareState && *(BoardStatePointer + 6) == squareState)
			return squareState;
		break;
	default:
		break;
	}
	return blank;
}

//	Displays the board state
void BoardState::display() {
	cout << endl;
	for (int i = 0; i < HEIGHT; i++) {
		cout << (char) *(BoardStatePointer + i * HEIGHT);
		for  (int j = 1; j < WIDTH; j++) {
			cout << " | " << (char) *(BoardStatePointer + i * WIDTH + j);
		}
		if (i != HEIGHT - 1)
			cout << endl << "---------\n";
		else
			cout << endl;
	}
}