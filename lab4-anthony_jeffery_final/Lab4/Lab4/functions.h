// function.h 
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// function header file that provides function and enum declaration

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>


// Declaration of arrayIndices
enum arrayIndex {
	programName = 0,
	GameName = 1,
	GameSize = 2,
	WinCondition = 3,
	decimal = 10,
	expectedArg = 2,
	expectedArg2 = 4,
	minSize =3,
};

// Declaration of 4 direction
enum direction {
	horizontal,
	vertical,
	majorDiagnal,
	minorDiagnal,
};

// Declaration of enumeration of different success/failure messages
enum errorMessage {
	success,
	file_not_found,
	incorrect_usage,
	cannot_read_line,
	cannot_extractDimension,
	fail_to_open,
	dimension_match_error,
	draw,
	player_quit,
	notSupportedType,
};

// Declaration of Game Infomation
enum GameInfo : size_t {
	zero = 0,
	move_draw = 0,
	

	// move
	Tic_initial_move = 0,
	Tic_total_moves = 9,
	Gmk_initial_move = 0,
	Gmk_total_moves = 17 * 17,

	// basic board info
	TicBoardWidth = 5,
	TicBoardHeight = 5,
	GomokuBoardWidth = 19,
	GomokuBoardHeight = 19,

	GomokuWin = 5,
};

// enumeration of TicTacToe gameBoard indices
enum TicTacToeGameBoardInfo {
	Tic_game_size = TicBoardWidth * TicBoardHeight - 1,
	Tic_game_columns = TicBoardWidth - 2,
	Tic_game_rows = TicBoardHeight - 2,

	// Important: Elements reside in four corner
	Tic_left_bottom = TicBoardWidth + 1,
	Tic_left_top = TicBoardWidth * Tic_game_rows + 1,
	Tic_right_bottom = TicBoardWidth + Tic_game_columns,
	Tic_right_top = TicBoardWidth * Tic_game_rows + Tic_game_columns,
};

// enumeration of Gomoku gameBoard indices
enum GomokuGameBoardInfo {
	GMK_game_size = GomokuBoardWidth * GomokuBoardHeight - 1,
	GMK_game_columns = GomokuBoardWidth - 2,
	GMK_game_rows = GomokuBoardHeight - 2,
	counter_win = 1,

	// Important: Elements reside in four corner
	GMK_left_bottom = GomokuBoardWidth + 1,
	GMK_left_top = GomokuBoardWidth * GMK_game_rows + 1,
	GMK_right_bottom = GomokuBoardWidth + GMK_game_columns,
	GMK_right_top = GomokuBoardWidth * GMK_game_rows + GMK_game_columns
};


// Declaration of the function usd in cpp file
int usageMessage(const char* programName);
std::string ToLowerCase(std::string s);