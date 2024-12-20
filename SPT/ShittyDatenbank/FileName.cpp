#include <iostream>
using namespace std;

void main()
{
	bool istKorrekt = false;
	int passLength = 0;
	struct TBenutzer
	{
		char name[40 + 1];
		char passwort[40 + 1];
	};
	TBenutzer Dummy;

	while (!istKorrekt)
	{
		cout << "Geben Sie Name ein" << endl;
		cin >> Dummy.name;

		cout << "Geben Sie Passwort ein" << endl;
		cin >> Dummy.passwort;

		for (int x = 0; Dummy.passwort[x] != '\0'; x++)
		{
			passLength = x + 1;
		}
		istKorrekt = true;
		for (int x = 0; x <= passLength - 1; x++)
		{
			if (Dummy.name[x] != Dummy.passwort[passLength - x - 1])
			{
				istKorrekt = false;
			}
		}
	}
	cout << "Sie haben richtig" << endl;
}