#pragma once

#include <string>

class TicTacToe {
public:
	BoardState* inputMove(string player, BoardState* bs);
	bool validityCheck(int test);
};