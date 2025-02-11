#include<iostream>
using namespace std;

int main() 
{
	int array[10]; 
	double summe = 0;
	double avg;
	int min;
	int max;

	for (int x = 0; x <= end(array) - begin(array) - 1; x++)	//User-Input in das Array
	{
		cout << "Bitte geben Sie die Zahl Nr " << x + 1 << " ein" << endl;
		cin >> array[x];
		system("cls");
	}

	for (int x = 0; x <= end(array) - begin(array) - 1; x++)	//Summen Berechnung
	{
		cout << " " << array[x] << " ";
		summe = summe + array[x];
	}
	cout << endl;
	cout << "Die Summe aller Werte betraegt: " << summe << endl;

	min = array[0];
	max = array[0];

	for (int x = 1; x <= end(array) - begin(array) - 1; x++)	//Min und Max berechnung
	{
		if (min > array[x]) {
			min = array[x];
		}
		if (max < array[x]) {
			max = array[x];
		}
	}

	avg = summe / (end(array)-begin(array));	//Durchschnittsberechnung

	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Durchschnitt: " << avg << endl;

	system("pause");
}