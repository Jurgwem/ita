#include <iostream>
#include <cstdio> // Für FILE und fopen
#pragma warning(disable : 4996) 
using namespace std;

struct Mitarbeiter
{
	char vorname[50];
	char nachname[50];
	char alter[50];
	char gehalt[50];
};

void einsetzen(FILE* datei, struct Mitarbeiter mitarbeiter)
{
	if (datei != NULL)
	{
		// Daten in die Datei schreiben
		size_t geschrieben = fwrite(&mitarbeiter, sizeof(struct Mitarbeiter), 1, datei);

		if (geschrieben == 1)
		{
			cout << "Daten wurden erfolgreich geschrieben." << endl;
		}
		else
		{
			cout << "Fehler beim Schreiben der Daten." << endl;
		}

	}
	else
	{
		cout << "Fehler beim Öffnen der Datei." << endl;
	}
}

int main()
{
	// Datei im Binärmodus öffnen (zum Schreiben)
	FILE* datei = fopen("datei.bin", "wb");

	// Einzelnes eintrag
	struct Mitarbeiter mitarbeiter1 = { "Hans", "Zimmer", "700", "3,75€"};
	einsetzen(datei, mitarbeiter1);

	struct Mitarbeiter mitarbeiter2 = { "Bob", "Müller", "3", "999999999€" };
	einsetzen(datei, mitarbeiter2);

	return 0;
}