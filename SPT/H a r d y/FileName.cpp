#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


//Sortieren durch Auswahl
void AuswahlSort(int f[], int anz)
{
    int i, stelle, dummy;
    int min;

    for (i = 0; i < anz - 1; i++)
    {

        min = f[i];
        for (int k = i + 1; k < anz; k++)
        {
            if (min > f[k]) { min = f[k]; stelle = k; } //Index merken
        }

        if (min != f[i])
        {
            dummy = f[i];
            f[i] = f[stelle];        // tauschen
            f[stelle] = dummy;
        }
    }
}


//Sortieralgorithmus Bubblesort ohne Optimierung (ohne Abbruch)
void Bubblesort(int f[], int anz)
{
    int hilf;
    for (int i = anz - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
        {
            if (f[j] > f[j + 1])
            {
                hilf = f[j];
                f[j] = f[j + 1];
                f[j + 1] = hilf;
            }
        }
}

//Sortieralgorithmus Bubblesort mit Optimierung (mit Abbruch)
void Bubblesort_Optimiert(int f[], int anz)
{
    int hilf;
    bool tausch;

    for (int i = anz - 2; i >= 0; i--)
    {
        tausch = false;
        for (int j = 0; j <= i; j++)
        {
            if (f[j] > f[j + 1])
            {
                hilf = f[j];
                f[j] = f[j + 1];
                f[j + 1] = hilf;
                tausch = true;
            }
        }
        if (tausch == false) break;
    }
}

//Sortieralgorithmus Gnomesort (eine Bubblesort-Variante, die die Laufrichtung nach dem Tauschen wechselt)
void Gnomesort(int f[], int anz)
{
    int i = 0, temp;
    while (i < anz)
    {
        if (i == 0 || f[i - 1] <= f[i])
        {
            i++;
        }
        else
        {
            temp = f[i];
            f[i] = f[i - 1];
            f[i - 1] = temp;
            i--;
        }
    }
}


// Quicksort aus dem C++ - Unterricht
void QuickSort(int F[], int a, int e)
{
    int mitte = (e + a) / 2;
    int dummy;

    int i = a;
    int j = e;

    while (1)
    {

        for (; F[i] <= F[mitte] && i < mitte; i++);
        for (; F[j] >= F[mitte] && j > mitte; j--);

        if (i == j) break;


        dummy = F[i];
        F[i] = F[j];
        F[j] = dummy;

        if (i == mitte) i = a;
        if (j == mitte) j = e;

    }

    if (a < mitte) QuickSort(F, a, mitte - 1);
    if (mitte < e) QuickSort(F, mitte + 1, e);
}


// Quicksort aus Lehrbuch
void UniQuickSort(int A[], int left, int right)
{
    int i, j; // Laufvariablen
    int item; // Hilfsfeld zum Vertauschen
    int pivot; // Pivot-Element
    if (right > left)
    {
        pivot = A[right]; // Pivot-Element festhalten
        i = left - 1, j = right; // Laufzeiger initialisieren
        for (;;)
        {
            while (A[++i] < pivot); // von links "grosses" Item suchen
            while (A[--j] > pivot); // von rechts "kleines" Item suchen
            if (i >= j) break; // Abbruch,wenn sich Zeiger überholen
            item = A[i]; // grosses u. kleines El. vertauschen
            A[i] = A[j];
            A[j] = item;
        }
        A[right] = A[i]; // Pivotelement auf endgültigen Platz
        A[i] = pivot;
        UniQuickSort(A, left, i - 1); // Teil-Listen getrennt sortieren
        UniQuickSort(A, i + 1, right);
    }
}


// Heapsort-Variante aus Lehrbuch

void Sinken(int A[], int left, int right)
{
    int i, j; // Laufzeiger
    int item; // Hilfsfeld zum Vertauschen zweier Elemente
    i = left; // zeige zur Wurzel
    j = 2 * i; // zeige auf den ersten der Söhne
    item = A[i]; // sinkendes Item zwischenspeichern
    while (j <= right) // wiederhole Sinken
    {
        if (j < right) // den größeren der beiden Söhne feststellen
            if (A[j] < A[j + 1]) j++;
        if (item >= A[j]) // richtiger Platz für das Item gefunden: i
            j = right + 1; // setze Abbruchbedingung für while
        else
        {
            A[i] = A[j]; // laß Nachfolger aufsteigen
            i = j; // zeige auf nächsten "leeren" Platz
            j = 2 * i; // zeige auf den nächsten Sohn
        }
    }
    A[i] = item; // Trage Item auf dem richtigen Platz ein
}

void HeapSort(int A[], int n)
{
    int item;                // Hilfsfeld zum Vertauschen
    int left, right;        // linke, rechte Grenze von Teilbäumen
    left = (n / 2) + 1;    // Zeige hinter den letzten Vaterknoten
    right = n;                // zeige auf rechtes Listenende
    while (left > 0)        // Schleife zum Aufbau des Heap
    {
        left--;                // zeige auf den nächsten Vaterknoten
        Sinken(A, left, right); // laß ihn absinken
    }
    while (right > 0)        // Sortiere jetzt den Heap
    {
        item = A[left];        // tausche Wurzel mit letztem Item
        A[left] = A[right]; // in der Restliste
        A[right] = item;
        right--;            // Restliste verkürzen
        Sinken(A, left, right); // neues Wurzel-Item absinken lassen
    }
}


void bubblesortN(int Werte[], int len) {
    int denkplatte;
    int sorted = false;
    int tmp;

    for (int x = 0; x <= len - 1; x++) {
        //ausgabe(Werte, len);
        for (int y = 0; y <= len - 1; y++) {
            if (Werte[y] > Werte[y + 1]) {
                tmp = Werte[y];
                Werte[y] = Werte[y + 1];
                Werte[y + 1] = tmp;
            }
        }
    }
}

//***********************************************************************************************************************


//Hilfsfunktionen
void Zufall(int f[], int anz)
{
    // initialisiert den Zufallsgenerator
    srand(time(NULL));
    // füllt das Array mit Zufallszahlen
    for (int i = 0; i < anz; i++)
        f[i] = rand() % 1000 + 1;

}

void Kopieren(int d[], int q[], int anz)
{
    for (int i = 0; i < anz; i++)
        d[i] = q[i];

}

int ZeitinMillisekunden()
{
    struct _timeb timebuffer;
    _ftime(&timebuffer);
    return timebuffer.time * 1000 + timebuffer.millitm;
}


//***********************************************************************************************************************




int main()
{
    const int anzahl = 25000;
    int feld[anzahl];
    int kopie[anzahl];
    int vorher, nachher;

    Zufall(kopie, anzahl);




    //Sortieren durch Auswahl
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    AuswahlSort(feld, anzahl);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch AuswahlSort in Millisekunden:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************

    //Bubblesort ohne Abbruch
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    Bubblesort(feld, anzahl);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch Bubblesort in Millisekunden:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************


    //Bubblesort mit Abbruch
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    Bubblesort_Optimiert(feld, anzahl);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch Bubblesort (optimiert) in Millisekunden:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************


    //Gnomesort (Bubblesort-Variante)
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    Gnomesort(feld, anzahl);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch Gnomesort in Millisekunden:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************


    //Quicksort aus Unterricht (Hardy)
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    QuickSort(feld, 0, anzahl - 1);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch Quicksort (Hardy) in Millisekunden:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************


    //Quicksort aus Lehrbuch
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    UniQuickSort(feld, 0, anzahl - 1);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch Quicksort (Lehrbuch) in Millisekunden:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************



    //Heapsort aus Lehrbuch
    //***********************************************************************************************************************
    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    HeapSort(feld, anzahl - 1);
    nachher = ZeitinMillisekunden();
    cout << "Zeitverbrauch Heapsort (Lehrbuch) in Millisekunden:" << nachher - vorher;
    cout << endl << endl;

    Kopieren(feld, kopie, anzahl);
    vorher = ZeitinMillisekunden();
    bubblesortN(feld, anzahl - 1);
    nachher = ZeitinMillisekunden();
    cout << "Nico's Bubblesort:" << nachher - vorher;
    cout << endl << endl;
    //***********************************************************************************************************************
    return 0;
}