#include <iostream>

using namespace std;

void fStampa(void);

int x = 1, y = 2;

void main()
{
	cout << "\nPre poziva funkcije: x = " << x << ", y = " << y << endl;
	fStampa();
	cout << "\nPosle poziva funkcije: x = " << x << ", y = " << y << endl;
	cout << endl;
}

void fStampa(void) 
{
	int x = 100, y = 200;
	cout << "\nUnutar funkcije: x = " << x << ", y = " << y << endl;
};