#include <iostream>
using namespace std;

void main()
{
	int eingabe1;
	int eingabe2;

	cout << "Bitte geben Sie Zahl 1 ein" << endl;
	cin >> eingabe1;

	cout << "Bitte geben Sie Zahl 2 ein" << endl;
	cin >> eingabe2;

	int* pArray;
	pArray = new int[eingabe1 * eingabe2];

	for (int x = 0; x < eingabe1; x++) 
	{
		for (int y = 0; y < eingabe2; y++)
		{
			*(pArray + x * eingabe2 + y) = y;
			cout << *(pArray + x * eingabe2 + y);
		}
		cout << endl;
	}
}