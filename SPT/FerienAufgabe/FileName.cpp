#include <iostream>
using namespace std;

void main()
{
	char kette[999];
	cout << "Bitte eingabe machen" << endl;
	cin.getline(kette, 999);

	char test;
	test = 65;

	cout << endl;

	for (int x = 0; x <= 25; x++)
	{
		cout << test;
		test++;
	}
	cout << endl << endl;
	int p;

	for (int y = 0; y <= 25; y++) 
	{
		cout << y << ") ";
		for (int x = 0; kette[x] != '\0'; x++)
		{
			if (kette[x] != ' ')
			{
				p = kette[x];
				p = p + y;
				if (p > 90)
				{
					p = p - 26;
				}
				cout << char(p);
			}
			else {
				cout << " ";
			}
			
		}
		cout << endl;
	}
	
}