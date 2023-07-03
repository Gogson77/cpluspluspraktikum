#include "klasa.h"
#include <iostream>
using namespace std;

klasa::klasa() {
	strcpy_s(pNaziv.pIme, "Nema");
	strcpy_s(pNaziv.pPrezime, "Nema");
	pGodRod = 0;
};

klasa::klasa(sNaziv pN, int pGR) {
	strcpy_s(pNaziv.pIme, pN.pIme);
	strcpy_s(pNaziv.pPrezime, pN.pPrezime);
	pGodRod = pGR;
};


int klasa::fUpis() {
	cout << "Ime: ";
	cin >> pNaziv.pIme;
	cout << "Prezime: ";
	cin >> pNaziv.pPrezime;
	cout << "Godina rodjenja: ";
	cin >> pGodRod;
	cout << endl;
	return 0;
};

int klasa::fIspis() {
	cout << "Ime: " << pNaziv.pIme;
	cout << ", Prezime: " << pNaziv.pPrezime;
	cout << ", Godina rodjenja: " << pGodRod;
	cout << endl;
	return 0;
};

int klasa::fStarost() {
	cout << "Starost osobe je " << 2023 - pGodRod << " godina." << endl;
	return 0;
};

klasa::~klasa() { 
	cout << "Rad u tri datoteke." << endl; 
};