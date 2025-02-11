#include <iostream>

using namespace std;

void main2()
{
    int input;
    do
    {
        cout << "Bitte geben Sie die geheimzahl ein!" << endl;
        cin >> input;

    } while ((input < 1 || input > 20) || input == 13);


    system("pause");
}
