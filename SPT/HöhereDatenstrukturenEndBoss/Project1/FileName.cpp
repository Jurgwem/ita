/*####################
  # Erstellt von:    #
  # Cornie Schmitt   #
  # Nico Bresinski   #
  # Leander Weilss   #
  # Gianluca Herzer  #
  ####################*/
 
#include<windows.h>
#include<iostream>
using namespace std;


struct TKnoten
{
    char Inhalt[50 + 1];
    int tiefe = 0;
    TKnoten* Rechts;
    TKnoten* Links;
};

int vert = 1;
int horz = 0;
const int WIDTH = 80;

int menu(TKnoten* Aktuell)
{
    cout << "Handle of the Fenster" << endl;
    cout << endl;
    cout << "\t\t" << Aktuell->Inhalt;
    cout << endl;

    if (Aktuell->Links) cout << "\t" << Aktuell->Links->Inhalt;
    else cout << "\t Vater?";


    if (Aktuell->Rechts) cout << "\t\t" << Aktuell->Rechts->Inhalt;
    else cout << "\t\t Mutter?";

    cout << endl;
    cout << "<0> Zur Wurzel gehen" << endl;
    if (Aktuell->Links) cout << "<1> Weitergehen zum Vater" << endl;
    else cout << "<1> Eingabe des Vaters" << endl;

    if (Aktuell->Rechts) cout << "<2> Weitergehen zur Mutter" << endl;
    else cout << "<2> Eingabe der Mutter" << endl;

    cout << "<3> Automatisches Ausfuellen" << endl;
    cout << "<4> Ausgabe des Stammbaums" << endl;
    cout << "<5> Ende" << endl;

    cout << "Ihre Eingabe bitte: " << endl;
    int wahl;
    cin >> wahl;

    return wahl;
}

void preAusgabe(TKnoten* Knoten)
{

}

void Ausgabe(TKnoten* Knoten)
{
    TKnoten* tmp;
    tmp = Knoten;
    int counter = 0;

    while (true)
    {
        counter++;
        Knoten->tiefe = counter;
        if (tmp->Rechts == NULL && tmp->Links == NULL)
        {
            break;
        }
        if (tmp->Rechts != NULL)
        {
            tmp = tmp->Rechts;
            continue;
        }
        if (tmp->Links != NULL)
        {
            tmp = tmp->Links;
            continue;
        }
        else
        {
            tmp->tiefe = counter;
        }
    }
    cout << Knoten->Inhalt << " = " << Knoten->tiefe << endl;
    //Struktur für eine Koordinate
    COORD pos;

    //Handle auf die Standardausgabe
    HANDLE standardOut;
    standardOut = GetStdHandle(STD_OUTPUT_HANDLE);


    //Koordinaten setzen   


    if (Knoten->Rechts != NULL)
    {
        pos.X = WIDTH + (vert * 4);
    }
    else if (Knoten->Links != NULL)
    {
        pos.X = WIDTH - (vert * 4);
    }

    vert = (Knoten->tiefe * (-1)) + 4;
    //pos.X = WIDTH;
    pos.Y = vert;

    SetConsoleCursorPosition(standardOut, pos); //2

    cout << Knoten->Inhalt << endl;

    if (Knoten->Links != NULL)
    {
        Ausgabe(Knoten->Links);
    }

    if (Knoten->Rechts != NULL)
    {
        Ausgabe(Knoten->Rechts);
    }

}

void Loeschen(TKnoten* Knoten)
{
    if (Knoten->Links != NULL) Loeschen(Knoten->Links);
    if (Knoten->Rechts != NULL) Loeschen(Knoten->Rechts);

    cout << "Es wird geloescht: " << Knoten->Inhalt << endl;
    if (Knoten != NULL) delete Knoten;
}

void main()
{
    TKnoten* Wurzel;
    TKnoten* Knoten;
    int wahl;

    Wurzel = new TKnoten;
    Wurzel->Rechts = NULL;
    Wurzel->Links = NULL;

    cout << "Bitte Wurzelinhalt eingeben: ";
    cin >> Wurzel->Inhalt;

    Knoten = Wurzel;

    do
    {
        wahl = menu(Knoten);

        switch (wahl)
        {
        case 0:
            Knoten = Wurzel;
            break;

        case 1:
            if (Knoten->Links) Knoten = Knoten->Links;
            else
            {
                Knoten->Links = new TKnoten;
                cout << "Eingabe des Vaters: ";
                cin >> Knoten->Links->Inhalt;
                Knoten->Links->Links = NULL;
                Knoten->Links->Rechts = NULL;
            }
            break;

        case 2:
            if (Knoten->Rechts) Knoten = Knoten->Rechts;
            else
            {
                Knoten->Rechts = new TKnoten;
                cout << "Eingabe der Mutter: ";
                cin >> Knoten->Rechts->Inhalt;
                Knoten->Rechts->Links = NULL;
                Knoten->Rechts->Rechts = NULL;
            }
            break;


        case 3:
            Knoten = Wurzel;
            strcpy_s(Knoten->Inhalt, "Hans");
            Knoten->Links = new TKnoten;
            strcpy_s(Knoten->Links->Inhalt, "Fred");
            Knoten->Rechts = new TKnoten;
            strcpy_s(Knoten->Rechts->Inhalt, "Else");

            Knoten->Links->Links = new TKnoten;
            strcpy_s(Knoten->Links->Links->Inhalt, "Opa Fred");
            Knoten->Links->Rechts = new TKnoten;
            strcpy_s(Knoten->Links->Rechts->Inhalt, "Oma Fred");

            Knoten->Rechts->Links = new TKnoten;
            strcpy_s(Knoten->Rechts->Links->Inhalt, "Opa Else");
            Knoten->Rechts->Rechts = new TKnoten;
            strcpy_s(Knoten->Rechts->Rechts->Inhalt, "Oma Else");

            Knoten->Links->Links->Links = NULL;
            Knoten->Links->Links->Rechts = NULL;
            Knoten->Links->Rechts->Links = NULL;
            Knoten->Links->Rechts->Rechts = NULL;

            Knoten->Rechts->Links->Links = NULL;
            Knoten->Rechts->Links->Rechts = NULL;
            Knoten->Rechts->Rechts->Links = NULL;
            Knoten->Rechts->Rechts->Rechts = NULL;

            break;

        case 4:
            system("cls");
            Ausgabe(Wurzel);
            int dummy;
            cin >> dummy;
            break;

        }


    } while (wahl != 5);

    Loeschen(Wurzel);
}