// TicTacToeGame.h
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// TicTacToeGame class declaration

#pragma once

#include <fstream>
#include "game_piece.h"
#include "GameBase.h"



class TicTacToeGame : public GameBase{
public:
	// Constructor
	TicTacToeGame();
	
	// Member Functions
	virtual bool draw();
	virtual int turn();
	virtual bool done();
	void print() override;

	// Helpers
	bool OutOfBound(game_piece piece);
	bool tripleEqual(game_piece a, game_piece b, game_piece c);
	void printValidMove(char currentplayer);

	// Friend function
	friend std::ostream& operator<<(std::ostream& output, const TicTacToeGame& game);
};