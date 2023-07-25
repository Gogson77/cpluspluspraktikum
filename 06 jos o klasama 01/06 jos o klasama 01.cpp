#include "kStedisa.h"
#include <iostream>

using namespace std;

int main()
{
	kStedisa* pokK;
	pokK = new kStedisa;
	int izbor = -1;

	pokK->fUpis();

	while (izbor != 0)
	{
		

		cout << "Odaberi:\t(0)Izlaz\t(1)Uplata\t(2)Isplata\t(3)Listaj\t(4)Prikazi\t(5)Max" << endl;
		cin >> izbor;

		switch (izbor)
		{
		case 0:
			izbor = 0;
			break;
		case 1:
			pokK->fUplata();
			break;
		case 2:
			pokK->fIsplata();
			break;
		case 3:
			pokK->fListaj();
			break;
		case 4:
			pokK->fPrikazi();
			break;
		case 5:
			pokK->fMax();
			break;
		default:
			cout << "Neispravan odabir\n\n";
		}

	}

	delete pokK;

	return 0;
}

