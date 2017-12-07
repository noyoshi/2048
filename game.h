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

class game{

  public:
    game();
    ~game();

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
