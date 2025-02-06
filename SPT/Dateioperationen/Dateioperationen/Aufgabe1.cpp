#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;

void main2() { // Bei Benutzung umbenennen in "main"!
	char input[10];

	cout << "Bitte geben Sie den Dateinamen ein (mit '.txt' Endung): ";
	cin >> input;
	FILE* f = fopen(input, "w");
	if (f == NULL) cout << "ERRROR!! Die Datei konnte nicht erstellt werden" << endl;
	else {
		cout << endl << "Die Datei " << input << " wurde erfolgreich erstellt" << endl;
	}
	int fclose(FILE * f);
}