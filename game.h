// game.h
// class Game header file

// Noah Yoshida
// Last update: Dec 1 2017

// #include "gfx.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <cmath>
#include <string>
#include "gfxnew.h"

using namespace std;

// Draws an individual square on the screen
void draw_square(int, int, int, int, int);
// Copies the board
void copyBoard(int[4][4], int[4][4]);

class game{

  public:
    game();
    ~game();

    // Sets the game based on an input board, used for end-of-game checking
    void setGame(int[4][4]);

    // Plays game
    void play();

    // Add Adjacent Squares That Can Be Added
    bool addSquares(char);

	// Moves all Squares a Certain Direction
	bool moveSquares(char);

	// Place a '2' on the Board in a Random Empty Location
	void addRandomSquare();

    // Prints board
    void print();

	// Check for End Game [TO DO]

	void endGameWindow();

  private:
    // Stores the values of the squares at each position
    int board[4][4];
    int maxScore;

};

// Checks to see if the game is over. Uses a copy of the game to check so that we
// do not modify the actual game being played 
bool endGame(game *);
