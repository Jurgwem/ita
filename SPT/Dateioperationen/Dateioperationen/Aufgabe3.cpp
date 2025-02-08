#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;

void main() { // Bei Benutzung umbenennen in "main"!
	char input[30 + 1];
	char input2[30 + 1];
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
			cout << "Bitte geben Sie an, was in die Datei geschrieben werden soll: ";
			cin >> input2;
			cout << endl;
			for (int i = 0; i < sizeof(input2); i++) {
				fputc(input2[i], f);
			}
			fclose(f);
		}
	}
	else {
		cout << "Die Datei existiert bereits" << endl;
		cout << "Willst du due Datei bearbeiten oder anteigen? (1 = BEARBEITEN, 2 = ANZEIGEN):  ";
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			FILE* f = fopen(input, "w");
			cout << "Bitte geben Sie an, was in die Datei geschrieben werden soll: ";
			cin >> input2;
			cout << endl;
			for (int i = 0; i < sizeof(input2); i++) {
				fputc(input2[i], f);
			}
			fclose(f);
		}
		else if (choice == 2) {
			FILE* f = fopen(input, "r");
			int tmp = 0;
			while (tmp != -1) {
				tmp = fgetc(f);
				cout << char(tmp);
			}
			fclose(f);
		}
	}
}