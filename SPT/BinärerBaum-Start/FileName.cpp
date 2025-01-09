#include <iostream>
using namespace std;

struct Baum
{
	char name[50 + 1];
	Baum* vater;
	Baum* mutter;
};

int ui(Baum* wurzel, Baum* position);

void eingabeVater(Baum* wurzel, Baum* position)
{
	char input[50 + 1];

	system("cls");
	if (position->vater == NULL)
	{
		Baum* vater = new Baum;
		vater->vater = NULL;
		vater->mutter = NULL;

		cout << "Geben sie den Namen des Vaters ein" << endl;
		cin.getline(input, 50);

		strcpy_s(vater->name, input);
		position->vater = vater;
	}
	else
	{
		position = position->vater;
	}
	
	ui(wurzel, position);
}

void eingabeMutter(Baum* wurzel, Baum* position)
{
	char input[50 + 1];

	system("cls");
	if (position->mutter == NULL)
	{
		Baum* mutter = new Baum;
		mutter->mutter = NULL;
		mutter->vater = NULL;

		cout << "Geben sie den Namen der Mutter ein" << endl;
		cin.getline(input, 50);

		strcpy_s(mutter->name, input);
		position->mutter = mutter;
	}
	else
	{
		position = position->mutter;
	}

	ui(wurzel, position);
}


int ui(Baum* wurzel, Baum* position)
{
	int choice;

	system("cls");
	cout << "          " << position->name << endl;
	cout << endl;
	if (position->vater == NULL)
	{
		cout << "Vater?";
	}
	else
	{
		cout << position->vater->name;
	}
	cout << "             ";
	if (position->mutter == NULL)
	{
		cout << "Mutter?" << endl;;
	}
	else
	{
		cout << position->mutter->name << endl;;
	}
	cout << endl;
	cout << "Bitte wahlen Sie aus" << endl;
	cout << "(1) - Zur Wurzel gehen" << endl;
	if (position->vater == NULL)
	{
		cout << "(2) - Eingabe des Vaters" << endl;
	}
	else
	{
		cout << "(2) - Zum Vater gehen" << endl;
	}
	if (position->mutter == NULL)
	{
		cout << "(3) - Mutter eingeben" << endl;
	}
	else
	{
		cout << "(3) - Weitergehen zur Mutter" << endl;
	}
	cout << "(4) - Ende" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		ui(wurzel, wurzel);
		break;

	case 2 :
		cin.ignore();
		eingabeVater(wurzel, position);
		break;

	case 3:
		cin.ignore();
		eingabeMutter(wurzel, position);
		break;

	case 4:
		return 0;
		break;

	default:
		break;
	}
	ui(wurzel, position);
}

void main()
{
	locale::global(locale("German_germany"));

	Baum* wurzel;
	wurzel = new Baum;
	strcpy_s(wurzel->name, "Wurzel");
	wurzel->vater = NULL;		
	wurzel->mutter = NULL;				

	ui(wurzel, wurzel);
}