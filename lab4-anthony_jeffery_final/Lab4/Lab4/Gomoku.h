// Gomoku.h
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// Gomoku class declaration

#pragma once
#include "GameBase.h"


class Gomoku : public GameBase {
private:
	// Helpers
	bool OutOfBound(game_piece piece);
	void printValidMove(char currentplayer);
	int directionNextIndex(int i, int direction);
	bool n_equal(std::vector<game_piece>& gp, int i, int n, int direction);

public:
	// Constructor
	Gomoku();
	Gomoku(int side, int nums_win);

	// Member Functions
	int win;
	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();


	// Friend function
	friend std::ostream& operator<<(std::ostream& os, const Gomoku& game);
};