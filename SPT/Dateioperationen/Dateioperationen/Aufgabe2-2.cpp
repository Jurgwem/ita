#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;

void main() {
	char input[30 + 1];
	int choice;

	cout << "Bitte geben Sie den Dateinamen ein: ";
	cin >> input;
	cout << endl;

	FILE* f = fopen(input, "r");

	if (f == NULL) {
		cout << "Die Datei wurde nicht gefunden, wollen Sie sie erstellen? (1 = JA, 2 = NEIN): ";
		cin >> choice;
		cout << endl;

		if (choice == 1) {
			FILE* f = fopen(input, "w");
			cout << "Die Datei wurde erfolgreich angelegt" << endl;
		}
	}
	else cout << "Die Datei existiert bereits" << endl;
}