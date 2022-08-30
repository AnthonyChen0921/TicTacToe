// game_board.h
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// declaration of gameboard function

#pragma once
#include "game_piece.h"
#include "functions.h"

using namespace std;


// Declaration of the function usd in cpp file
int parseDimension(ifstream& ifs, unsigned int& h, unsigned int& v);
int parseGamePiece(ifstream& ifs, vector<game_piece>& gamepiece, unsigned int row, unsigned int col);
int printGameBoard(const vector<game_piece>& gamepiece, unsigned int row, unsigned int col);
int printAdjElement(const vector<game_piece>& gamepiece, unsigned int row, unsigned int col);
void printblock(const vector<game_piece>& gamepiece, unsigned int j, unsigned int i, unsigned col, unsigned int row, bool& semicolon);