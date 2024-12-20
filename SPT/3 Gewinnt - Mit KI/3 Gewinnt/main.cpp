/*
Autoren: Leander Weiss, Roman Frigger
Datum: 13.03.2024 - noch in Arbeit
Thema: Projektarbeit SWE - 3 Gewinnt
Version: 2.0 (Mit KI)
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "error.h";
#include "drop_disk.h";
#include "print_board.h";
#include "player_move.h";
#include "change_p.h";
#include "check_win.h";
#include "ki_move.h";


void main() {
	locale::global(locale("German_germany"));
	const int board_rows = 5;
	const int board_cols = 6;
	char board[board_rows][board_cols] = {
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '}
	};

	char p1 = '#';
	char p2 = '*';
	int p = 1;
	int win = 0;
	int gamemode;
	int running = 1;
	int pmove = 0;
	
	cout << "(1) Mehrspieler" << endl;
	cout << "(2) Gegen Computer" << endl;
	cout << "Wähle den Spielmodus: ";
	cin >> gamemode;
	cout << endl;

	if (gamemode <= 2 && gamemode >= 1) {
		if (gamemode == 1) { // Mehrspieler Modus
			do { // Gameloop für Mehrspieler
				print_board(board_rows, board_cols, board);
				player_move(p, p1, p2, board_cols, board);
				p = change_p(p);
				win = check_win(p, p1, p2, board_rows, board_cols, board);
			} while (running == 1 && win == 0);

			if (win != 0) {
				print_board(board_rows, board_cols, board);
				cout << endl << "Spieler " << win << " hat gewonnen" << endl;
				system("pause");
			}
		}
		else if (gamemode == 2) { // KI Modus
			do { // Gameloop für KI
				print_board(board_rows, board_cols, board);
				p = 1;
				pmove = player_move(p, p1, p2, board_cols, board);
				win = check_win(p, p1, p2, board_rows, board_cols, board);
				if (win == 1) break;
				p = 2;
				ki_move(p, board_rows, board_cols, pmove, board);
				win = check_win(p, p1, p2, board_rows, board_cols, board);
				if (win == 2) break; 
			} while (running == 1 && win == 0);

			if (win == 1) {
				print_board(board_rows, board_cols, board);
				cout << "Der Spieler hat gewonnen" << endl;
			}
			else if (win == 2) {
				print_board(board_rows, board_cols, board);
				cout << "Der Computer hat gewonnen" << endl;
			}
			else {
				error("Fehler, bitte neustarten", 1);
			}
		}
	}
	else {
		error("Unbekannter Spielmodus", 0);
	}
}