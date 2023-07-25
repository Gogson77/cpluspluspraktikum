#include "kKnjiga.h"
#include <iostream>
#include <string>

using namespace std;

kKnjiga::kKnjiga() {
	strcpy_s(pNaziv, "Nema");
	pFormat = tvrdi;
	strcpy_s(pPisac.pIme, "Nema");
	strcpy_s(pPisac.pPrezime, "Nema");
	strcpy_s(pIzdavac, "Nema");
	pBrojStrana = 0;
	pCijenaStrane = 0;
	pCijenaKnjige = 0;
};

void kKnjiga::fUpis() {
	int pFormatValue;
	cout << "Unesi naziv knjige: ";
	cin >> pNaziv;
	cout << "\nUnesi format knjige (tvrdi=0, meki=1, dzepno=2): ";
	cin >> pFormatValue;
	switch (pFormatValue) {
	case 0: pFormat = tvrdi; break;
	case 1: pFormat = meki; break;
	case 2: pFormat = dzepno; break;
	default:
		cout << "\nUnesi pravilan broj!" << endl;
		fUpis();
		break;
	}
	cout << "\nUnesi ime i prezime pisca: " << endl;
	cin >> pPisac.pIme >> pPisac.pPrezime;
	cout << "\nUnesi naziva izdavaca: ";
	cin >> pIzdavac;
	cout << endl;
}

void kKnjiga::fIzracunaj() {
	double popust;
	cout << "Unesi broj strana knjige: ";
	cin >> pBrojStrana;
	cout << "\nUnesi popust na cijenu knjige: ";
	cin >> popust;
	switch (pFormat)
	{
	case tvrdi: pCijenaStrane = 10; break;
	case meki: pCijenaStrane = 8; break;
	case dzepno: pCijenaStrane = 5; break;
	default:
		cout << "\nNepoznat format, cijena strane nije postavljena." << endl;
		break;
	}
	pCijenaKnjige = pBrojStrana * pCijenaStrane * (1 - popust / 100);
};

void kKnjiga::fIspisi() {
	cout << "\nKnjiga " << pNaziv << " kosta " << pCijenaKnjige << " dinara." << endl;
};

kKnjiga::~kKnjiga() {
	cout << "\nKnjiga je procitana." << endl << endl;
};
