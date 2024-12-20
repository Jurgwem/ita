#include <iostream>
using namespace std;

int stringLänge()
{
	char kette[99999];
	int counter = 0;

	cout << "Bitte geben Sie etwas ein." << endl;
	cin.getline(kette,99999);

	for (int x = 0; kette[x] != '\0'; x++)
	{
		counter++;
	}

	return counter;
}

void main()
{
	char kette[5 + 1] = "Hallo";	//5 + 1, da 5 Zeichen +1 Zeichen da am Ende eine Nullerkennung hin muss "\0"

	cout << kette << endl;

	kette[5] = 'X';

	cout << kette << endl;
	system("cls");

	cout << "Länge des Inputs: " << stringLänge() << endl;
}