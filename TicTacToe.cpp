#include "BoardState.h"
#include "TicTacToe.h"

//	Main Menu for the game
void displayMenu() {
	cout << "Welcome to Tic Tac Toe. The goal of the game is to take turns placing X's or O's in order to form 3 in a row." << endl;
	cout << "Please enter your selection from the menu below: " << endl;
	cout << "\tn. Start a new game." << endl;
	cout << "\tv. View the score." << endl;
	cout << "\tq. Quit the program." << endl;
	cout << "Enter your selection: ";
}

//	Make sure menu selection is valid.
bool validateMenuSelection(char input) {
	if (input == 'n' || input == 'v' || input == 'q')
		return true;
	else {
		cout << "\nPlease choose a valid menu option (case sensitive)." << endl;
		system("pause");
		return false;
	}
}

//	Main function
int main() {
	BoardState* board;
	TicTacToe game;
	char input;
	bool quitFlag = false;
	int victoryFlag = 0;
	int playerOneScore = 0, playerTwoScore = 0;
	int turnCounter = 0;

	//	Game loop to keep score and refresh board states when new games started.
	do {
		//	Main Menu display and selection
		do {
			system("CLS");
			displayMenu();
			cin >> input;
		} while (!validateMenuSelection(input));

		switch (input) {
			//	Start a new game
		case 'n':
			//	Initialize a fresh board and the turn counter (for draws)
			board = new BoardState;
			turnCounter = 0;

			//	While the board isn't full and no one has won, alternate turns and check for victories.
			while (victoryFlag == 0) {
				turnCounter++;
				board = game.inputMove("one", board);
				if (board->victoryCheck() == 'X') {
					victoryFlag = 1;
					playerOneScore++;
					cout << "\nPlayer One Wins!" << endl;
					system("pause");
					continue;
				}
				turnCounter++;
				//	If reached turn 10 then the board is full and it's a draw.
				if (turnCounter == 10) {
					victoryFlag = 1;
					cout << "\nThe Game is a Draw. One point to each player." << endl;
					playerOneScore++;
					playerTwoScore++;
					system("pause");
					continue;
				}
				board = game.inputMove("two", board);
				if (board->victoryCheck() == 'O') {
					victoryFlag = 1;
					playerTwoScore++;
					cout << "\nPlayer Two Wins!" << endl;
					system("pause");
				}
			}
			//	Free the allocated memory after the game.
			delete(board);
			victoryFlag = 0;
			break;

			//	View the number of wins each player has obtained.
		case 'v':
			cout << "Player One has " << playerOneScore << " wins." << endl;
			cout << "Player Two has " << playerTwoScore << " wins." << endl;
			system("pause");
			break;

			//	Quit the game.
		case 'q':
			quitFlag = true;
			break;

		default:
			break;
		}
	} while (quitFlag == false);

	//	Return from Main exit code 0
	return 0;
}
