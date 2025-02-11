#include <iostream>

using namespace std;

int mai3()
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


    //jank episode 1
    high = z1 * ((z1 / z2) > 0 ? 1 : 0) + z2 * ((z2 / z1) > 0 ? 1 : 0);
    low = ((z1 + z2) - sqrt((z1 - z2) * (z1 - z2))) / 2;


    cout << "3. Zahl bitte eingeben" << endl;
    cin >> z3;
    

    //jank episode 2
    high = high * ((high / z3) > 0 ? 1 : 0) + z3 * ((z3 / high) > 0 ? 1 : 0);
    low = ((low + z3) - sqrt((low - z3) * (low - z3))) / 2;


    cout << "Minimum: " << endl;
    cout << low << endl;
    cout << "Maximum: " << endl;
    cout << high<< endl;

    system("pause");
}