#include <iostream>

using namespace std;

int main()
{
    int tag = 0;
    int monat = 0;
    int jahr = 0;
    bool schaltjahr = false;
    bool ok = false;


    do {

        cout << "Bitte geben sie ein Datum ein (Tag Monat Jahr)" << endl;
        cin >> tag >> monat >> jahr;
      
        /* Schaltjahreskontrolle*/
        if (jahr % 4 == 0 && jahr % 100 != 0 || jahr % 4 == 0 && jahr % 100 == 0  && jahr % 400 == 0) {
            schaltjahr = true;
        }
        else {
            schaltjahr = false;
        }

        /*cout << "Schaltjahr = " << schaltjahr << endl;*/

        /* Tageskontrolle */
        if (monat == 2 || monat == 4 || monat == 6 || monat == 9 || monat == 11) {
            if (monat == 2) {
                if (schaltjahr) {
                    if (tag >= 0 && tag <= 29) {
                        ok = true;
                    }
                    else {
                        ok = false;
                    }
                }
                else {
                    if (tag >= 0 && tag <= 28) {
                        ok = true;
                    }
                    else {
                        ok = false;
                    }
                }
            }
            else if (tag >= 0 && tag <= 30) {
                ok = true;
            }
            else {
                ok = false;
            }
        }
        else {
            if (tag >= 0 && tag <= 31) {
                ok = true;
            }
            else {
                ok = false;
            }
        }


        if (!(monat >= 0 && monat <= 12)) { /* Monatskontrolle */
            ok = false;
        }


#   
        if (!ok) {
            cout << "Das Datum ist nicht korrekt" << endl;
        }
        else {
            cout << "Das Datum ist korrekt, hurra!" << endl;
        }
    } while (!ok);



    system("pause");
}
//
// 
// 
// 
//#include <iostream>
//
//using namespace std;
//
//void main()
//{
//    int input;
//    int quersumme = 0;
//
//    cout << "Bitte geben Sie eine Zahl ein" << endl;
//    cin >> input;
//
//    while (input > 0) {
//        quersumme += input % 10;
//        input /= 10;
//    }
//
//    cout << quersumme << endl;
//
//    system("pause");
//}
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
// 
// 
// 
// 
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