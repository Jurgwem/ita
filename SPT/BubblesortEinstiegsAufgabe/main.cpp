#include <iostream>
using namespace std;

void ausgabe(int Werte[], int len)
{
	for (int x = 0; x <= len; x++)
	{
		cout << " " << Werte[x] << " ";
	}
	cout << endl;
}

void bubblesort(int Werte[], int len)
{
	int tmp;
	bool sorted = false;
	bool denkplatte;

	while (!sorted) {
		//ausgabe(Werte, len);
		for (int y = 0; y <= len - 1; y++) {
			if (Werte[y] > Werte[y + 1]) {
				tmp = Werte[y];
				Werte[y] = Werte[y + 1];
				Werte[y + 1] = tmp;
			}
		}
		//EFFIZIENZ
		denkplatte = true;
		for (int x = 0; x <= len - 1; x++) {
			if (Werte[x] > Werte[x + 1]) {
				denkplatte = false;
			}
		}
		if (denkplatte) {
			sorted = true;
		}
	}
}

void main()
{
	int Werte[18] = {6, 3, 7, 9, 1, 187361, 0, -4, 4, 2, 1000, 19, 41, 19, 14, 69, 42, 88};
	int len = 17;

	cout << "unsortiert: " << endl;
	ausgabe(Werte, len);

	bubblesort(Werte, len);
	
	cout << "sortiert: " << endl;
	ausgabe(Werte, len);
	cout << endl;
	system("pause");
}