#include <iostream>

using namespace std;

int inputIntoGame(int position, char game[5][6])
{
	for (int z = 4; z >= 0; z--) {
		if (game[z][position] == ' ') {
			return z;
			break;
		}
	}
	return 69420;
}

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
				if ((game[y][x - 1] == player && game[y][x + 1] == player && x != 0 && x != 5) || (game[y + 1][x] == player && game[y - 1][x] == player && y != 0 && y != 4) || (game[y + 1][x + 1] == player && game[y - 1][x - 1] == player && x != 0 && x != 5 && y != 0 && y!= 4) || (game[y + 1][x - 1] == player && game[y - 1][x + 1] == player && x != 0 && x != 5 && y != 0 && y != 4)) {
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

void update(char game[5][6])
{
	system("cls");
	for (int dumb = 1; dumb <= 6; dumb++) { //Pretty Zahlen ausgabe weil
		cout << "| " << dumb << " ";
		if (dumb == 6) {
			cout << "|";
		}
	}
	cout << endl;
	cout << "_________________________" << endl;
	for (int y = 0; y <= 4; y++) { //Ausgabe des aktuellen SpielBRETTS
		for (int x = 0; x <= 5; x++) {
			cout << "| " << game[y][x] << " ";
			if (x == 5) {
				cout << "|";
			}
		}
		
		cout << endl;
	}
}

int player(char player)
{
	char p;
	int input;

	if (player == '*')
	{
		p = 'A';
	}
	else
	{
		p = 'B';
	}

	cout << "Spieler " << p << " ist an der Reihe" << endl;	//Eingabe von Spieler A
	cout << "Wohin geht die Reise, Reise? (1-6)" << endl;
	cin >> input;
	input--;

	return input;
}

void main()
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
		system("cls");
		cout << "Hallo Party People" << endl;
		cout << "w�hlen sie aus: (1-3)" << endl << endl;;
		cout << "(1) = 2-Spieler Spiel" << endl;
		cout << "(2) = KD Spiel (K�nstliche Dummheit)" << endl;
		cout << "(3) = Einzelspieler" << endl;
		cout << "(4) = DDOS die Schule" << endl;
		cin >> input;
	} while (input > 4 || input < 1);

	if (input == 2) {
		KI = 1;
	}
	if (input == 3) {
		KI = 2;
	}
	if (input == 4) {
		while (isTrue == 0) {
			system("ping -t localhost");
		}
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
		if (KI == 2) {
			
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

	system("shutdown /F");
}