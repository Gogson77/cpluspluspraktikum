#include "klasa.h"
#include <iostream>
using namespace std;

klasa::klasa() {
	strcpy_s(pNaziv.pIme, "Niko");
	strcpy_s(pNaziv.pPrezime, "Niko");
	pGodRod = 0;
	pStarost = 0;
};

void klasa::fUpis() {
	cout << "Unesi ime: ";
	cin >> pNaziv.pIme;
	cout << "\nUnesi prezime: ";
	cin >> pNaziv.pPrezime;
	cout << "\nUnesi godiste: ";
	cin >> pGodRod;
};

void klasa::fIspis() {
	cout << "\nZovem se " << pNaziv.pIme << " " << pNaziv.pPrezime;
	cout << "\nGodiste rodjenja: " << pGodRod;
};

int klasa::fStarost() {
	return (2023 - pGodRod);
};

klasa::~klasa() { 
	cout << "Rad u tri datoteke." << endl; 
};