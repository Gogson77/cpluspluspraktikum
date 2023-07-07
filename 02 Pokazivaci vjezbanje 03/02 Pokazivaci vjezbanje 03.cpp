#include <iostream>

using namespace std;

void main()
{
	char c;
	char *ptr;
	ptr = &c;

	c = 'X';
	cout << "\nDirektna dodela vrednosti: c = " << c << endl;

	*ptr = 'x';
	cout << "\nIndirektna dodela vrednosti: c = " << c << endl;

	/* Prikaz vrednosti promenljive  c  indirektno, pomoću  ptr */
	cout << "\nPosredan pristup: *ptr = " << *ptr << endl;

	/* Prikaz adrese promenljive  c, pomoću  ptr */
	cout << "\nAdresa promenljive c je: " << &ptr << endl;

	cout << endl << endl;

}