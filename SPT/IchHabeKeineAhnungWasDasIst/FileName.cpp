#include <iostream>
using namespace std;

void quadrieren(float * adresse)	//Aufgabe 1
{
	float tmp = *adresse;
	tmp = tmp * tmp;
	*adresse = tmp;
}

void sortieren(char* eins, char* zwei, char* drei)	//Ausgabe 2
{
	int array[3];
	array[0] = int(*eins);
	array[1] = int(*zwei);
	array[2] = int(*drei);

	int tmp;
	for (int y = 0; y <= 1; y++)
	{ 
		for (int x = 0; x <= 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
			}
		}
	}
	*eins = char(array[0]);
	*zwei = char(array[1]);
	*drei = char(array[2]);
}

void main()
{
	float x;
	float* px = &x; 

	cout << "Bitte gebe Zahl ein" << endl;
	cin >> x;


	quadrieren(px);

	cout << x << endl << endl;

	//Aufgabe 2
	char a, b, c;
	char* pa = &a;
	char* pb = &b;
	char* pc = &c;

	cout << "Bitte geben Sie 3 Buchstaben ein" << endl;
	cin >> a >> b >> c;

	sortieren(pa, pb, pc);

	cout << a << b << c << endl;
}