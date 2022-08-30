// game_piece.h
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// contains struct of game_piece and enum piece_color

#pragma once
#include "functions.h"


// Enum of color on the game board
enum class piece_color{ 
	red = 1,
	black = 2,
	white = 3,
	invalid_color = 4,
	no_color = 5
};

// Declaration of the struct game_piece
struct game_piece
{
	piece_color color = piece_color::invalid_color;
	std::string name;
	std::string display;
	int coordinate_x = 0;
	int coordinate_y = 0;
};

// Declaration of the function usd in cpp file
std::string ValueToColor(piece_color colorValue);
piece_color ColorToValue(std::string color);