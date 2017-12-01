// game.h 
// class Game header file 

// Noah Yoshida 
// Last update: Dec 1 2017

#include "gfx.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>

using namespace std;

// Updates the board 
void update_board(char, game &);
// Updates an individual square 
void update_square(char, game &);
// Draws an individual square on the screen
void draw_square(int, int, int);

class game{
  public:
    game();
    ~game();
    // Plays the turn out 
    void play_turn(char);
    // Prints board 
    void print();
    // Prints the end screen? When the game ends 
    void end_screen();
  private:
    int board[4][4];
    int max_score;
}
    
