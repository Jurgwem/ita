#include <iostream>
using namespace std;

float berechnung(float zahl1, float zahl2, float zahl3, bool returnMin)
{
		float min;
		float max;


		min = zahl1;
		max = zahl2;

		if (zahl1 > zahl2)
		{
			min = zahl2;
			max = zahl1;
		}

		if (max < zahl3)
		{
			max = zahl3;
		}

		if (zahl3 < min)
		{
			min = zahl3;
		}

		if (returnMin) {
			return min;
		}
		else {
			return max;
		}
}