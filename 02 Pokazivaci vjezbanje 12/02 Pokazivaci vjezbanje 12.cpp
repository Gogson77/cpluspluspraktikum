#include <iostream>

using namespace std;

void main()
{
	int x = 9;
	int *pok;
	pok = &x;
	cout << "Vrednost u pokazivacu je : " << *pok << endl;
}
