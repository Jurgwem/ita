#include <iostream>
using namespace std;

int inputIntoGame(int position, char game[5][6])
{
	for (int z = 4; z >= 0; z--) {	//collision powered by
		if (game[z][position] == ' ') {
			return z;
			break;
		}
	}
	return 69420;
}