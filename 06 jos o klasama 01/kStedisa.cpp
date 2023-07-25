#include "kStedisa.h"
#include <iostream>

using namespace std;

int kStedisa::pRedniBroj = 0;

kStedisa::kStedisa() {
pBroj = 0;
strcpy_s(pIme, "");
pBrRacuna = 0;
pStanje = 0.00;
}

void kStedisa::fUpis() {
	pRedniBroj += 1;
	cout << "Unesi ime: " << endl;
	cin >> pIme;
	cout << "Unesi broj racuna: " << endl;
	cin >> pBrRacuna;
	cout << "Unesi " << endl;
	cout << "Unesi " << endl;

};

void kStedisa::fUplata() {

};

void kStedisa::fIsplata() {

};

void kStedisa::fListaj() {

};

void kStedisa::fPrikazi() {

};

void kStedisa::fMax() {

};

kStedisa::~kStedisa() {

};