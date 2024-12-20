#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(0));
	
	string name[] = { "Nico\t", "Gianluca", "Connie\t", "Serpil\t", "Linus\t",
					   "Alex\t", "Beer\t", "Lysander", "Sascha\t", "Kuzmini\t",
					   "Wahle\t", "Vandermoin", "Hunke\t", "Roemer\t", "Hardy\t", "Leander\t",
					   "Jerke\t", "Joisten\t", };
	int x, y, z;
	int length = end(name) - begin(name);
	string result_l[end(name) - begin(name)];
	string result_r[end(name) - begin(name)];

	bool exists;
	int tmp;

	for (int index = 0; index <= length - 1; index++) {
		do {
			exists = false;
			tmp = 0 + (rand() % length);
			for (int x = 0; x <= length - 1; x++) {
				if (result_l[x] == name[tmp]) {
					exists = true;
					break;
				}
			}
		} while (exists);
		result_l[index] = name[tmp];
	}
	//we do the dumbass shit now
	for (int index = 0; index <= length - 1; index++) {
		do {
			exists = false;
			tmp = 0 + (rand() % length);
			for (int x = 0; x <= length - 1; x++) {
				if (result_r[x] == name[tmp] || name[tmp] == result_r[x]) {
					exists = true;
					break;
				}
			}
		} while (exists);
		result_r[index] = name[tmp];
	}

	for (int x = 0; x <= length - 1; x++) {
		z = 0 + (rand() % 100);
		cout << result_l[x] << "\tx\t" << result_r[x] << " \t passen zu: " << z << "%" << " zusammen" << endl;
	}




	return 0;
}
