#include <iostream>
#include <string>
using namespace std;

void print_board(int rows, int cols, char board[][6]) {	
	string autor = "Leander Weiss, Roman Frigger";
	string datum = "13.03.2024 - noch in Arbeit";
	string thema = "Prokejtarbeit SWE - 3 Gewinnt";
	string version = "2.0 (Mit KI)";

	system("cls");

	cout << "Autoren: " << autor << endl;
	cout << "Datum: " << datum << endl;
	cout << "Thema: " << thema << endl;
	cout << "Version: " << version << endl;
	cout << endl;

	for (int i = 0; i < cols; i++) {
		cout << "   " << i + 1 << "";
	}

	cout << endl;


	for (int i = 0; i < rows; i++) {
		for (int x = 0; x < cols; x++) {
			cout << " | " << board[i][x];
			if (x == cols - 1) {
				cout << " |";
			}
		}
		cout << endl << endl;
	}
}