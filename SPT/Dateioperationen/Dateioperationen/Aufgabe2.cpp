#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;

void main3() {
	std::locale de_DE("de_DE.UTF-8");
	char input[32];
	char combined[32] = "names/";
	int input2 = 0;

	cout << "Bitte geben Sie einen Namen ein: ";
	cin >> input;
	strcat(input, ".txt");
	strcat(combined, input);
	FILE* f = fopen(combined, "r");
	if (f != NULL)
	{
		cout << "Die Datei '" << combined << "' existiert bereits." << endl;
	}
	else {
		cout << "Datei wurde nicht gefunden, möchten Sie diese anlegen? (1 = Ja, 0 = Nein)" << endl;
		cin >> input2;
		if (input2 == 1)
		{
			FILE* f = fopen(combined, "w");
			cout << "Die Datei wurde angelegt mit dem Namen '" << input << "' unter '" << combined << "'" << endl;
		}
	}
	int fclose(FILE * f);
	system("pause");
}