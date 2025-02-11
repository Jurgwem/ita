#include <iostream>

using namespace std;

void main2()
{
    int input;
    int tmp = 0;

    cout << "Bitte geben Sie die geheimzahl ein!" << endl;
    cin >> input;

    {
        tmp++;
        cout >> tmp >> endl;

    } while (tmp != input);


    system("pause");
}
