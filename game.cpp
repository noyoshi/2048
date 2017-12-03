// game.cpp
// Class game implementation

// Noah Yoshida + Allen Duong
// Last updated: Dec 3 2017

// #include "gfx.h"
#include "game.h"

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

  /// Randomly Place First Piece
  addRandomSquare();

  // Lowest possible score is a 2
  maxScore = 2;
}

game::~game(){} // Destructor

void game::play(){ // Plays The Game

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

	system("clear");

	// Update the Board

	moveSquares(c);
	addSquares(c);
	moveSquares(c);
	add_random_square();

	print();
    skip:;
    cout << "wasd to move, q to quit: ";
  }

}


void game::moveSquares(char dir){ // Function to Compress All Current Squares to a Single Side

  switch(dir){

    case 119: // Up
      
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			int count = 0;  // Count of non-zero elements

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row and Push Things Up

				if (board[yCoord][xCoord] != 0){
					board[count++][xCoord] = board[yCoord][xCoord];
				}
			}

			// Now all non-zero elements have been shifted to 
			// front and  'count' is set as index of first 0. 
			// Make all elements 0 from count to end.

			while (count < 4)
				board[count++][xCoord] = 0;
		}
		
      break;


    case 115: // Down
     
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			int count = 3;  // Count of non-zero elements

			for (int yCoord = 3; yCoord >= 0; yCoord--){ // Go Through Every Row and Push Things Up

				if (board[yCoord][xCoord] == 0){
					continue;
				}
				else{
					board[count--][xCoord] = board[yCoord][xCoord];
				}
			}

			// Now all non-zero elements have been shifted to 
			// front and  'count' is set as index of first 0. 
			// Make all elements 0 from count to end.
			

			while (count >= 0)
				board[count--][xCoord] = 0;
		}

      break;


    case 97: // Left

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Each Row

			int count = 0;  // Count of non-zero elements

			for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Every Column and Push Things Left

				if (board[yCoord][xCoord] != 0){
					board[yCoord][count++] = board[yCoord][xCoord];
				}
			}

			// Now all non-zero elements have been shifted to 
			// front and  'count' is set as index of first 0. 
			// Make all elements 0 from count to end.

			while (count < 4)
				board[yCoord][count++] = 0;
		}
     
      break;

    case 100: // Right

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Each Row

			int count = 3;  // Count of non-zero elements

			for (int xCoord = 3; xCoord >= 0; xCoord--){ // Go Through Every Column and Push Things Right

				if (board[yCoord][xCoord] == 0){
					continue;
				}
				else{
					board[yCoord][count--] = board[yCoord][xCoord];
				}

			}

			// Now all non-zero elements have been shifted to 
			// front and  'count' is set as index of first 0. 
			// Make all elements 0 from count to end.


			while (count >= 0)
				board[yCoord][count--] = 0;
		}
      break;
  }
}

void game::addSquares(char dir){
	
	switch (dir){

	case 119: // Up

		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Add Things, Prioritizing Lower Index Values

				if (board[yCoord][xCoord] == board[yCoord + 1][xCoord]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord + 1][xCoord] = 0;
				}
			}
		}

		break;

	case 115: // Down
		
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 3; yCoord >= 0; yCoord--){ // Add Things, Prioritizing Lower Higher Values

				if (board[yCoord][xCoord] == board[yCoord - 1][xCoord]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord - 1][xCoord] = 0;
				}
			}
		}

		break;


	case 97: // Left

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Each Row

			for (int xCoord = 0; xCoord < 4; xCoord++){ // Add Things, Prioritizing Lower Index Values

				if (board[yCoord][xCoord] == board[yCoord][xCoord + 1]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord][xCoord + 1] = 0;
				}
			}
		}

		break;


	case 100: // Right

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Each Row

			for (int xCoord = 3; xCoord >= 0; xCoord--){ // Add Things, Prioritizing Lower Index Values

				if (board[yCoord][xCoord] == board[yCoord][xCoord - 1]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord][xCoord - 1] = 0;
				}
			}
		}

		break;
	}
}

void game::addRandomSquare(){
  
	srand(time(NULL));

	while (true){

		// Randomize a Location
		int xCoord = rand() % 3;
		int yCoord = rand() % 3;

		if (board[yCoord][xCoord] == 0){
			board[yCoord][xCoord] = 2;
			break;
		}
	}
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
