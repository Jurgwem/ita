#include <iostream>
using namespace std;

struct TListe
{
	char Daten[50 + 1];
	int index;
	TListe* vor;
	TListe* nach;
};

int length = 0;

void newindex(TListe* Kopf) {
	TListe* Laeufer;
	int c = 1;
	Laeufer = Kopf->nach;
	Kopf->index = 0;
	while (1) {
		Laeufer->index = c;
		if (Laeufer->index == length) break;
		Laeufer = Laeufer->nach;
		c++;
	}
}

void del(TListe* Kopf) {
	TListe* Laeufer;

	TListe* nach = Kopf->nach;
	TListe* vor = Kopf->vor;
	TListe* tmp;
	TListe* del;
	Laeufer = Kopf;

	int index;
	cout << "Index: ";
	cin >> index;
	cout << endl;
	if (index != 0) {
		while (Laeufer->index < index) {
			Laeufer = Laeufer->nach;
		}

		tmp = Laeufer;
		del = Laeufer;

		if (del->nach != NULL)
		{
			vor = del->vor;
			tmp = del->nach;
			tmp->vor = vor;
		}
		if (del->vor != NULL)
		{
			nach = del->nach;
			tmp = del->vor;
			tmp->nach = nach;
		}
		delete del;
		length--;
		newindex(Kopf);
	}
}

void andern(TListe* Kopf)
{
	TListe* Laeufer = Kopf;
	TListe* dummy_v = Laeufer->vor;
	TListe* dummy_n = Laeufer->nach;

	int index;
	char input[50 + 1];
	cout << "Wo möchten Sie ändern?" << endl;
	cin >> index;

	for (int x = 0; x <= length; x++)
	{
		if (Laeufer->index == index)
		{
			break;
		}
		Laeufer = Laeufer->nach;
	}
	if (index <= length && index != 0) {
		cout << "gefundener index: " << Laeufer->index << endl;
		cout << "Geben Sie Daten ein " << endl;
		cin >> input;
		cout << endl;
		strcpy_s(Laeufer->Daten, input);
	}
}

void input(TListe* Kopf) {
	TListe* Laeufer, * dummy;
	Laeufer = Kopf; // Laeufer startet

	char input[50 + 1];
	cout << "Gib Daten: ";
	cin >> input;
	cout << endl;
	if (Laeufer->index == length) {
		Laeufer->nach = new TListe;
		dummy = Laeufer->nach;
		dummy->vor = Laeufer;
		dummy->index = length + 1;
		dummy->nach = NULL;
		Laeufer = Laeufer->nach;
	}
	else {
		while (1) {
			Laeufer = Laeufer->nach;
			if (Laeufer->index == length) break;
		}
		Laeufer->nach = new TListe;
		dummy = Laeufer->nach;
		dummy->vor = Laeufer;
		dummy->index = length + 1;
		dummy->nach = NULL;
		Laeufer = Laeufer->nach;
	}
	strcpy_s(Laeufer->Daten, input);
	length++;
}

void show(TListe* Kopf) {
	TListe* Laeufer;
	if (Kopf->nach == NULL) {
		Laeufer = Kopf; // Zurück zum Anfang
	}
	else {
		Laeufer = Kopf->nach;
	}
	if (length > 0) {
		while (1)
		{
			cout << Laeufer->Daten << " - " << Laeufer->index << endl; // Ausgabe der Inhalte
			if (Laeufer->index == length) break;
			Laeufer = Laeufer->nach; // Laeufer geht weiter
		}
	}
	else {
		cout << "Noch keine Daten vorhanden..." << endl;
	}
	system("pause");
}

void ui(TListe* Kopf) {
	TListe* Laeufer;

	int choice;
	system("cls");
	cout << "Bitte wahlen Sie aus" << endl;
	cout << "(1) - Eintragen" << endl;
	cout << "(2) - alles ausspucken" << endl;
	cout << "(3) - löschen" << endl;
	cout << "(4) - ändernung" << endl;
	cout << "DEBUG!!!! Länge: " << length << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		input(Kopf);
		break;

	case 2:
		show(Kopf);
		break;

	case 3:
		del(Kopf);
		break;

	case 4:
		andern(Kopf);
		break;

	default:
		ui(Kopf);
		break;
	}
}

void main() {
	locale::global(locale("German_germany"));

	TListe* Kopf;
	Kopf = new TListe;
	Kopf->vor = NULL;
	Kopf->nach = NULL;
	Kopf->index = 0;

	while (true) {
		ui(Kopf);
	}
}