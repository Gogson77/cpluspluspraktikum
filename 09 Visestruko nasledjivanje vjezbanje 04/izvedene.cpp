#include "izvedene.h"
#include <iostream>

using namespace std;

void iTableta::fUpisivanje()
{
	iLekovi* pok = new iLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi koliko komada ima u pakovanju: ";
	cin >> pKomada;
	cout << "\nUnesi po koliko tableta se pije odjednom: ";
	cin >> pKoliko;
	cout << "Unesi koliko puta na dan se pije tableta: ";
	cin >> pDoziranje;
	delete pok;
}

void iTableta::fIspisivanje() const 
{
	fIspisivanje();
	cout << "\nU pakovanju ima: " << pKomada;
	cout << "\nDnevno doziranje: " << pDoziranje << " puta po " << pKoliko << " tableta" << endl;
}

int iTableta::fKupovina(int pDana) 
{
	return (int)(pKoliko * pDoziranje * pDana / pKomada);
}