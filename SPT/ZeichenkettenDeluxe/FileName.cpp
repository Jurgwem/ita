#include<iostream>
using namespace std;

bool palindrom(char k[], int l)
{
	int length = l;
	bool ergebnis = true;
	length--;

	for (int i = 0; i <= length; i++)
	{
		if (k[i] != k[length - i]) {
			ergebnis = false;
			break;
		}
	}
	return ergebnis;
}

void strUmdrehen(char k[], int l)
{
	char tmp;
	int length = l;

	length--;

	for (int i = 0; i <= length / 2; i++)
	{
		tmp = k[length - i];
		k[length - i] = k[i];
		k[i] = tmp;
	}
}

long char2int(char k[], int l)
{
	long result = 0;
	int factor = 1;
	int length = l;
	int tmp;
	length--;

	for (int x = length; x >= 0; x--)
	{
		if ((k[x] == '0') ||
			(k[x] == '1') ||
			(k[x] == '2') ||
			(k[x] == '3') ||
			(k[x] == '4') ||
			(k[x] == '5') ||
			(k[x] == '6') ||
			(k[x] == '7') ||
			(k[x] == '8') ||
			(k[x] == '9'))
		{
			tmp = k[x] - '0';
			//cout << "num: " << tmp << " " << "fac: " << factor << " " << "comb: " << (factor * tmp) << endl;
			result = result + (factor * tmp);
			factor = factor * 10;
		}
	}
	return result;
}

void StrErsetze(char k[], int l, char alt[], char neu[])
{
	int length = l;
	length--;

	int altLength = 0;
	for (int i = 0; alt[i] != '\0'; i++)
	{
		altLength++;
	}
	altLength--;

	for (int x = 0; x <= altLength; x++)
	{
		for (int y = 0; y <= length; y++)
		{
			if (k[y] = alt[x])
			{

			}
		}
	}
}

void main()
{
	char Kette[999];
	int length = 0;

	cout << "Bitte geben Sie etwas ein" << endl;
	cin.getline(Kette, 999);
	cout << endl;

	for (int i = 0; Kette[i] != '\0'; i++)
	{
		length++;
	}

	if (palindrom(Kette, length))
	{
		cout << "Die Zeichenkette ist ein Palindrom" << endl << endl;
	}
	else {
		cout << "Die Zeichenkette ist kein Palindrom" << endl << endl;
	}

	cout << "Umgedreht: " << endl;
	strUmdrehen(Kette, length);
	cout << Kette << endl << endl;
	strUmdrehen(Kette, length);

	cout << "Nur Zahlen: " << endl;
	cout << char2int(Kette, length) << endl << endl;


	char alt[999];
	char neu[999];

	cout << "Bitte geben Sie ein, welchen Teil Sie ersetzen wollen" << endl;
	cin.getline(alt, 999);
	cout << endl;
	cout << "Mit was soll es ersetzt werden?" << endl;
	cin.getline(neu, 999);
	cout << endl;

	StrErsetze(Kette, length, alt, neu);
	cout << Kette;
}