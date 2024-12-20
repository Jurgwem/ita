#include <iostream>
using namespace std;

int check_win(int p,char p1, char p2, int rows, int cols, char board[][6]) {
	int win = 0;

	for (int i = 0; i < rows; i++) {
		for (int x = 0; x < cols; x++) {
			if (board[i][x] == p1) {
				if (board[i][x] == board[i][x - 1] && board[i][x] == board[i][x + 1] || board[i][x] == board[i - 1][x] && board[i][x] == board[i + 1][x] || board[i][x] == board[i + 1][x - 1] && board[i][x] == board[i - 1][x + 1] || board[i][x] == board[i - 1][x - 1] && board[i][x] == board[i + 1][x + 1]) {
					win = 1;
				}
			}
			else if (board[i][x] == p2) {
				if (board[i][x] == board[i][x - 1] && board[i][x] == board[i][x + 1] || board[i][x] == board[i - 1][x] && board[i][x] == board[i + 1][x] || board[i][x] == board[i + 1][x - 1] && board[i][x] == board[i - 1][x + 1] || board[i][x] == board[i - 1][x - 1] && board[i][x] == board[i + 1][x + 1]) {
					win = 2;
				}
			}
		}
	}

	return win;
}