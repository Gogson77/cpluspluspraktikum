#include "izvedene.h"
#include <iostream>

using namespace std;

void iTableta::fUpisivanje(){
	iLekovi* pok = new iLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi koliko komada ima u pakovanju: ";
	cin >> pKomada;
	cout << "\nUnesi po koliko tableta se pije odjednom: ";
	cin >> pKoliko;
	cout << "\nUnesi koliko puta na dan se pije tableta: ";
	cin >> pDoziranje;
	delete pok;
}

void iTableta::fIspisivanje() const {
	fIspisivanje();
	cout << "\nU pakovanju ima: " << pKomada;
	cout << "\nDnevno doziranje: " << pDoziranje << " puta po " << pKoliko << " tableta" << endl;
}

int iTableta::fKupovina(int pDana) {
	return (int)(pKoliko * pDoziranje * pDana / pKomada);
}

void iSirup::fUpisivanje() {
	iLekovi* pok = new iLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi zapreminu flasice: ";
	cin >> pKolicinaFlas;
	cout << "\nUnesi kolicinu koju treba popiti: ";
	cin >> pKolicinaDoz;
	cout << "\nUnesi koliko puta na dan se pije sirup: ";
	cin >> pDoziranje;
	delete pok;
}

void iSirup::fIspisivanje() const {
	fIspisivanje();
	cout << "\nZapremina flasice je: " << pKolicinaFlas;
	cout << "\nDnevno doziranje: " << pDoziranje << " puta po " << pKolicinaDoz << " ml sirupa" << endl;
}

int iSirup::fKupovina(int pDana) {
	return (int)(pKolicinaDoz*pDoziranje*pDana/pKolicinaFlas);
}

void iInjekcije::fUpisivanje() {
	iLekovi* pok = new iLekovi;
	pok->fUpisivanje();
	cout << "\nUnesi broj ampula u pakovanju: ";
	cin >> pKolicinaPak;
	cout << "\nUnesi zapreminu ampule: ";
	cin >> pKolicinaAmp;
	cout << "\nUnesi koliko puta na dan se dobija injekcija: ";
	cin >> pDoziranje;
	delete pok;
}

void iInjekcije::fIspisivanje() const {
	fIspisivanje();
	cout << "\nPakovanje sadrzi " << pKolicinaPak << " ampula" << endl;
	cout << "\nZapremina jedne ampule je " << pKolicinaAmp << " ml" << endl;
	cout << "\nDnevno doziranje: " << pDoziranje << " puta" << endl;
}

int iInjekcije::fKupovina(int pDana) {
	return (int)(pDoziranje * pDana / pKolicinaPak);
}