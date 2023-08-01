#include "klase.h"
#include <iostream>

using namespace std;


kCokolada::kCokolada() {
	strcpy_s(pMarka, "");
	pCena = 0.00;
};

void kCokolada::fUpisCoko() {
	cout << "Upisi marku cokolade: ";
	cin >> pMarka;
	cout << "Upisi cijenu cokolade " << pMarka << ": ";
	cin >> pCena;
};

double kCokolada::fProsecnaCena(kCokolada* oCoko, int n) {
	int i;
	double prosek = 0;
	for (i = 0; i < n; i++)
		prosek += oCoko[i].fDohvatiCenu();
	return prosek / n;
}

iTorta::iTorta() {
	strcpy_s(pIme, "");
};

void iTorta::fUpis() {
	cout << "Unesi naziv torte: ";
	cin >> pIme;
}

double iTorta::fMinCena(kCokolada* oCoko, int n) {
	int i, indmin;
	double min;
	min = oCoko[0].fDohvatiCenu();
	indmin = 0;
	for (i = 0; i < n; i++)
		if (min > oCoko[i].fDohvatiCenu()) {
			min = oCoko[i].fDohvatiCenu();
			indmin = i;
		}
	return min;
}