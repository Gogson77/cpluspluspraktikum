#include <iostream>

using namespace std;

void main()
{
	int x = 0;
	cout << "\nVan bloka, x = " << x << endl;
	{
		int x = 1000;
		cout << "\nUnutar bloka, x = " << x << endl;
	}
	cout << "\nVan bloka ponovo, x = " << x << endl;
	cout << endl;

}