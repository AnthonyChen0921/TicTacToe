This program will provide the user with two games, TicTacToe and Gomoku. The user can choose which game to 
play by giving the name of the game after the program name.

This is the errorlevel returns meaning:
success = 0, file_not_found = 1, incorrect_usage = 2, cannot_read_line = 3, cannot_extractDimension = 4,
fail_to_open = 5, dimension_match_error = 6, draw = 7, player_quit = 8, notSupportedType = 9,

The program will give a message when the user have this return values other than 0.

Error1:
There checking of the winning conditions sometimes goes out of bound causing errors to the program.
fix1:
Add more conditions to the done method checking the boundaries for the first playable row and column.
Error2:
There are warnings with number types and fuction initialization
fix2:
I change some number types and initialize some fuctions to intial values to avoid the warnings.

Test cases1:
I use Lab4.exe TicTacToe to start the program.
The program will goes into the TicTacToe game and will perfrom a TicTacToe game.
When user enter "quit"
The program will prints out "quit
Player X has quit the game!
Turn played: 0" and quits the program.

Test2:
I used Lab4.exe Gomoku to start the program.
The program will goes into the Gomoku game and will perfrom a Gomoku game.
When user enter "quit"
The program will prints out "quit
Player B has quit the game!
Turn played: 0" and quits the program.
When I echo %errorlevel% it returns 8 which means player_quit.

Test3:
I used Lab4.exe Gomoku to start the program and use 0,0.
It prints out the Gomoku board.
------------------------------------------------------------
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
0
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
------------------------------------------------------------
and returns.
"Warning: The coordinate you entered was invalid!"
This menas it works same with the TicTacToe where user cannot play on the outer ring so it is an invalid place.

Test4:
I used Lab4.exe Gomoku to start the program and plays out a full Gomoku game.
It prints out the Gomoku board and shows.
------------------------------------------------------------
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2     W  W  W  W
1     B  B  B  B  B
0
X  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
------------------------------------------------------------

Player B: 1,1; 2,1; 3,1; 4,1; 5,1;
===================
Player B wins!
===================
---- Game Over ----

When I do echo %errorlevel%. It shows 0 which means the program exits without error.

Test 5:
I enter Lab4.exe TicTacToe Gomoku to start the program and it returns a usage message which said:
"usage: Lab4.exe TicTacToe/Gomoku (choose either)
See usage error above to rerun the program."
When I do echo %errorlevel%. It shows 2 which means incorrect_usage.

Extra Credit:
In this part, we designed a recursion method that can solve the extra credit. First in the gamebase class,
we dectect if the user have 4 inputs which includes the gameboard size and the winning number the user want,
if the user enters the game will save those to variables to the member variable to the gomoku class which will
create a gameboard and the winning conditions accroding to the user input. If the user does not input these two
numbers the game will work the same as before with the old board size and the 5 winning pieces. The recursion winning 
condition is done by checking every pieces and its four directions using the done method, and the done method will
call n_equal method which will do a recursion on a single piece and see if it can go though the winning condtion times 
which means in that direction it have that many same piece. It will check directions becasue the directionNextIndex method
will return the next piece in this dicrection the method will check. All the boundries are checked in the end to make sure
there are no errors.
