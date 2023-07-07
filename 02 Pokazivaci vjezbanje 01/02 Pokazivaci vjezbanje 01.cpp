#include <iostream>

using namespace std;

void main()
{
	int x = 1;
	int *ptr;
	ptr = &x;

	cout << "\nDirektan pristup: x = " << x;
	cout << "\nIndirektan pristup: x = " << *ptr;
	cout << "\nAdresa promenljive prikazane na 1. nacin : " << &x;
	cout << "\nAdresa promenljive prikazane na 2. nacin : " << ptr;
	cout << endl;
}