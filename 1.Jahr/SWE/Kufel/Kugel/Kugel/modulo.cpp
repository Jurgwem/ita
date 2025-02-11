#include <iostream>

using namespace std;

int main()
{
    int a1;
    int a2;

    cout << "1. Zahl bitte eingeben" << endl;
    cin >> a1;

    cout << "2. Zahl bitte eingeben" << endl;
    cin >> a2;


    if (!((a1 + a2) % 5)) {
        if (a1 > a2) {
            if ((a1 * a2) > 100) {
                cout << "Zahlen sind OK" << endl;
            }
            else {
                cout << "Das Produkt der Zahlen ist nicht groeßer als 100" << endl;
            }
        }
        else {
            cout << "Die erste zahl ist nicht groeßer als die Zweite" << endl;
        }
    }
    else {
        cout << "Die Summe ist nicht durch 5 teilbar" << endl;
    }

    system("pause");
}