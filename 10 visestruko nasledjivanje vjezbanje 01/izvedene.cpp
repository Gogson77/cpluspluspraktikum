#include "izvedene.h"
#include <iostream>

using namespace std;

void iTableta::fUpisivanje()
{
	kLekovi* pok = new kLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi ime proizvodjaca: ";
	cin >> pIme;
	cout << "\nUnesi koliko komada ima u pakovanju: ";
	cin >> pKomada;
	cout << "\nUnesi po koliko tableta se pije tablete: ";
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


void iSirup::fUpisivanje()
{
	kLekovi* pok = new kLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi ime proizvodjaca: ";
	cin >> pIme;
	cout << "\nUnesi zapreminu flasice: ";
	cin >> pKolicinaFlas;
	cout << "\nUnesi kolicinu koju treba popiti: ";
	cin >> pKolicinaDoz;
	cout << "Unesi koliko puta na dan se pije sirup: ";
	cin >> pDoziranje;
	delete pok;
}

void iSirup::fIspisivanje() const
{
	fIspisivanje();
	cout << "\nZapremina flasice je: " << pKolicinaFlas;
	cout << "\nDnevno doziranje: " << pDoziranje << " puta po " << pKolicinaDoz << " ml sirupa" << endl;
}

int iSirup::fKupovina(int pDana)
{
	return (int)(pKolicinaDoz * pDoziranje * pDana / pKolicinaFlas);
}


void iInjekcije::fUpisivanje()
{
	kLekovi* pok = new kLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi ime proizvodjaca: ";
	cin >> pIme;
	cout << "\nUnesi broj ampula u pakovanju: ";
	cin >> pKolicinaPak;
	cout << "\nUnesi zapreminu ampule: ";
	cin >> pKolicinaAmp;
	cout << "Unesi koliko puta na dan se dobija injekcija: ";
	cin >> pDoziranje;
	delete pok;
}

void iInjekcije::fIspisivanje() const
{
	fIspisivanje();
	cout << "\nPakovanje sadrzi " << pKolicinaPak << " ampula" << endl;
	cout << "Zapremina jedne ampule je: " << pKolicinaAmp << " ml" << endl;
	cout << "\nDnevno doziranje: " << pDoziranje << " puta" << endl;
}

int iInjekcije::fKupovina(int pDana)
{
	return (int)(pDoziranje * pDana / pKolicinaPak);
}


