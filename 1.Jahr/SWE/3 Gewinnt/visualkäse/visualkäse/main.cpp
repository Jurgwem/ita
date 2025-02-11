#include <iostream>
using namespace std;

#include "inputIntoGame.h"
#include "player.h"
#include "update.h"
#include "winCheck.h"

int main()
{
	locale::global(locale("German_germany"));

	int isTrue = 0;
	int KI_brain = 5;
	int KI = 0;
	int currentPlayer = 1;
	char playerA = '*';
	char playerB = '#';
	int input;
	int tmp;

	char game[5][6]
	{
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '}
	};

	do {
		isTrue = 0;
		KI_brain = 5;
		KI = 0;
		currentPlayer = 1;

		for (int y = 0; y <= 4; y++) {
			for (int x = 0; x <= 5; x++) {
				game[y][x] = ' ';
			}
		}
		do {
			system("cls");
			cout << "Hallo Party People" << endl;
			cout << "wählen sie aus: (1-5)" << endl << endl;;
			cout << "(1) = 2-Spieler Spiel" << endl;
			cout << "(2) = Einzelspieler" << endl;
			cout << "(3) = KL Spiel (Künstliche Lögik)" << endl;
			cout << "(4) = Spiel beenden" << endl;
			cin >> input;
		} while (input > 4 || input < 1);

		if (input == 3) {
			KI = 1;
		}
		if (input == 2) {
			KI = 2;
		}
		if (input == 4) {
			return 0;
		}

		do	//GAMEPLAY LOOP
		{
			do {
				update(game);	//Player A Cycle
				input = player(playerA);
				tmp = inputIntoGame(input, game);
			} while (tmp == 69420 || input < 0 || input > 5);

			game[tmp][input] = playerA;
			isTrue = winCheck(playerA, game);
			if (isTrue != 0) {
				break;
			}

			if (KI == 0) {
				update(game);	//Player B Cycle
				do {
					update(game);
					input = player(playerB);
					tmp = inputIntoGame(input, game);
				} while (tmp == 69420 || input < 0 || input > 5);

				game[inputIntoGame(input, game)][input] = playerB;
				isTrue = winCheck(playerB, game);
			}
			if (KI == 1) {
				if (inputIntoGame(KI_brain, game) == 69420) {
					KI_brain--;
				}
				game[inputIntoGame(KI_brain, game)][KI_brain] = playerB;
				isTrue = winCheck(playerB, game);
			}
		} while (isTrue == 0);

		update(game);

		if (isTrue == 1)
		{
			cout << "Spieler A gewinnt." << endl;
		}
		else if (isTrue == 2)
		{
			cout << "Spieler B gewinnt." << endl;
		}
		else
		{
			cout << "Unentschieden... HOW" << endl;
		}
		isTrue = 0;
		system("pause");
	} while (input != 5);
}