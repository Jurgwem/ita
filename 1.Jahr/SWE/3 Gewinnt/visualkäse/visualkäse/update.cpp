#include <iostream>
using namespace std;


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