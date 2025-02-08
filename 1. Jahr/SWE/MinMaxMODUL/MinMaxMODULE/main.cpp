#include <iostream>
using namespace std;

#include "eingabe.h"
#include "berechnung.h"
#include "ausgabe.h"


void main()
{
	float zahl1, zahl2, zahl3;
	float min, max;
	
	zahl1 = eingabe(1);
	zahl2 = eingabe(2);
	zahl3 = eingabe(3);

	min = berechnung(zahl1, zahl2, zahl3, true);
	max = berechnung(zahl1, zahl2, zahl3, false);

	ausgabe(min, max);

}