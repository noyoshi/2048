// game.cpp
// Class game implementation

// Noah Yoshida
// Last updated: Dec 1 2017

// #include "gfx.h"
#include "game.h"

/*
Already included in header file?
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
*/

// By passing the game, g, by reference, we can modify it inside the function
void draw_square(int x, int y, int value, int XSIZE, int YSIZE){
  // Draws a square on the board
}

game::game(){
  // Fills the board with 0's, which are the default value
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      board[i][j] = 0;
    }
  }
  board[2][2] = 2;
  // Lowest possible score is a 2
  max_score = 2;
}

game::~game(){
  // Destructor
}

void game::play(){
  // Plays the game

  // Temp method to make sure logic works
  char c;
  cout << "wasd to move, q to quit: ";
  print();
  while(cin >> c){
    // Play game
    if(c != 97 and c!= 119 and c!= 115 and c!= 100 and c!= 'q'){
      cout << c << endl;
      cout << "Bad input, please try again.\n";
      goto skip;
    }

    if(c == 'q') // End the game
      break;

    update_board(c);
    print();
    add_random_square();
    skip:;
    cout << "wasd to move, q to quit: ";
  }

}

void game::update_board(char dir){
  // Updates the board after one turn
  switch(dir){
    case 119:
      // Up
      for(int i = 1; i < 4; i++){
        // We do not have to check the top row, they do not move
        for(int j = 0; j < 4; j++){
          if(board[i][j] != 0)
            update_square(dir, i, j);
        }
      }

      break;
    case 115:
      // Down
      for(int i = 2; i >= 0; i--){
        // We do not have to check the bottom row, they do not move
        for(int j = 0; j < 4; j++){
          if(board[i][j] != 0)
            update_square(dir, i, j);
        }
      }

      break;
    case 97:
      // Left
      for(int j = 1; j < 4; j++){
        // We do not have to check the left row, they do not move
        for(int i = 3; i >= 0; i--){
          if(board[i][j] != 0)
            update_square(dir, i, j);
        }
      }

      break;
    case 100:
      // Right
      for(int j = 2; j >= 0; j--){
        // We do not have to check the right row, they do not move
        for(int i = 0; i < 4; i++){
          if(board[i][j] != 0)
            update_square(dir, i, j);
        }
      }
      break;
  }
}

void game::update_square(char dir, int i, int j){
  // Called in update_board for every square, this function updates the position
  // and possibly the value of a square being moved

  cout << "updating " << i << " " << j << endl;
  switch(dir){
    case 119:
      // Up
      while(board[i-1][j] == 0 and i >= 0){
        // While not at top edge and the next space is empty


        board[i-1][j] = board[i][j];
        board[i][j] = 0;
        // Moves the square, incriments to the next loation
        i --;
      }
      if(i < 0){
        i = 0;
      }
      if(board[i-1][j] == board[i][j]){
        // If the next square is of equal value
        board[i-1][j] += board[i][j];
        board[i][j] = 0;
        break;
        // Due to the order we traverse the grid, we will never have a case
        // where two blocks combine, then the combined block will move
      }
      break;
    case 115:
      // Down
      while(board[i+1][j] == 0 and i != 4){
        // While not at bottom edge and the next space is empty


        board[i+1][j] = board[i][j];
        board[i][j] = 0;
        // Moves the square, incriments to the next loation
        i ++;
      }
      if(i > 3){
        i = 3;
      }
      if(board[i+1][j] == board[i][j]){
        // If the next square is of equal value
        board[i+1][j] += board[i][j];
        board[i][j] = 0;
        break;
        // Due to the order we traverse the grid, we will never have a case
        // where two blocks combine, then the combined block will move
      }
      break;
    case 97:
      // Left
      while(board[i][j-1] == 0 and j >= 0){
        // While not at bottom edge and the next space is empty


        board[i][j-1] = board[i][j];
        board[i][j] = 0;
        // Moves the square, incriments to the next loation
        j --;
      }
      if(j < 0){
        j = 1;
      }
      if(board[i][j-1] == board[i][j]){
        // If the next square is of equal value
        board[i][j-1] += board[i][j];
        board[i][j] = 0;
        break;
        // Due to the order we traverse the grid, we will never have a case
        // where two blocks combine, then the combined block will move
      }
      break;
    case 100:
      // Right
      while(board[i][j+1] == 0 and j < 4){
        // While not at bottom edge and the next space is empty


        board[i][j+1] = board[i][j];
        board[i][j] = 0;
        // Moves the square, incriments to the next loation
        j ++;
      }
      if(j > 3){
        j --;
      }
      if(board[i][j+1] == board[i][j]){
        // If the next square is of equal value
        board[i][j+1] += board[i][j];
        board[i][j] = 0;
        break;
        // Due to the order we traverse the grid, we will never have a case
        // where two blocks combine, then the combined block will move
      }
      break;
  }
}

void game::add_random_square(){
  // Temporary, non-random tester
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(board[i][j] == 0){
        board[i][j] = 2;
        goto end;
      }
    }
  }
  end:;
}

void game::print(){
  // Prints the board state to the screen
  /*
  int const XSIZE = 800, YSIZE = 800;
  char input;

  gfx_open(XSIZE, YSIZE, "2048");
  */
  // TODO: First, we are going to just make sure logic works. This will
  // draw to command line for that.

  cout << "_________________\n";
  for(int i = 0; i < 4; i++){
    cout << "| ";
    for(int j = 0; j < 4; j++){
      cout << board[i][j] << " ";
    }
    cout << "|\n";
  }
  cout << "_________________\n";
  cout << "Max score: " << max_score << endl;
}

// void game::end_screen(){
//   // End screen? Might not need this, we shall see
// }
