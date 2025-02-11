#include <iostream>

using namespace std;

int main()
{
	int w1, w2, w3, w4;
	int ergebnis = 0;
	cout << "Bitte geben Sie die 4 Weichen ein: " << endl;
	cin >> w1 >> w2 >> w3 >> w4;

	if (w1 == 1 && w2 == 1 || w1 == 1 && w2 == 0 && w4 == 1 || w1 == 0 && w3 == 1 && w4 == 1) {
	    ergebnis = 1;
	}

	cout << "Die Kugel landet im Ausgang: " << ergebnis << endl;

	return 0;
}