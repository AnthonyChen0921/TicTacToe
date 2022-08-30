// GameBase.h
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// GameBase Header
// GameBase class declaration

#pragma once

#include <vector>
#include <stdlib.h> 
#include "game_piece.h"

class GameBase {
public:
	// game functions
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	int prompt(unsigned int& x, unsigned int& y);
	int play();

	// dynamically allocate game object according to command line arguments
	static std::shared_ptr<GameBase> get_Game(int len, char* args[]);
	
protected:
	// common varaible in game
	int width = 0;
	int height = 0;
	int move = 0;
	int move_remain = 0;
	char current_player = ' ';

	// limit
	int x_lowerLimit = 1;
	int x_upperLimit = 1;
	int y_lowerLimit = 1;
	int y_upperLimit = 1;

	// longest gamepiece display string length (c++ style string)
	int length = 1;

	// game container
	std::vector<game_piece> gamepieces;
};