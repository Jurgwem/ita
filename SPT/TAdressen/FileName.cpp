#include <iostream>
using namespace std;

const int anzahl = 100;

struct TAdressen
{
	char vorname[100 + 1];
	char nachname[100 + 1];
	char strasse[100 + 1];
	char hausnummer[5 + 1];
	char ort[100 + 1];
	char plz[8 + 1];
};
TAdressen Adressen[anzahl];

//NOTIZBLOCK

void ui();


void anlegen()
{
	int index;
	char input[99 + 1];

	cout << "An welcher Position möchten sie schreiben? (0 - 99, -1 für nächste freie Stelle)" << endl;
	cin >> index;

	if (index == -1)
	{
		for (int x = 0; x < anzahl; x++)
		{
			if (Adressen[x].vorname[0] == '\0')
			{
				index = x;
				cout << "Aktuelle Position: " << index << endl << endl;
				break;
			}
		}
	}

	cout << "Was ist Ihr Vorname? (max. 100 Zeichen)" << endl;	//vorname
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(input, 99);
	strcpy_s(Adressen[index].vorname, input);

	cout << "Was ist Ihr Nachname? (max. 100 Zeichen)" << endl;	//nachname
	cin.getline(input, 99);
	strcpy_s(Adressen[index].nachname, input);

	cout << "Was ist Ihre Straße (ohne Hausnummer)? (max. 100 Zeichen)" << endl;	//strasse
	cin.getline(input, 100);
	strcpy_s(Adressen[index].strasse, input);

	cout << "Was ist Ihre Hausnummer? (max. 5 Zeichen)" << endl;	//Hausnummer
	cin.getline(input, 100);
	strcpy_s(Adressen[index].hausnummer, input);

	cout << "Was ist Ihr Ort (ohne PLZ)? (max. 100 Zeichen)" << endl;		//Ort
	cin.getline(input, 100);
	strcpy_s(Adressen[index].ort, input);

	cout << "Was ist Ihre PLZ? (max. 8 Zeichen)" << endl;		//Ort
	cin.getline(input, 100);
	strcpy_s(Adressen[index].plz, input);

	ui();
}

void anzeigen()
{
	for (int index = 0; index <= anzahl - 1; index++)
	{
		cout << "Index: " << index << endl;
		cout << "Name: " << Adressen[index].vorname << " ";
		cout << Adressen[index].nachname << endl;
		cout << "Strasse: " << Adressen[index].strasse << " ";
		cout << Adressen[index].hausnummer << endl;
		cout << "Ort: " << Adressen[index].plz << " ";
		cout << Adressen[index].ort << endl;
		cout << endl << endl;
	}
	system("pause");
	ui();
}

void löschen()
{
	int auswahl;
	cout << "An welcher Position wollen Sie löschen? (0 - 99)" << endl;
	cin >> auswahl;

	strcpy_s(Adressen[auswahl].vorname, "");
	strcpy_s(Adressen[auswahl].nachname, "");
	strcpy_s(Adressen[auswahl].ort, "");
	strcpy_s(Adressen[auswahl].strasse, "");
	strcpy_s(Adressen[auswahl].plz, "");
	strcpy_s(Adressen[auswahl].hausnummer, "");

	ui();
}

void ändern()
{
	int index;
	int eingabe;
	char input[100 + 1];

	cout << "Welche Position möchten sie ändern? (0 - 99)" << endl;
	cin >> index;

	cout << "Was möchten Sie ändern?" << endl << endl;
	cout << "(1) - Vorname" << endl;
	cout << "(2) - Nachname" << endl;
	cout << "(3) - Strasse" << endl;
	cout << "(4) - Hausnummer" << endl;
	cout << "(5) - Ort" << endl;
	cout << "(6) - PLZ" << endl;

	cin >> eingabe;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (eingabe)
	{
	case 1:
		cout << "Bitte geben Sie den neuen Vornamen ein (max. 100 Zeichen)" << endl;
		cin.getline(input, 100);
		strcpy_s(Adressen[index].vorname, input);
		break;

	case 2:
		cout << "Bitte geben Sie den neuen Nachnamen ein (max. 100 Zeichen))" << endl;
		cin.getline(input, 100);
		strcpy_s(Adressen[index].nachname, input);
		break;

	case 3:
		cout << "Bitte geben Sie die neue Strasse ein (max. 100 Zeichen)" << endl;
		cin.getline(input, 100);
		strcpy_s(Adressen[index].strasse, input);
		break;

	case 4:
		cout << "Bitte geben Sie die neue Hausnummer ein (max. 5 Zeichen)" << endl;
		cin.getline(input, 100);
		strcpy_s(Adressen[index].hausnummer, input);
		break;

	case 5:
		cout << "Bitte geben Sie den neuen Ort ein (max. 100 Zeichen)" << endl;
		cin.getline(input, 100);
		strcpy_s(Adressen[index].ort, input);
		break;

	case 6:
		cout << "Bitte geben Sie die neue PLZ ein (max. 8 Zeichen)" << endl;
		cin.getline(input, 100);
		strcpy_s(Adressen[index].plz, input);
		break;


	default:
		break;
	}

	ui();
}

//void sortieren()
//{
//	int eingabe;
//	char tmp[100 + 1];
//	cout << "Nach was wollen Sie sortieren?" << endl;
//	cout << "(1) - Vorname" << endl;
//	cout << "(2) - Nachname" << endl;
//	cout << "(3) - Strasse" << endl;
//	cout << "(4) - Hausnummer" << endl;
//	cout << "(5) - Ort" << endl;
//	cout << "(6) - PLZ" << endl;
//	cout << "(7) - Índex" << endl;
//	cin >> eingabe;
//
//	switch (eingabe)
//	{
//	case 1:	//code
//		int tmp[100][100];
//		int tmp2;
//		for (int x = 0; x <= anzahl - 1; x++)
//		{
//			cout << "index: " << x << endl;
//			for (int y = 0; Adressen[x].vorname[y] != '\0'; y++)
//			{
//				cout << "c_letter: " << Adressen[x].vorname[y] << endl;
//				tmp[x][y] = int(Adressen[x].vorname[y]);
//				cout << "c_letter_trans: " << tmp[x][y] << endl;
//			}
//		}
//		for (int x = 0; x <= anzahl - 1; x++)
//		{
//			for (int z = 0; z <= anzahl - 1; z++) {
//				if (tmp[x][0] > tmp[x + 1][0])
//				{
//
//				}
//			{
//		}
//
//		system("pause");
//		break;
//
//	case 2:
//
//		break;
//
//	case 3:
//
//		break;
//
//	case 4:
//
//		break;
//
//	default:
//		break;
//	}
//	ui();
//}
void ui()
{
	int auswahl;
	system("cls");

	cout << "Bitte wählen Sie aus, was sie machen wollen" << endl;
	cout << "(1) - Anlegen" << endl;
	cout << "(2) - Löschen" << endl;
	cout << "(3) - Ändern" << endl;
	cout << "(4) - Sortieren" << endl;
	cout << "(5) - Anzeigen (debug)" << endl;
	cout << "(6) - Exit" << endl;
	cout << endl << "Ihre Eingabe" << endl;
	cin >> auswahl;

	system("cls");
	switch (auswahl)
	{
	case 1:
		anlegen();
		break;

	case 2:
		löschen();
		break;

	case 3:
		ändern();
		break;

	case 4:
		//sortieren();
		break;

	case 5:
		anzeigen();
		break;

	case 6:
		system("exit");
		break;

	default:
		ui();
		break;
	}
}

void main()
{
	locale::global(locale("German_germany"));
	//EULA
	cout << "Alle angaben MÜSSEN klein geschrieben ODER groß geschrieben sein" << endl;
	system("pause");
	ui();
}