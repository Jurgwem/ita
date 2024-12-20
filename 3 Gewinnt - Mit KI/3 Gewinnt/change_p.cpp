#include <iostream>
using namespace std;

int change_p(int p) {
	if (p == 1) p = 2;
	else if (p == 2) p = 1;

	return p;
}