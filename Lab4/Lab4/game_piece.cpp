// game_piece.cpp
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// some useful utillity to interchange piece_color with color string

#include "game_piece.h"

using namespace std;

/// <summary>
/// Given color Vlaue and convert to specific color string
/// </summary>
/// <param name="colorValue"> int colorValue </param>
/// <returns> Color string accordingly </returns>
string ValueToColor(piece_color colorValue) {
	switch (colorValue) {
		default: 
			return " ";
		case piece_color::red:
			return "red";
		case piece_color::black:
			return "black";
		case piece_color::white:
			return "white";
		case piece_color::invalid_color:
			return "invalid color";
		case piece_color::no_color:
			return " ";
	}
}


/// <summary>
/// Given color string and convert to specific color value
/// </summary>
/// 
/// <param name="color"> string color </param>
/// <returns> piece_color </returns>
piece_color ColorToValue(string color) {
	string color_lower = ToLowerCase(color);
	
	if (color == "red") {
		return piece_color::red;
	}
	else if (color == "black") {
		return piece_color::black;
	}
	else if (color == "white") {
		return piece_color::white;
	}
	else if (color == " ") {
		return piece_color::no_color;
	}
	else {
		return piece_color::invalid_color;
	}
}



