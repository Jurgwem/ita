#include <iostream>
using namespace std;

#include "drop_disk.h";

void ki_move(int p, int rows, int cols, int pmove, char board[][6]) {
	char p1 = '#';
	char p2 = '*';	
	int move = 0;

	// Spieler am Sieg hindern
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//TODO KI versucht zu gewinnen
			if (board[i][j] == p2) {
				if (board[i][j] == board[i][j + 1]) {
					move = j + 2;
				}
				else if (board[i][j] == board[i - 1][j]) {
					move = j;
				}
			}
			if (board[i][j] == p1) { // Spieler am Gewinnen hindern
				if (j == 0) { // �berpr�fung von Spieler-Gewinnm�glichkeit in der ersten Spalte
					move = pmove + 1;
					if (board[i][j] == board[i - 1][j] && (board[i - 2][j] == ' ' || board[i - 2][j] == p1)) {
						move = j;
					}
					else if (board[i][j] == board[i][j + 1] && (board[i][j + 2] == ' ' || board[i - 2][j] == p1) && board[i + 1][j + 2] != ' ') {
						move = j + 2;
					}
				}
				else if (j > 0 < (rows - 1)) { // �berpr�fung von Spieler-Gewinnm�glichkeit in der Mitte
					move = pmove + 1;
					if (board[i][j] == board[i - 1][j] && (board[i - 2][j] == ' ' || board[i - 2][j] == p1)) {
						move = j;
					}
					/*else if (board[i][j] == board[i][j - 1] && (board[i][j + 1] == ' ' || board[i][j - 1] == p1)) {
						move = j + 1;
					}*/
					else if (board[i][j] == board[i][j + 1] && (board[i][j + 2] == ' ' || board[i][j - 1] == p1) && board[i + 1][j + 2] != ' ') {
						move = j + 2;
					}
				}
				else if (j = rows) { // �berpr�fung von Spieler-Gewinnm�glichkeit in der letzten Spalte
					move = pmove - 1;
					if (board[i][j] == board[i - 1][j] && (board[i - 2][j] == ' ' || board[i - 2][j] == p1)) {
						move = j;
					}
				}
				
				//TODO Alle anderen M�glichkeiten, wie die KI gewinnen kann hinzuf�gen
			}
		}
	}

	move++;
	drop_disk(p, p1, p2, move, board);
}