#include <iostream>
#include <string>
using namespace std;

void error(string msg, int rs) {
	cout << "ERROR: " << msg << "!" << endl;
	system("pause>nul");
	if (rs == 1) {
		exit(42);
	}
}