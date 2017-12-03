// 2048 Main executable

// Noah Yoshida & Allen Duong
// Last edited: Dec 1 2017
#include "game.h"
#include "gfx.h"
#include <iostream>

using namespace std;

int main(){

	system("clear");
	cout << "Press ESC Key to Exit the Game!" << endl;

	game g;
	g.play();

	return 0;
}
