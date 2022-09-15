// function.cpp
// Authur: AnthonyChen 
// coauthur: JefferyChai
// Email:chenerdong@wustl.edu, c.jeffery@wustl.edu
// contains usageMessage and TolowerCase function


#include "functions.h"
using namespace std;



// output usage message with program name
int usageMessage(const char* programName) {
	printf("usage: %s TicTacToe/Gomoku (choose either)", programName);
	cout << endl;
	return incorrect_usage;
}


// convert any upperCase string to lowerCase
string ToLowerCase(string s) {
	for (char c : s) {
		c = tolower(c);
	}
	return s;
}
