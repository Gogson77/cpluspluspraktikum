#include "kStek.h"
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	for (;;) 
	{
		cout << "\nDuzina niza brojeva? ";
		cin >> n;
		if (!n) break;
		cout << "\nNiz od " << n << " brojeva? ";
		for (int i = 0; i < n; i++) {
			cin >> k;
			kStek::fDodaj(k);
		}
		cout << "\nNiz po obrnutom redosledu: ";
		while (!kStek::fPrazan())
			cout << " " << kStek::fUzmi();
		cout << endl << endl;
		kStek::fBrisi();
	}
}