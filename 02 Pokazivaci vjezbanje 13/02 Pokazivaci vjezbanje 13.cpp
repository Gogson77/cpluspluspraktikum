#include <iostream>

using namespace std;

void main()
{
	int prom = 5;
	cout << "Vrednost promenljive je : " << prom << endl;
	int* pok;
	pok = &prom;
	cout << "Vrednost promenljive je : " << *pok << endl;
}
