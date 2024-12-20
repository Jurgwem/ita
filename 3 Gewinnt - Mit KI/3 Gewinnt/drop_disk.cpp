#include <iostream>
using namespace std;

#include "error.h";

void drop_disk(int p, char p1, char p2, int move, char board[][6]) {
	int set = move - 1;

	if (p == 1) {
		for (int i = 4; i >= 0; i--) {
			if (board[i][set] == ' ') {
				board[i][set] = p1;
				break;
			}
		}
	}
	else if (p == 2) {
		for (int i = 4; i >= 0; i--) {
			if (board[i][set] == ' ') {
				board[i][set] = p2;
				break;
			}
		}
	}
	else {
		error("Fehler, Bitte neu starten", 1);
	}
}