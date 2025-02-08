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
//#include <iostream>
//
//using namespace std;
//
//void main()
//{
//    int input;
//    int tmp = 0;
//
//    cout << "Bitte geben Sie eine Zahl zum hinzählen ein!" << endl;
//    cin >> input;
//
//    do {
//        tmp++;
//        if (!(tmp % 2)) {
//            cout << tmp << endl;
//        }
//
//    } while (tmp != input);
//
//
//    system("pause");
//}


//#include <iostream>
//
//using namespace std;
//
//void main2()
//{
//    int input;
//    do
//    {
//        cout << "Bitte geben Sie die geheimzahl ein!" << endl;
//        cin >> input;
//
//    } while ((input < 1 || input > 20) || input == 13);
//
//
//    system("pause");
//}
//
//