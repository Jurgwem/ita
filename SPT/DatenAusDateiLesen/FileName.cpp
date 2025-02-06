#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;

void main() {
	std::locale de_DE("de_DE.UTF-8");
	char input[32+1];
	char input3[100+1];
	int length = 0;
	char combined[32] = "names/";
	int input2 = 0;

	cout << "Bitte geben Sie einen Namen ein: ";
	cin >> input;
	strcat(input, ".txt");
	strcat(combined, input);
	FILE* f = fopen(combined, "r");
	if (f != NULL)
	{
		f = fopen(combined, "r");
		int tmp = 0;
		cout << endl << "aktueller Inhalt:" << endl;
		while (tmp != -1)
		{
			tmp = fgetc(f);
			cout << char(tmp);
			//cout << tmp << endl;
		}
		cout << endl << endl;
		cout << "Die Datei '" << combined << "' existiert bereits, moechten Sie diese bearbeiten? (1 = Ja, 0 = Nein)" << endl;
		cin >> input2;
		fclose(f);
		FILE* f = fopen(combined, "w");
		cout << "Geben Sie nun ein, was eingetragen werden soll in die Datei (" << combined << ") (max. 32 Zeichen)" << endl;
		cin >> input3;
		
		while (fgetc(f) != -1)
		{
			cout << fgetc(f) << endl;
		}
		for (int i = 0; i <= 101; i++)
		{
			if (input3[i] == '\0')
			{
				break;
			}
			fputc(input3[i], f);
		}

	}
	else {
		cout << "Datei wurde nicht gefunden, moechten Sie diese anlegen? (1 = Ja, 0 = Nein)" << endl;
		cin >> input2;
		if (input2 == 1)
		{
			fclose(f);
			FILE* f = fopen(combined, "w");
			cout << "Die Datei wurde angelegt mit dem Namen '" << input << "' unter '" << combined << "'" << endl;
			fclose(f);
		}
	}
	system("pause");
}