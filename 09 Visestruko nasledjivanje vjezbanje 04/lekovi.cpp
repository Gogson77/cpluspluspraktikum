#include "lekovi.h"
#include <iostream>

using namespace std;

float iLekovi::fFormirajCenu(
	float pFabCena,
	float pProc,
	float pRabat
) const {
	return pFabCena * (1 + (pProc + pRabat) / 100);
};

void iLekovi::fUpisivanje()
{
	cout << "\nUnesi ime leka: ";
	cin >> pNaziv;
	cout << "\nUnesi ime proizvodjaca: ";
	cin >> pProiz.pIme;
}

void iLekovi::fIspisivanje() const 
{
	cout << "Naziv leka: " << pNaziv << endl;
	cout << "Sifra leka: " << pSifra << endl;
}