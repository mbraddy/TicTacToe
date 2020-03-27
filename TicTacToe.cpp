#include "BoardState.h"
#include "TicTacToe.h"

//	Player # one or two takes a turn
BoardState* TicTacToe::inputMove(string player, BoardState* bs) {
	string turn;
	int inputOne, inputTwo;

	//	Clear screen and Displays game board
	system("CLS");
	bs->display();

	//	Determines which player is placing
	if (player.compare("one") == 0)
		turn = "X";
	else if (player.compare("two") == 0)
		turn = "O";
	else
		return bs;

	//	Enter loops to check validity of inputs
	do {

		//	Row
		do {
			cout << "\nPlayer " << player.c_str() << ", enter the row number (1, 2, or 3) for your next move: ";
			cin >> inputOne;
		} while (!validityCheck(inputOne));

		//	Column
		do {
			cout << "\nPlayer " << player.c_str() << ", enter the column number (1, 2, or 3) for your next move: ";
			cin >> inputTwo;
		} while (!validityCheck(inputTwo));

	//	Exits on validation
	} while (!(bs->validateMove(inputOne - 1, inputTwo - 1)));

	//	Input X or O
	if (player.compare("one") == 0)
		bs->setX(inputOne - 1, inputTwo - 1);
	else
		bs->setO(inputOne - 1, inputTwo - 1);

	return bs;
}

//	Make sure the inputs are between 1 and 3
bool TicTacToe::validityCheck(int test) {
	return (test < 4 && test  > 0);
}
