// TicTacToeGame.cpp
// Authur: AnthonyChen 
// Email:chenerdong@wustl.edu
// TocTacToeGame Class Definition
// Important function to detect winner, printboard..etc

#include "TicTacToeGame.h"
#include "functions.h"
#include "game_piece.h"
using namespace std;

// Default constructor
TicTacToeGame::TicTacToeGame() {
	// initalization of member variable
	width = TicBoardWidth;
	height = TicBoardHeight;
	current_player = 'O';
	move = Tic_initial_move;
	move_remain = Tic_total_moves;


	// Valid Cooridnate domain
	x_lowerLimit = zero;
	x_upperLimit = TicBoardWidth - 1;
	y_lowerLimit = zero;
	y_upperLimit = TicBoardHeight - 1;

	// empty the game board
	for (int i = width - 1; i >= 0; --i) {
		for (int j = 0; j <= height - 1; ++j) {
			// Construct the struct gamepiece to pushback to Game vector
			game_piece piece;
			piece.coordinate_x = zero;
			piece.coordinate_y = zero;
			piece.display = " ";
			gamepieces.push_back(piece);
		}
	}
	// fill in the x,y cooridnates
	for (int i = width - 1; i >= 0; --i) {
		for (int j = 0; j <= height - 1; ++j) {
			int index = width * i + j;
			gamepieces[index].coordinate_x = j;
			gamepieces[index].coordinate_y = i;
		}
	}
	
}

// Overload the << operator that is used to printout board
std::ostream& operator<<(std::ostream& output, const TicTacToeGame& game) {
	output << endl;
	output << "---------------------" << endl;

	size_t IndexSize = to_string(game.width - 1).size();
	for (int i = game.width - 1; i >= 0; i--)
	{
		// Print y axis
		output << setw(IndexSize) << i << " ";

		// Print gamepiece X O or empty
		for (int j = 0; j <= game.height - 1; j++)
		{
			int index = game.width * i + j;
			output << setw(game.length) <<game.gamepieces[index].display << " ";
		}
		output << endl;
	}

	// Print x axis
	output << "  ";
	for (int k = 0; k < game.width; k++) {
		output << setw(game.length) << k << " ";
	}
	output << endl;
	output << "---------------------" << endl;

	return output;

}

// Simple print
void TicTacToeGame::print() {
	cout << *this << endl;
}

// return True if given piece is out of game board.
bool TicTacToeGame::OutOfBound(game_piece piece) {
	if (piece.coordinate_x <= x_lowerLimit || piece.coordinate_x >= x_upperLimit || piece.coordinate_y <= y_lowerLimit || piece.coordinate_y >= y_upperLimit) {
		return true;
	}
	return false;
}

// return True if given three piece is equal to each other and is not empty
bool TicTacToeGame::tripleEqual(game_piece a, game_piece b, game_piece c) {
	if (!OutOfBound(a) && !OutOfBound(c) && !OutOfBound(b)) {
		if ((a.display != " ") && (a.display == b.display) && (b.display == c.display)) {
			return true;
		}
		return false;
	}
	return false;
}

// Scan through every elements in the board
// Centered as looping element, check horizontal, vertical, major/minor diagonal
bool TicTacToeGame::done() {
	for (size_t i = Tic_left_bottom; i <= Tic_right_top; i++) {
		// Check horizontal:
		if (tripleEqual(gamepieces[i-1], gamepieces[i], gamepieces[i+1])) {
			return true;
		}

		// Check vertical:
		if (tripleEqual(gamepieces[i- TicBoardHeight], gamepieces[i], gamepieces[i+ TicBoardHeight])) {
			return true;
		}

		// Check Major Diagonal:
		if (tripleEqual(gamepieces[i-(TicBoardHeight-1)], gamepieces[i], gamepieces[i+(TicBoardHeight-1)])) {
			return true;
		}

		// Check Minor Diagonal:
		if (tripleEqual(gamepieces[i-(TicBoardHeight+1)], gamepieces[i], gamepieces[i+(TicBoardHeight+1)])) {
			return true;
		}
	}
	return false;
}

// check if the game is draw
bool TicTacToeGame::draw() {
	if (done() || move_remain != move_draw) {
		return false;
	}
	return true;
}



// print the accumulated move of either player X or O
void TicTacToeGame::printValidMove(char currentplayer) {
	if (currentplayer == 'X') {
		cout << "Player X: ";
		for (int i = Tic_left_bottom; i <= Tic_right_top; ++i) {
			if (gamepieces[i].display == "X") {
				cout << gamepieces[i].coordinate_x << "," << gamepieces[i].coordinate_y << "; ";
			}
		}
		cout << endl;
	}
	else if (currentplayer == 'O') {
		cout << "Player O: ";
		for (int i = Tic_left_bottom; i <= Tic_right_top; ++i) {
			if (gamepieces[i].display == "O") {
				cout << gamepieces[i].coordinate_x << "," << gamepieces[i].coordinate_y << "; ";
			}
		}
		cout << endl;
	}
}

// Switch player when valid move has been made
int TicTacToeGame::turn() {

	unsigned int x = TicBoardWidth;
	unsigned int y = TicBoardHeight;

	if (current_player == 'X')
	{
		// Switch player
		current_player = 'O';
	}
	else if (current_player == 'O')
	{
		// Switch player
		current_player = 'X';
	}

	cout << "*** Turn for Player " << current_player << "! ***" << endl;
	
	// Put x,y into board
	int p = prompt(x, y);
	if (p == errorMessage::player_quit) {
		cout << "Player " << current_player << " has quit the game!" << endl;
		cout << "Turn played: " << move << endl;
		move_remain = zero;
		return errorMessage::player_quit;
	} 
	int index = TicBoardWidth * y + x;
	gamepieces[index].display = current_player;

	// Increment move played
	++move;
	--move_remain;

	// Print the board
	cout << *this << endl;

	// Print valid move
	printValidMove(current_player);

	return success;
}

