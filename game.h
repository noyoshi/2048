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

using namespace std;

// Draws an individual square on the screen
void draw_square(int, int, int, int, int);

// void animate_transition()
// used if we want to animate each turn?

class game{
  public:
    game();
    ~game();

    // Plays game
    void play();

    // Updates the board
    void update_board(char);

    // Add Adjacent Squares That Can Be Added 
    void addSquares(char);

	// Moves all Squares a Certain Direction
	void moveSquares(char);


	
    void add_random_square();

    // Prints board
    void print();

    // Prints the end screen? When the game ends
    // void end_screen();
  private:
    // Stores the values of the squares at each position
    int board[4][4];
    int max_score;
    // temp_board[4][4]
    // stores the previous board state, used for animation?
};
