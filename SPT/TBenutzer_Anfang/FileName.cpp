#include <iostream>
using namespace std;

struct TBenutzer
{
	char name[40 + 1];
	char passwort[40 + 1];
};
TBenutzer Benutzer[5];


void eingabe(int anzahl)
{
	for (int x = 0; x < anzahl; x++)
	{
		cout << "Geben Sie Name ein" << endl;
		cin >> Benutzer[x].name;

		cout << "Geben Sie Passwort ein" << endl;
		cin >> Benutzer[x].passwort;
	}
}

void ausgabe(int anzahl)
{
	for (int x = 0; x < anzahl; x++)
	{
		cout << "'Name' / 'Passwort' von Benutzer: " << x + 1 << endl;
		cout << "'" << Benutzer[x].name << "' / '" << Benutzer[x].passwort << "'" << endl << endl;
	}
}

void main()
{
	eingabe(5);
	cout << endl << endl << endl;
	ausgabe(5);
}