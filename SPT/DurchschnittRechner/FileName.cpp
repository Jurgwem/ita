#include <iostream>
using namespace std;

void main()
{
	int eingabe;
	double avg;
	double ges = 0;

	cout << "Wieviele Werte wolle Sie eingeben?" << endl;
	cin >> eingabe;

	double* pArray;
	pArray = new double[eingabe];

	for (int i = 0; i < eingabe; i++)
	{
		cout << "Bitte geben Sie Zahl " << i + 1 << " ein" << endl;
		cin >> pArray[i];
	}
	ges = pArray[0];
	for (int i = 1; i < eingabe; i++)
	{
		ges += pArray[i];
	}
	avg = ges / eingabe;
	cout << "Durchschnitt: " << avg << endl;
}