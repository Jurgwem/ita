#include <iostream>
using namespace std;

int player(char player)
{
	char p;
	int input;

	if (player == '*')
	{
		p = 'A';
	}
	else
	{
		p = 'B';
	}

	cout << "Spieler " << p << " ist an der Reihe" << endl;	//Eingabe von Spieler A
	cout << "Wohin geht die Reise, Reise? (1-6)" << endl;
	cin >> input;
	input--;

	return input;
}