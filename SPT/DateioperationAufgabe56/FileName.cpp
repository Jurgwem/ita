#include <iostream>
#include <cstdio>
using namespace std;
#pragma warning(disable : 4996)

int main()
{
    //Anlegung/Initialisierung von Variablen
    char dateiname[255 + 1];
    char zeile[255 + 1];
    int mitarbeiterAnzahl = 0;

    int erweitern = 1;
    //Dateinamen und -pfad Eingabe in "dateiname"
    cout << "Bitte geben Sie den Dateinamen ein (mit .txt-Endung): ";
    cin >> dateiname;
    do
    {
        mitarbeiterAnzahl = 0;
        // Der Zeiger zeigt auf die Datei und zeigt auf das erste Zeichen, im Lesemodus
        FILE* datei = fopen(dateiname, "r+");
        if (datei == nullptr)
        {  // Falls die Datei nicht göffnet werden kann, wird ein fehler Code ausgegeben
            cout << "Fehler beim Öffnen der Datei!" << endl;
            return 1;
        }

        // Jede Zeile wird ausgegeben (max 256 Zeichen), wird wiederholt bis nullptr, aka Ende der Datei
        // Bei jeder wiederholung wird der counter "mitarbeiteranzahl" um 1 erhöht
        cout << "Die Namen in der Datei sind:" << endl;
        while (fgets(zeile, 256, datei) != nullptr)
        {
            cout << zeile;
            mitarbeiterAnzahl++;
        }


        // Ausgabe der Mitarbeiteranzahl
        cout << "Die Anzahl der Mitarbeiter in der Datei ist: " << mitarbeiterAnzahl << endl;

    
        cout << "Was moechten Sie tun?" << endl;
        cout << "(1) = Namen hinzufügen" << endl;
        cout << "(2) = Namen suchen & bearbeiten" << endl;
        cout << "(3) = exit" << endl;
        cin >> erweitern;

        if (erweitern == 1)
        {
            cin.ignore();
            char eingabe[255 + 1];

            cout << "Wie lautet der Name, der Hinzugefeugt werden soll?" << endl;
            cin.getline(eingabe, 255);
            strcat(eingabe, "\n");

            fputs(eingabe,datei);
            // Datei wird geschlossen 
            fclose(datei);
        }
        if (erweitern == 2)
        {
            fclose(datei);
            datei = fopen(dateiname, "r+");
            cin.ignore();
            cout << "Wie lautet der Name den Sie bearbeiten möchten?" << endl;
            char eingabe[255 + 1];
            cin.getline(eingabe, 255);
            strcat(eingabe, "\n");



            while (fgets(zeile, 256, datei) != nullptr) {
                if (zeile == eingabe)
                {
                    cout << "PENIS" << endl;
                    break;
                }
                else
                {
                    cout << "suche nach: " << eingabe << "nicht gefunden: " << zeile << endl;
                }
            }
            cout << "Wie lautet der lautet der Neue Name? " << endl;
            cin.getline(eingabe, 255);
            strcat(eingabe, "\n");
            fputs(eingabe, datei);
        }
        

        

        } while (erweitern == 1 || erweitern ==  2 );
        system("pause");
        return 0;
}
//FUNKTIONSWEISE
//Das Program fragt nach einen Dateinamen/-pfad und gibt daraufhin alle darin
//beinhalteten Zeilen aus (mit einer max. länge von 256 Zeichen pro Zeile)
//Zum Schluss gibt es noch die Anzahl aller Zeilen bzw. aller Mitarbeiter aus