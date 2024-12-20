#include <iostream>
using namespace std;

void main()
{
	int Werte[18] = { 6, 3, 7, 9, 1, 187361, 0, -4, 4, 2, 1000, 19, 41, 19, 14, 69, 42, 88 };
	int len = 17;
	int tmp;

	cout << "unsortiert: " << endl;
	for (int z = 0; z <= len; z++)
	{
		cout << " " << Werte[z] << " ";
	}

	for (int x = 0; x <= len; x++) {
		for (int y = 0; y <= len - 1; y++) {
			if (Werte[y] > Werte[y + 1]) {
				tmp = Werte[y];
				Werte[y] = Werte[y + 1];
				Werte[y + 1] = tmp;
			}
		}
	}

	cout << endl;
	cout << "sortiert: " << endl;
	for (int z = 0; z <= len; z++)
	{
		cout << " " << Werte[z] << " ";
	}
}