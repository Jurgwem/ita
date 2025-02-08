#include <iostream>

using namespace std;

int mai4()
{
    float z1;
    float z2;
    float z3;
    float low;
    float high;


    cout << "1. Zahl bitte eingeben" << endl;
    cin >> z1;

    cout << "2. Zahl bitte eingeben" << endl;
    cin >> z2;


    low = z2;
    high = z1;

    if (z1 < z2) {
        low = z1;
        high = z2;
    }

    cout << "3. Zahl bitte eingeben" << endl;
    cin >> z3;


    if (z3 > high) {
        high = z3;
    }
    if (low > z3) {
        low = z3;
    }


    cout << "Minimum: " << endl;
    cout << low << endl;
    cout << "Maximum: " << endl;
    cout << high << endl;

    system("pause");
}