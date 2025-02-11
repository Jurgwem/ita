/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main ()
{
  char antwort;
  float k;
  float z;
  float p;
  float ergebnis;

  cout << "Bitte geben Sie an, was Sie berechnen wollen:" << endl;
  cout << "k = Kapital" << endl;
  cout << "z = Zinsen" << endl;
  cout << "p = Prozentsatz" << endl;
  cin >> antwort;

  if (antwort == 'k')
    {				//Berechnung Kapital
    
      cout << "Bitte geben Sie Ihre Zinsen ein:" << endl;
      cin >> z;
      cout << "Bitte geben Sie Ihre Prozentsatz ein:" << endl;
      cin >> p;
      ergebnis = z / p * 100;
      cout << "Ihr Ergebnis betrC$gt: " << ergebnis << endl;

    }
  else if (antwort == 'z')
    {				//Berechnung Zinsen
    
      cout << "Bitte geben Sie Ihr Kapital ein:" << endl;
      cin >> k;
      cout << "Bitte geben Sie Ihre Prozentsatz ein:" << endl;
      cin >> p;
      ergebnis = k * p / 100;
      cout << "Ihr Ergebnis betrC$gt: " << ergebnis << endl;

    }
  else if (antwort == 'p')
    {				//Berechnung Prozentsatz

      cout << "Bitte geben Sie Ihr Kapital ein:" << endl;
      cin >> k;
      cout << "Bitte geben Sie Ihre Zinsen ein:" << endl;
      cin >> z;
      ergebnis = z * 100 / k;
      cout << "Ihr Ergebnis: " << ergebnis << endl;

    }
  else
    {   //Fehler

      cout << "Falsche Antwort, Fehler!" << endl;

    }
  return 0;
}
