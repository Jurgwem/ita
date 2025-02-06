#include <iostream>

using namespace std;

int main()
{
    int zahl1;
    int zahl2;
    float rest;
    
    cout << "geben Sie mir einen ganzen Wert" << endl;
    cin >> zahl1;
    
    cout << "geben Sie mir noch einen ganzen Wert" << endl;
    cin >> zahl2;
    
    rest = zahl1 - (zahl1 / zahl2) * zahl2;
    
    if (rest != 0) {
        cout << "Ihre Zahl hat einen restbetrag! Dieser beträgt: " << rest << endl;
    } else {
        cout << "Ihre Zahl hat KEINEN restbetrag" << endl;
    }
    
    return 0;
}