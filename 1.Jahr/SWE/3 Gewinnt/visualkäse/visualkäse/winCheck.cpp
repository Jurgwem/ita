#include <iostream>
using namespace std;

int winCheck(char player, char game[5][6])
{
	int gewonnen = 0;
	int counter = 0;

	for (int y = 0; y <= 4; y++) {
		for (int x = 0; x <= 5; x++) {
			if (game[y][x] != ' ') {
				counter++;
			}
			if (game[y][x] == player) {
				if ((game[y][x - 1] == player && game[y][x + 1] == player && x != 0 && x != 5) || (game[y + 1][x] == player && game[y - 1][x] == player && y != 0 && y != 4) || (game[y + 1][x + 1] == player && game[y - 1][x - 1] == player && x != 0 && x != 5 && y != 0 && y != 4) || (game[y + 1][x - 1] == player && game[y - 1][x + 1] == player && x != 0 && x != 5 && y != 0 && y != 4)) {
					if (player == '*') {
						return 1;
					}
					else {
						return 2;
					}
				}
			}
		}
	}
	if (counter == 30) {
		return 3;
	}
	return 0;
}