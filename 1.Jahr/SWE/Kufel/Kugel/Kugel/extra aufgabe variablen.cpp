#include <iostream>

using namespace std;

int main()
{
    float netto;
    float anzahl;
    float steuern = 19;
    float summe;
    
    cout << "Bitte geben Sie Ihren Nettopreis an:" << endl;
    cin >> netto;
    
    cout << "Bitte geben Sie Ihre Anzahl der Produkte an: " << endl;
    cin >> anzahl;
    
    
    summe = netto + netto * (steuern / 100);

    cout << "Der Einzel Bruttopreis beträgt: " << summe << endl;
    
    
    summe = netto * anzahl;
    
    cout << "Der Nettopreis beträgt: " << summe << endl;
    
    
    summe = (netto + netto * (steuern / 100)) * anzahl;
    
    cout << "Der Bruttopreis beträgt: " << summe << endl;




    return 0;
}
