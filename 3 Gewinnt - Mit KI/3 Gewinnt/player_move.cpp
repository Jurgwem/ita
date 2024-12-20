#include <iostream>
using namespace std;

#include "drop_disk.h";
#include "error.h";

int player_move(int p, char p1, char p2, int cols, char board[][6]) {
	int move;

	cout << "Spieler " << p << " ist am Zug" << endl;
	cout << "Dein Zug: ";
	cin >> move;
	cout << endl;

	int set = move - 1;

	if (move <= cols && move > 0) {
		drop_disk(p, p1, p2, move, board);
	}
	else {
		error("Fehlerhafte Eingabe", 0);
	}

	return set;
}