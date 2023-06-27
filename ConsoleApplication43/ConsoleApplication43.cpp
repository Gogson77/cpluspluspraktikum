#include <iostream>
using namespace std;

int main()
{
	int mesec;
	while (1)
	{
		cout << " Unesi redni broj meseca: " << endl;
		cin >> mesec;
		if (mesec == 0) break;
		switch (mesec)
		{
		case 1: cout << " Januar" << endl;
			break;
		case 2: cout << " Februar" << endl;
			break;
		case 3: cout << " Mart" << endl;
			break;
		case 4: cout << " April" << endl;
			break;
		case 5: cout << " Maj" << endl;
			break;
		case 6: cout << " Jun" << endl;
			break;
		case 7: cout << " Jul" << endl;
			break;
		case 8: cout << " Avgust" << endl;
			break;
		case 9: cout << " Septembar" << endl;
			break;
		case 10: cout << " Oktobar" << endl;
			break;
		case 11: cout << " Novembar" << endl;
			break;
		case 12: cout << " Decembar" << endl;
			break;
		default: cout << " Niste uneli dobar redni broj meseca." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}
