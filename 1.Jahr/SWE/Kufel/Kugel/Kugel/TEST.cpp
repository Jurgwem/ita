#include <iostream>

using namespace std;

void main()
{
    int input;
    int quersumme;

    cout << "Bitte geben Sie eine Zahl ein" << endl;
    cin >> input;
       
    while (input > 0) {
        quersumme += input % 10;
        input /= 10;
    }

    cout << quersumme << endl;

    system("pause");
}
