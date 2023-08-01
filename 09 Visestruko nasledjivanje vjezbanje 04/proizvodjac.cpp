#include "proizvodjac.h"
#include <iostream>

using namespace std;

void kProizvodjac::fCitanje() {
	cout << "\nUnesi ime proizvodjaca: ";
	cin >> pIme;
	cout << "\nUnesi adresu proizvodjaca" << endl;
	cout << "\tUlica: ";
	cin >> pAdr.pUlica;
	cout << "\tBroj: ";
	cin >> pAdr.pBroj;
	cout << "\tGrad: ";
	cin >> pAdr.pGrad;
}

void kProizvodjac::fPisanje() const {
	cout << "\nIme proizvodjaca: " << pIme << endl;
	cout << "Adresa proizvodjaca: " << pAdr.pUlica << " " << pAdr.pBroj << " " << pAdr.pGrad << endl;
}
