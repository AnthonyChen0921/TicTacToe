// Lab4.cpp
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// The main function to implement the cpp file

#include "TicTacToeGame.h"
#include "functions.h"
#include "game_piece.h"
#include "GameBase.h"


using namespace std;

int main(int argc, char* argv[])
{
	// Obtain programName at argv[0]
	const char* program = argv[arrayIndex::programName];

	// Call get game using shared ptr and passing commandline arguments
	shared_ptr<GameBase> ptr = GameBase::get_Game(argc, argv);

	// Check if exactly 1 arguments (in addition to programName, so expected argunments should be 2)
	if (argc != arrayIndex::expectedArg && argc != arrayIndex::expectedArg2) {
		int error = usageMessage(program);
		cout << "See usage error above to rerun the program." << endl;
		return error;
	}
	else {
		// if game is constructed, call play()
		if (ptr != nullptr) {
			return ptr->play();
		}
		else {
			int error = usageMessage(program);
			cout << "Game not supported or incorrect Game Name" << endl;
			return error;
		}
	}
	return success;
}
