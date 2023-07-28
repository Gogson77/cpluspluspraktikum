#include "kStedisa.h"
#include <iostream>
#include <iomanip>

using namespace std;

int kStedisa::pBrojac = 0;

kStedisa::kStedisa() {
	pRedniBroj = ++pBrojac;
	strcpy_s(pIme, "");
	pStedRacun = 0;
	pStanje = 0.00;
}

void kStedisa::fUpis() {
	cout << "Unesite ime stedise: ";
	cin.ignore();
	cin.getline(pIme, MAX_IME);
	cout << "Unesite broj stednog racuna: ";
	cin >> pStedRacun;
	cout << "Unesite pocetno stanje: ";
	cin >> pStanje;
	cout << endl;
}

void kStedisa::fUplata(double iznos) {
	(*this).pStanje += abs(iznos); 
}

void kStedisa::fIsplata(double iznos) {
	if (iznos > pStanje) {
		cout << "Nemate dovoljno novca na racunu za trazenu isplatu.\n\n";
	} else {
		(*this).pStanje -= abs(iznos);
	}
}

kStedisa kStedisa::operator++() {
	++pStanje;
	return *this;
}

kStedisa kStedisa::operator--() {
	--pStanje;
	return *this;
}

inline kStedisa& kStedisa :: operator += (kStedisa pom) {
	pStanje += pom.pStanje;
	return *this;
};		// a += b


inline kStedisa& kStedisa :: operator -= (kStedisa pom) {
	pStanje -= pom.pStanje;
	return *this;
};		// a -= b

kStedisa operator + (kStedisa prvi, kStedisa drugi) {
	kStedisa zbir;
	zbir.pStanje = prvi.pStanje + drugi.pStanje;
	return zbir;
};  // c = a + b

void kStedisa::fListaj() {
	cout << pRedniBroj << "\t\t" << pIme << "\t\t" << pStedRacun << "\t\t" << pStanje << "\n";
}

void kStedisa::fPrikazi() {
	cout << pRedniBroj << "\t\t" << pIme << "\t\t" << pStedRacun << "\t\t" << pStanje << "\n";
}

void kStedisa::fIspisZaglavlja() {
	cout << "\nRedni broj\tIme stedise\tStedni racun\tStanje\n";
	cout << "------------------------------------------------------\n";
};

double kStedisa::fMax(const kStedisa* pokNizK) {
	double maxStanje = 0.0;
	int indexMaxStanje = -1;

	for (int i = 0; i < pBrojac; i++) {
		if (pokNizK[i].pStanje > maxStanje) {
			maxStanje = pokNizK[i].pStanje;
			indexMaxStanje = i;
		}
	}

	if (indexMaxStanje != -1) {
		cout << pokNizK[indexMaxStanje].pRedniBroj << "\t\t" << pokNizK[indexMaxStanje].pIme << "\t\t" << pokNizK[indexMaxStanje].pStedRacun << "\t\t" << fixed << setprecision(2) << pokNizK[indexMaxStanje].pStanje << "\n";
		cout << endl;
	}
	else {
		cout << "Nema stedisa sa uplacenim novcem.\n";
	}

	return maxStanje;
}

kStedisa::~kStedisa() {
	cout << "\nBroj stedisa koji se nalaze u imeniku: " << pBrojac;
}