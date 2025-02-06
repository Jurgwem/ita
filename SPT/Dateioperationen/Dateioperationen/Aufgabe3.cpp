#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
using namespace std;

void main() {
	std::locale de_DE("de_DE.UTF-8");
	
	cout << "ich mache jetzt auf" << endl;
	FILE* f;
	f = fopen("test.txt", "rb");
	
	system("pause");
	cout << "ich mache jetzt zu" << endl;
	fclose(f);
	system("pause");
}