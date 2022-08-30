// GameBase.cpp
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// GameBase Class Definition
// Important function prompt, play..etc

#include "GameBase.h"
#include "functions.h"
#include "TicTacToeGame.h"
#include "Gomoku.h"


using namespace std;


// repeatly ask user to enter a valid input
int GameBase::prompt(unsigned int& x, unsigned int& y) {
	// Notify player to enter a coordinate to continue
	cout << "Enter a valid coordinate to play (i.e. 2,3), or 'quit' to leave the game." << endl;

	// Extract the line from input to string, check error or quit at this moment
	string line;
	if (!getline(cin, line)) {
		return errorMessage::cannot_read_line;
	}
	else if (line == "quit") {
		return errorMessage::player_quit;
	}

	// Extract comma character and replace with a space
	size_t comma_index = line.find_first_of(',');
	if (comma_index != string::npos) {
		line.at(comma_index) = ' ';
	}

	// use istringstream to extract coordinates
	istringstream iss(line);
	int a;
	int b;
	if (iss >> a >> b) {
		// Check Invalid coordinate (OutofBound)
		if (a <= x_lowerLimit || a >= x_upperLimit || b <= y_lowerLimit || b >= y_upperLimit) {
			cout << "------------------------------------------------" << endl;
			cout << "Warning: The coordinate you entered was invalid!" << endl;
			cout << "------------------------------------------------" << endl;
			// Recursively call the function untill valid/quit
			return prompt(x, y);
		}
		// When the coodinate is within the valid region, check Occupy
		else {
			int index = width * b + a;
			// Check occupied element
			if (gamepieces[index].display != " ")
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Warning: The spot you entered has already been occupied!" << endl;
				cout << "--------------------------------------------------------" << endl;
				// Recursively call the function untill valid/quit
				prompt(x, y);
			}
			else {
				// pass back the correct input
				x = a;
				y = b;
				// update longest display size
				if (static_cast<int>(gamepieces[index].display.size()) > length) {
					length = static_cast<int>(gamepieces[index].display.size());
				}
			}
		}
	}
	else{
		cout << "---------------------------------------" << endl;
		cout << "Warning: Unable to extract coordinates!" << endl;
		cout << "---------------------------------------" << endl;
		return prompt(x, y);
	}
	return success;
}

// check winning condition and draw condition, check player turn and quit message
int GameBase::play() {
	// Print gameBoard 
	print();

	while (!done() && !draw()) {
		if (turn() == errorMessage::player_quit)
		{
			return errorMessage::player_quit;
		}
	}

	if (done()) {
		cout << "===================" << endl;
		cout << "Player " << current_player << " wins!" << endl;
		cout << "===================" << endl;
		cout << "---- Game Over ----" << endl;
		return success;
	}
	else if (draw()) {
		cout << "Turn played: " << move << endl;
		if (move_remain == zero) {
			cout << "No move remainning!" << endl;
		}
		cout << "----   Draw!   ----" << endl;
		cout << "---- Game Over ----" << endl;
		return errorMessage::draw;
	}

	return success;
}

// return the pointer if game has been constructed
// return nulptr if command line is not correct
shared_ptr<GameBase> GameBase::get_Game(int len, char* args[]) {
	if (len == 2) {
		string game = args[GameName];
		if (game == "TicTacToe") {
			// construct TicTacToeGame object
			auto ptr = make_shared<TicTacToeGame>();
			return ptr;
		}
		else if (game == "Gomoku") {
			// construct Gomoku object
			auto ptr = make_shared<Gomoku>();
			return ptr;
		}
	}
	if (len == 4) {
		string game = args[GameName];
		int size = strtol(args[GameSize],&args[GameSize], decimal);
		int win = strtol(args[WinCondition], &args[WinCondition], decimal);
		if (game == "Gomoku") {
			// construct Gomoku object
			if (size >= minSize && win >= minSize && (win <= size)) {
				auto ptr = make_shared<Gomoku>(size, win);
				return ptr;
			}
			cout << "Size error: Board size must be greater than 3, winning condition must be less than board size." << endl;
			return nullptr;
		}
		cout << "Invalid Game name" << endl;
		return nullptr;
	}
	return nullptr;
}