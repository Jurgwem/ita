// Online C++ compiler to run C++ program online
using namespace std;
#include <iostream>

float rechner(float kap, int year){
    float zinssatz;
    
    if(year >= 11 || year <= 0) {
        return -1;
    }
    
    for (int a = 1; a <= year; a++) {
        switch(a){
            case 1:
                zinssatz = 1.5;
                break;
            case 2:
                zinssatz = 1.75;
                break;
            case 3:
                zinssatz = 2;
                break;
            case 4:
                zinssatz = 2.25;
                break;
            case 5:
                zinssatz = 2.5;
                break;
            case 6:
                zinssatz = 2.75;
                break;
            case 7:
                zinssatz = 2.75;
                break;
            case 8:
                zinssatz = 3;
                break;
            case 9:
                zinssatz = 3;
                break;
            case 10:
                zinssatz = 3;
                break;
            default:
                zinssatz = 0;
                break;
        }
        kap = kap + (kap * (zinssatz / 100));
    }
    return kap;
}

int main() {
    float kapital;
    int years;
    
    cout << endl;
    cout << "Bitte geben Sie Ihr Startkapital und Ihre Jahre ein." << endl;
    cin >> kapital >> years;
    
    if (rechner(kapital, years) == -1) {
        cout << "Fehler" << endl;
    } else {
        cout << rechner(kapital, years) << endl;
    }
    
    

    return 0;
}