// Gomoku.cpp
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// Gomoku Class Definition
// Important function to detect winner, printboard..etc

#include "Gomoku.h"

using namespace std;

// Default constructor
Gomoku::Gomoku() {
	width = GomokuBoardWidth ;
	height = GomokuBoardHeight;
	current_player = 'W';
	move = Gmk_initial_move;
	move_remain = Gmk_total_moves;

	// Valid Cooridnate domain
	x_lowerLimit = zero;
	x_upperLimit = GomokuBoardWidth - 1;
	y_lowerLimit = zero;
	y_upperLimit = GomokuBoardHeight - 1;

	win = GomokuWin;

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

// Customize constructor
Gomoku::Gomoku(int side, int nums_win) {
	width = side + 2;
	height = side + 2;
	current_player = 'W';
	move = Gmk_initial_move;
	move_remain = (side-2) * (side - 2);

	// Valid Cooridnate domain
	x_lowerLimit = zero;
	x_upperLimit = width - 1;
	y_lowerLimit = zero;
	y_upperLimit = height - 1;

	// parse in winning condition
	win = nums_win;

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
std::ostream& operator<<(std::ostream& output, const Gomoku& game) {
	output << left << endl;
	size_t IndexSize = to_string(game.width - 1).size() + 1;
	string sep(IndexSize * (static_cast<size_t>(game.width) + 1), '-');
	output << sep << endl;
	for (int i = game.width - 1; i >= 0; i--)
	{
		// Print y axis
		output << setw(IndexSize) << i;

		// Print gamepiece G W or empty
		for (int j = 0; j <= game.height - 1; j++)
		{
			int index = game.width * i + j;
			output << setw(IndexSize) << game.gamepieces[index].display;
		}
		output << endl;
	}

	// Print x axis
	output << setw(IndexSize) << "X";
	for (int k = 0; k < game.width; k++) {
		output << setw(IndexSize) << k;
	}
	output << endl;
	output << sep << endl;

	return output;

}



// Simple print
void Gomoku::print() {
	cout << *this << endl;
}

// return True if given piece is out of game board.
bool Gomoku::OutOfBound(game_piece piece) {
	if (piece.coordinate_x <= x_lowerLimit|| piece.coordinate_x >= x_upperLimit|| piece.coordinate_y <= y_lowerLimit|| piece.coordinate_y >= y_upperLimit) {
		return true;
	}
	return false;
}

// return the index of next element accroding to direction
int Gomoku::directionNextIndex(int i, int direction) {
	switch (direction) {
	case horizontal:
		// next horizontal 
		return i + 1;
	case vertical:
		// next vertical
		return i + width;
	case majorDiagnal:
		// next major dignal
		return i + width + 1;
	case minorDiagnal:
		// next minor dignal
		return i + width - 1;
	}
	return 0;
}

// recursively check 2 element in the board, check if n in a row
bool Gomoku::n_equal(vector<game_piece>& gp, int i, int n, int direction) {
	// counter down to one, there's a winner
	if (n == counter_win) {
		return true;
	}
	// Check 2 element according to given direction recursively
	if (!OutOfBound(gp[i]) && !OutOfBound(gp[directionNextIndex(i,direction)])) {
		if ((gp[i].display != " ") && (gp[i].display == gp[directionNextIndex(i, direction)].display)) {
			return n_equal(gp, directionNextIndex(i, direction), n - 1, direction);
		}
	}
	return false;
}

// Scan through every elements in the board
// Centered as looping element, check horizontal, vertical, major/minor diagonal
bool Gomoku::done() {
	for (int i = width +1; i <= width * (height -2) + (width -2); i++) {
		// Checking 4 directions
		for (int j = 1; j <= 4; j++) {
			// once n in a row detected, return true
			if (n_equal(gamepieces, i, win, j)) {
				return true;
			}
		}
	}
	return false;
}




// check if the game is draw
bool Gomoku::draw() {
	if (done() || move_remain != move_draw) {
		return false;
	}
	return true;
}

// print the accumulated move of either player G or W
void Gomoku::printValidMove(char currentplayer) {
	if (currentplayer == 'B') {
		cout << "Player B: ";
		for (int i = 0; i <= width * height - 1; ++i) {
			if (gamepieces[i].display == "B") {
				cout << gamepieces[i].coordinate_x << "," << gamepieces[i].coordinate_y << "; ";
			}
		}
		cout << endl;
	}
	else if (currentplayer == 'W') {
		cout << "Player W: ";
		for (int i = 0; i <= width * height -1; ++i) {
			if (gamepieces[i].display == "W") {
				cout << gamepieces[i].coordinate_x << "," << gamepieces[i].coordinate_y << "; ";
			}
		}
		cout << endl;
	}
}


// Switch player when valid move has been made
int Gomoku::turn() {

	unsigned int x = width;
	unsigned int y = height;

	if (current_player == 'B')
	{
		// Switch player
		current_player = 'W';
	}
	else if (current_player == 'W')
	{
		// Switch player
		current_player = 'B';
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
	int index = width * y + x;
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

