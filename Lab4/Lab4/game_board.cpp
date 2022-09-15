// game_board.cpp
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// source file that contains the definition of parseDimension and parseGamePiece
// Also contains the function to print out the board

#include "game_board.h"
#include "game_piece.h"
#include "functions.h"

using namespace std;

/// <summary>
/// Get the width and the height from the input file stream
/// </summary>
/// <param name="ifs"> input file stream </param>
/// <param name="width"> width </param>
/// <param name="height"> height </param>
/// <returns> int errorMessage </returns>
int parseDimension(ifstream& ifs, unsigned int& width, unsigned int& height) {
	int w, h;
	string line;
	if (getline(ifs, line)){
		istringstream iss(line);
		if (iss >> w >> h) {
			if (w < 0 || h < 0) {
				return errorMessage::cannot_extractDimension;
			}
			else {
				width = w;
				height = h;
				return errorMessage::success;
			}
		}
	}
	return errorMessage::cannot_read_line;
}

/// <summary>
/// Extract the info from ifs, and construct the game_piece
/// </summary>
/// <param name="ifs"> reference to input file </param>
/// <param name="gamepiece"> reference to gamepiece(item in vector) </param>
/// <param name="row"> height </param>
/// <param name="col"> width </param>
/// <returns> errorMessage or success </returns>
int parseGamePiece(ifstream& ifs, vector<game_piece>& gamepiece, unsigned int row, unsigned int col) {
	string line;
	string color;
	string name;
	string display;
	unsigned int height;
	unsigned int width;

	while (getline(ifs, line)) {
		if (ifs.fail())
		{
			return errorMessage::fail_to_open;
		}

		istringstream iss(line);

		if (iss >> color >> name >> display >> height >> width) {
			// continue to next loop if height/width is greater than given
			if ((height >= row) || (width >= col)) {
				continue;
			}
			int index = row * width + height;

			// if the piece_color is invalid or no color, continue as well
			piece_color enumColor = ColorToValue(color);
			if ((enumColor == piece_color::invalid_color) || (enumColor == piece_color::no_color)) {
				continue;
			}
			gamepiece[index].color = enumColor;
			gamepiece[index].name = name;
			gamepiece[index].display = display;
		}
	}
	return errorMessage::success;
}

// print the game board
int printGameBoard(const vector<game_piece>& gamepiece, unsigned int row, unsigned int col) {
	int game_size = static_cast<unsigned int>(gamepiece.size());
	if (game_size != row * col) {
		return errorMessage::dimension_match_error;
	}
	for (int i = col - 1; i >= 0; i--) {
		for (unsigned j = 0; j < row; j++) {
			int temp = row * i + j;
			string display = gamepiece[temp].display;
			cout << display << " ";
		}
		if (i != 0) {
			cout << endl;
		}
	}
	return errorMessage::success;
}

// print adjacent element helper
void printblock(const vector<game_piece>& gamepiece, unsigned int j, unsigned int i, unsigned col, unsigned int row, bool& semicolon) {
	if (i >= 0 && i < col && j >= 0 && j < row) {
		int index = row * i + j;
		piece_color color = gamepiece[index].color;
		if ((color != piece_color::invalid_color) && (color != piece_color::no_color)) {
			if (semicolon)
			{
				cout << "; ";
			}
			cout << i << "," << j << " " << ValueToColor(color) << " " << gamepiece[index].name;
			semicolon = true;
		}
	}
}

// printout adjacent element
int printAdjElement(const vector<game_piece>& gamepiece, unsigned int row, unsigned int col) {
	int game_size = static_cast<unsigned int>(gamepiece.size());
	if (game_size != row * col) {
		return errorMessage::dimension_match_error;
	}
	cout << endl;
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < col; j++) {
			int temp = row * i + j;
			piece_color color = gamepiece[temp].color;
			string name = gamepiece[temp].name;
			if ((color != piece_color::invalid_color) && (color != piece_color::no_color)) {
				cout << i << "," << j  << " " << ValueToColor(color) << " " << gamepiece[temp].name << ": ";
				bool ret = false;
				printblock(gamepiece, j - 1, i - 1, col, row, ret);
				printblock(gamepiece, j - 1, i, col, row, ret);
				printblock(gamepiece, j - 1, i + 1, col, row, ret);
				printblock(gamepiece, j, i + 1, col, row, ret);    
				printblock(gamepiece, j, i - 1, col, row, ret);
				printblock(gamepiece, j + 1, i - 1, col, row, ret);
				printblock(gamepiece, j + 1, i, col, row, ret);
				printblock(gamepiece, j + 1, i + 1, col, row, ret);   
				
				cout << endl;
			}
		}  
	}
	return errorMessage::success;
}