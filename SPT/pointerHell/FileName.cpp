#include <iostream>
using namespace std;

void main()
{
	int x = 10;
	int y = 20;

	int* px = &x;
	int* py = &y;
	int** ppx = &px;
	int** ppy = &py;
	int*** pppx = &ppx;
	int*** pppy = &ppy;

	int* pz = &x;
	int** ppz = &pz;
	int*** pppz = &ppz;

	pz = *ppx;
	ppz = *pppy;

	***pppz = *pz * **ppx + **ppz - ((**ppx) *= 3);
	cout << ***pppz << " = " << *pz << " * " << **ppx << " + " << **ppz << " - " << **ppx << endl << endl;

	cout << x << " " << y;
}