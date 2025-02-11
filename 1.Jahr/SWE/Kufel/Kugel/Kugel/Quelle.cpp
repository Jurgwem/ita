#include <iostream>

using namespace std;

int main2()
{
	int w1, w2, w3, w4;
	int ergebnis;
	cout << "Bitte geben Sie die 4 Weichen ein: " << endl;
	cin >> w1 >> w2 >> w3 >> w4;

	if (w1 == 0) {
		if (w3 == 1) {
			if (w4 == 1) {
				ergebnis = 1;
			}
			else {
				ergebnis = 0;
			}
		}
		else {
			ergebnis = 0;
		}
	}
	else {
		if (w2 == 1) {
			ergebnis = 1;
		}
		else {
			if (w4 == 1) {
				ergebnis = 1;
			}
			else {
				ergebnis = 0;
			}
		}
	}

	cout << "Die Kugel landet im Ausgang: " << ergebnis << endl;

	return 0;
	system("pause");
}