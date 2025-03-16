#include <iostream>
#include <cstdio>
#include <windows.h>    //Damit Umlaute funktionieren
#pragma warning(disable : 4996) // Deaktiviert die Warnung für die Verwendung von fopen

using namespace std;

struct Mitarbeiter {
    char mitarbeiternummer[2048]; // Mitarbeiter-ID als char-Array
    char vorname[2048];
    char nachname[2048];
    char geburtsdatum[2048];
    char telefonnummer[2048];
    char email[2048];
    char strasse[2048]; // Straße
    char hausnummer[2048]; // Hausnummer
    char plz[2048];     // Postleitzahl
    char stadt[2048];   // Stadt
    char land[2048];    // Land
};

int main() {
    SetConsoleOutputCP(CP_UTF8);  
    SetConsoleCP(CP_UTF8);
    //Charset auf UTF-8 umstellen für umlaute

    int eingabe;
    int counter = 0;
    Mitarbeiter mitarbeiter;

    FILE* datei = fopen("mitarbeiter200.dat", "r");

    //Überprüfung ub die Datei geöffnet werden kann
    if (datei == nullptr) {
        cout << "Fehler beim Öffnen der Datei!" << endl;
        return 0;
    }

    cout << "Bitte warten ..." << endl;

    //Zählen, wieviele Einträge in der Datei sind
    while (fread(&mitarbeiter, sizeof(Mitarbeiter), 1, datei) != 0)
    {
        counter++;
    }

    //schließen und neu-öffnen der Datei um den Pointer zurückzusetzen
    fclose(datei);
    datei = fopen("mitarbeiter200.dat", "r");

    //Eingabe mit upper- und lower bounds kontrolle
    do
    { 
        system("cls");
        cout << "Bitte MitarbeiterID eingeben: (1 - " << counter << ")" << endl;
        cin >> eingabe;
    } while (eingabe > counter || eingabe < 1);

    
    //while (fread(&mitarbeiter, sizeof(Mitarbeiter), 1, datei) != 0)
    //so viele Eintrage durchgehen bis wir bei den von der Eingabe sind
    for (int i = 0; i <= eingabe - 1; i++)
    {
        fread(&mitarbeiter, sizeof(Mitarbeiter), 1, datei);
    }
    //Ausgabe des Eintrages
    cout << endl << endl;

    cout << mitarbeiter.mitarbeiternummer << endl;
    cout << mitarbeiter.vorname << endl;
    cout << mitarbeiter.nachname << endl;
    cout << mitarbeiter.geburtsdatum << endl;
    cout << mitarbeiter.telefonnummer << endl;
    cout << mitarbeiter.email << endl;
    cout << mitarbeiter.strasse << endl;
    cout << mitarbeiter.hausnummer << endl;
    cout << mitarbeiter.plz << endl;
    cout << mitarbeiter.stadt << endl;
    cout << mitarbeiter.land << endl;
}