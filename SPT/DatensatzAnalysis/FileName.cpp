#include<iostream>
using namespace std;

void min(int array[], int length)
{
	system("cls");
	int min = array[0];

	for (int x = 1; x <= length - 1; x++)
	{
		if (min > array[x]) {
			min = array[x];
		}
	}

	cout << "Minimum betraegt: " << min << endl;
	system("pause");
}

void max(int array[], int length)
{
	system("cls");
	int max = array[0];

	for (int x = 1; x <= length - 1; x++)
	{
		if (max < array[x]) {
			max = array[x];
		}
	}

	cout << "Maximum betraegt: " << max << endl;
	system("pause");
}

void durchschnitt(int array[], int length)
{
	system("cls");
	double avg;
	double summe = 0;

	for (int x = 0; x <= length - 1; x++)
	{
		summe += array[x];
	}

	avg = summe / length;

	cout << "Durchschnitt betraegt: " << avg << endl;
	system("pause");
}

void abweichung(int array[], int length)
{
	system("cls");
	double ergebnis = 0;
	double mittelwert = 0;
	double abweichung = 0;

	for (int x = 0; x <= length - 1; x++)
	{
		mittelwert += array[x];
	}

	mittelwert = mittelwert / length;

	for (int x = 0; x <= length - 1; x++)
	{
		abweichung += abs(array[x] - mittelwert);
	}

	ergebnis = abweichung / length;

	cout << "Die mittlere Abweichung betraegt: " << ergebnis << endl;
	system("pause");
}

void haufigkeit(int array[], int length)
{
	int result[5];
	int tmp;
	int count = 0;

	for (int x = 0; x <= 100; x++)
	{
		for (int index = 0; index <= length - 2; index++) {
			if (array[x] < array[x + 1]) {
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
			}
		}
	}
	for (int index = 0; index <= length - 2; index++) {
		cout << " " << array[index] << " ";

	}
	system("pause");
}

void main()
{
	int input;
	bool beenden = false;
	int Werte[100] = { 
			19 , 9 , 6 , 12 , 18 , 7 , 17 , 10 , 16 , 4 ,
			15 , 2 , 23 , 16 , 21 , 27 , 8 , 10 , 2 , 14,
			7 , 5 , 0 , 1 , 5 , 20 , 8 , 7 , 23 , 16 , 28,
			28 , 28 , 19 , 8 , 21 , 20 , 18 , 27 , 19 , 4,
			27 , 4 , 2 , 8 , 19 , 17 , 16 , 6 , 26 , 27 , 8,
			5 , 12 , 19 , 20 , 11 , 7 , 18 , 5 , 0 , 0 , 27,
			27 , 5 , 19 , 19 , 8 , 18 , 4 , 23 , 17 , 19 , 11,
			16 , 26 , 20 , 11 , 17 , 6 , 26 , 23 , 9 , 28 , 6,
			14 , 5 , 11 , 11 , 12 , 13 , 4 , 18 , 19 , 14 , 3,
			26 , 15 , 21 , 23 ,
	};

	do
	{
		cout << "Bitte wählen Sie, was berechnet werden soll: (1-6)" << endl;
		cout << "(1) Minimum berechnen" << endl;
		cout << "(2) Maximum berechnen" << endl;
		cout << "(3) Mittelwert berechnen" << endl;
		cout << "(4) Mittlere Abweichung berechnen" << endl;
		cout << "(5) 5 Werte, die ab meisten vorkommen" << endl;
		cout << "(6) Programm beenden" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			min(Werte, anzahl);
			break;

		case 2:
			max(Werte, anzahl);
			break;

		case 3:
			durchschnitt(Werte, anzahl);
			break;

		case 4:
			abweichung(Werte, anzahl);
			break;

		case 5:
			haufigkeit(Werte, anzahl);
			break;

		case 6:
			beenden = true;
			break;

		default:
			cout << "inkorrekte eingabe" << endl;
			break;
		}
		system("cls");
	} while (!beenden);

	cout << "Programm wurde beendet" << endl;
	system("pause");

}

void old()
{
	int array[10];
	double summe = 0;
	double avg;
	int min;
	int max;

	for (int x = 0; x <= 9; x++)	//User-Input in das Array
	{
		cout << "Bitte geben Sie die Zahl Nr " << x + 1 << " ein" << endl;
		cin >> array[x];
		system("cls");
	}

	for (int x = 0; x <= 9; x++)	//Summen Berechnung
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

	avg = summe / (end(array) - begin(array));	//Durchschnittsberechnung

	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Durchschnitt: " << avg << endl;

	system("pause");
}