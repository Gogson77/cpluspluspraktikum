#include "kLekovi.h"
#include <iostream>

using namespace std;

float kLekovi::fFormirajCenu(float pFabCena, float pProc, float pRabat) const
{
	return pFabCena * (1 + (pProc + pRabat) / 100);
}

void kLekovi::fUpisivanje()
{
	cout << "\nUnesi ime leka: ";
	cin >> pNaziv;
}

void kLekovi::fIspisivanje() const
{
	cout << "Naziv leka: " << pNaziv << endl;
	cout << "Sifra leka: " << pSifra << endl;
}

