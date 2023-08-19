#include "kProizvodjac.h"
#include <iostream>

using namespace std;

void kProizvodjac::fCitaj()
{
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

void kProizvodjac::fPisi() const
{
	cout << "\nIme proizvodjaca: " << pIme << endl;
	cout << "Adresa proizvodjaca: " << pAdr.pUlica << " " << pAdr.pBroj << " " << pAdr.pGrad << endl;
}
