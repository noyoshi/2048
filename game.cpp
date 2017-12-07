// game.cpp
// Class game implementation

// Noah Yoshida + Allen Duong
// Last updated: Dec 3 2017:
//		- Removed GoTo's
//		- Added Animation

#include "game.h"
#include "gfxnew.h"

void drawSquare(int xCoord, int yCoord){
	// Draws a square on the board
	// Point Provided is the Upper Left Corner of the Square
	// Dimensions are 175 x 175 Pixels

	gfx_line(xCoord, yCoord, xCoord + 150, yCoord); // Top Line
	gfx_line(xCoord + 150, yCoord, xCoord + 150, yCoord + 150); // Right Line
	gfx_line(xCoord, yCoord + 150, xCoord + 150, yCoord + 150); // Bottom Line
	gfx_line(xCoord, yCoord, xCoord, yCoord + 150); // Left Line

	for (int i = yCoord; i < (yCoord + 150); i++){ // Fill the Square

		gfx_line(xCoord, i, xCoord + 150, i);

	}
}

// Function to Copy Board 1 to Board 2
void copyBoard(int board1[4][4], int board2[4][4]){

	for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

			board2[yCoord][xCoord] = board1[yCoord][xCoord];

		}
	}
}

game::game(){

	// Fills the board with 0's, which are the default value
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
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

	// Set Basic Variables
	int width = 725;	// Width
	int height = 725;	// Height
	char c;				// Keyboard Input
	int event;

	// Open a New Window for Drawing
	gfx_open(width, height, "2048.cpp");
	print();

	bool movement = false;
	bool add = false;

	while (c != 27){

		// Play game
		event = gfx_event_waiting();

		if (event){
			c = gfx_wait();
			if (event == 2){
				if ((c != 'w') and(c != 'a') and(c != 's') and(c != 'd') and(c != 27)){
					continue;
				}

				movement = moveSquares(c);
				add = addSquares(c);
				moveSquares(c);

				if (movement || add){
					addRandomSquare();
				}

				print();

			}
		}
	}
}


bool game::moveSquares(char dir){ // Function to Compress All Current Squares to a Single Side

	// Decalre Variables
	int temp[4][4];
	copyBoard(board, temp);

	switch (dir){

	case 'w': // Up

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

			while (count < 4){
				board[count++][xCoord] = 0;
			}

		}

		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;
		
		break;


	case 's': // Down

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


			while (count >= 0){
				board[count--][xCoord] = 0;
			}
		}

		
		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;


	case 'a': // Left

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

			while (count < 4){
				board[yCoord][count++] = 0;
			}

		}

		
		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;

	case 'd': // Right

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


			while (count >= 0){
				board[yCoord][count--] = 0;
			}
		}

		
		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;
	}

	return true;
}

bool game::addSquares(char dir){

	// Decalre Variables
	int temp[4][4];
	copyBoard(board, temp);

	switch (dir){

	case 'w': // Up

		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Add Things, Prioritizing Lower Index Values

				if (board[yCoord][xCoord] == board[yCoord + 1][xCoord]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord + 1][xCoord] = 0;
				}
			}
		}

		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;

	case 's': // Down

		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 3; yCoord >= 0; yCoord--){ // Add Things, Prioritizing Lower Higher Values

				if (board[yCoord][xCoord] == board[yCoord - 1][xCoord]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord - 1][xCoord] = 0;
				}
			}
		}

		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;


	case 'a': // Left

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Each Row

			for (int xCoord = 0; xCoord < 4; xCoord++){ // Add Things, Prioritizing Lower Index Values

				if (board[yCoord][xCoord] == board[yCoord][xCoord + 1]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord][xCoord + 1] = 0;
				}
			}
		}

		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;


	case 'd': // Right

		for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Each Row

			for (int xCoord = 3; xCoord >= 0; xCoord--){ // Add Things, Prioritizing Lower Index Values

				if (board[yCoord][xCoord] == board[yCoord][xCoord - 1]){
					board[yCoord][xCoord] = board[yCoord][xCoord] * 2;
					board[yCoord][xCoord - 1] = 0;
				}
			}
		}

		// Check If New Arrays are Same as Old Arrays
		for (int xCoord = 0; xCoord < 4; xCoord++){ // Go Through Each Column

			for (int yCoord = 0; yCoord < 4; yCoord++){ // Go Through Every Row

				if (board[yCoord][xCoord] != temp[yCoord][xCoord]){ // If Board has changed, return true
					return true;
				}
			}
		}

		return false;

		break;
	}
}

void game::addRandomSquare(){
	// TODO: Fix this
	srand(time(NULL));

	while (true){

		// Randomize a Location
		int xCoord = rand() % 3;
		int yCoord = rand() % 3;
		bool found = false;
		if (board[yCoord][xCoord] == 0){
			board[yCoord][xCoord] = 2;
			found = true;
			break;
		}
		if (not found){
			cout << "END OF GAME" << endl;
			break;
		}
	}
}

void game::print(){

	/** COMMAND LINE GRAPHICS (USED FOR TESTING)
			cout << "_________________\n";
			for (int i = 0; i < 4; i++){
			cout << "| ";
			for (int j = 0; j < 4; j++){
			cout << board[i][j] << " ";
			}
			cout << "|\n";
			}
			cout << "_________________\n";
			cout << "Max score: " << maxScore << endl;

			**/

	// COLORS FOR ALL 2048 TILES
	// Background: rgb(187,173,160)
	// Empty Square: rgb(205,192,180)
	// 2 Square: rgb(238,228,218)
	// 4 Square: rgb(237,224,200)
	// 8 Square: rgb(242,177,121)
	// 16 Square: rgb(245,149,99)
	// 32 Square: rgb(246,124,95)
	// 64 Square: rgb(246,94,59)
	// 128 Square: rgb(237,207,114)
	// 256 Square: rgb(237,204,97)
	// 512 Square: rgb(237,200,80)
	// 1024 Square: rgb(237,197,63)
	// 2048 Square: rgb(237,194,46)
	// 4096++ Square: rgb(60,58,50)

	// Clear Screen
	gfx_clear_color(187, 173, 160);
	gfx_clear();

	// Place Boxes (Box Dimension 225 x 225) (Border Thickness 25px)

	XPoint initialPos;
	initialPos.x = 25;
	initialPos.y = 25;
	char theFont[] = "12x24romankana";
	char two[] = "2";
	char four[] = "4";
	char eight[] = "8";
	char sixteen[] = "16";
	char thritytwo[] = "32";
	char sixtyfour[] = "64";
	char onetwentyeight[] = "128";
	char twofiftysix[] = "256";
	char fivehundo[] = "512";
	char thousand[] = "1024";
	char twofoureight[] = "2048";
	// char myText[]
	gfx_changefont(theFont);

	// Draw All Tiles of board On Graphics Window
	for (int i = 0; i < 4; i++){ // xCoord Index

		for (int j = 0; j < 4; j++){ // yCoord Index

			if (board[j][i] == 0){
				gfx_color(205, 192, 180);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				// gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, "0");
			}
			else if (board[j][i] == 2){
				char myText[] = "2";
				gfx_color(238, 228, 218);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, two);
			}
			else if (board[j][i] == 4){
				char myText[] = "4";
				gfx_color(237, 224, 200);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, four);
			}
			else if (board[j][i] == 8){
				char myText[] = "8";
				gfx_color(242, 177, 121);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, eight);
			}
			else if (board[j][i] == 16){
				char myText[] = "16";
				gfx_color(245, 149, 99);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, sixteen);
			}
			else if (board[j][i] == 32){
				char myText[] = "32";
				gfx_color(246, 124, 95);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, thritytwo);
			}
			else if (board[j][i] == 64){
				char myText[] = "64";
				gfx_color(246, 94, 59);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, sixtyfour);
			}
			else if (board[j][i] == 128){
				char myText[] = "128";
				gfx_color(237, 207, 114);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, onetwentyeight);
			}
			else if (board[j][i] == 256){
				char myText[] = "256";
				gfx_color(237, 204, 97);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, twofiftysix);
			}
			else if (board[j][i] == 512){
				char myText[] = "512";
				gfx_color(237, 200, 80);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, fivehundo);
			}
			else if (board[j][i] == 1024){
				char myText[] = "1024";
				gfx_color(237, 197, 63);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, thousand);
			}
			else if (board[j][i] == 2048){
				char myText[] = "2048";
				gfx_color(237, 194, 46);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				gfx_color(0, 0, 0);
				gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, twofoureight);
			}
			else{
				// string x  = "NaN";
				gfx_color(60, 58, 50);
				drawSquare(initialPos.x + (i * 175), initialPos.y + (j * 175));
				// gfx_text(initialPos.x + (i * 175) + 75, initialPos.y + (j * 175) + 75, x);
			}
		}
	}

}
