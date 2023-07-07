#include <iostream>

using namespace std;

int fZamena();

void main()
{
	int i = 10;
	cout << "\nPre zamene: i = " << i << endl;
	i = fZamena();
	cout << "\nPosle zamene: i = " << i << endl << endl;
}

int fZamena() { return 20; };