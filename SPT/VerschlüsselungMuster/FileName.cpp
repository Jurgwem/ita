#include <iostream>
using namespace std;
void verschlusseln(char verschlüsselung[], char keywort[], char ABC[])
{
	int lange = 0;
	//lange zählen
	do {
		if (keywort[lange] == '\0') {
			break;
		}
		lange++;
	} while (true);
	//doppelte löschen
	for (int i = 0; i < lange; i++) {
		for (int r = i + 1; r < lange; ) {//alle möglichen kobnatinen
			if (keywort[i] == keywort[r]) {//vergleichen ob gleich
				for (int t = r; t < lange; t++) {//wenn ja
					keywort[t] = keywort[t + 1];//alle nach dem buchstaben ein nach links 
				}
				lange--;//lange wird gekürzt
			}
			else {// nein 
				r++;//nächster buchstabe 
			}
		}
	}
	std::cout << "Berreinigte Ausgabe : " << keywort << endl;//Ausgabe
	int langeVerABC = 0, index = 0;
	//Verschlüsseltes ABC
	for (int i = 0; i < lange; i++) {
		verschlüsselung[langeVerABC++] = keywort[i];//keywort wird an den anfanggesetzt
	}
	for (int i = 0; i < 26; i++) {
		index = 0;
		for (int r = 0; r < lange; r++) {
			if (ABC[i] == keywort[r]) {
				index = 1;
				break;
			}
		}
		if (index == 0) {
			verschlüsselung[langeVerABC++] = ABC[i];
		}
	}
	verschlüsselung[langeVerABC] = '\0';

}

int main()
{
	char ABC[26 + 1] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char verschlüsselung[26 + 1], keywort[26 + 1], wort[100];
	std::cout << "bitte wort eingeben" << endl;
	cin >> keywort;
	std::cout << keywort << endl;
	verschlusseln(verschlüsselung, keywort, ABC);
	std::cout << "Verschlüsslungs ABC : " << verschlüsselung << endl;//Ausgabe
	std::cout << "wollen sie entschlüsseln dann drücken sie die eins (1)." << endl;
	std::cout << "wollen sie verschlüsseln dann drücken sie die zwei (2)." << endl;
	int einszwei;
	cin >> einszwei;
	if (einszwei == 1) {
		cout << "geben sie das zu Entschlusselde wort an." << endl;
		cin >> wort;
		int length = 0;
		do {
			if (wort[length] == '\0') {
				break;
			}
			length++;
		} while (true);
		for (int i = 0; i < length; i++) {
			for (int a = 0; a < 26; a++) {
				if (verschlüsselung[a] == wort[i]) {
					wort[i] = ABC[a];
					cout << wort << endl;
					break;
				}
			}
		}
		cout << wort << endl;
	}
	else {
		cout << "geben sie das zu Verschlüsselde wort an." << endl;
		cin >> wort;
		int length = 0;
		do {
			if (wort[length] == '\0') {
				break;
			}
			length++;
		} while (true);
		for (int i = 0; i < length; i++) {
			for (int a = 0; a < 26; a++) {
				if (ABC[a] == wort[i]) {
					wort[i] = verschlüsselung[a];
					cout << wort << endl;
					break;
				}
			}
		}
		cout << wort << endl;
	}
}