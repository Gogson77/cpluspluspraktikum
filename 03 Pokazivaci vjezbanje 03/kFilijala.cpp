#include "kFilijala.h"
# include <iostream>
# include <string>

using namespace std;

kFilijala::kFilijala() {
	strcpy_s(pSifra, "Nema");
	strcpy_s(pGlavni, "Nema");
	strcpy_s(pLokacija.pUlica, "Nema");
	pLokacija.pBroj = 0;
	strcpy_s(pLokacija.pGrad, "Nema");
	pNaplata = 0.00;
};

void kFilijala::fUpis() {
	cout << "Sifra:";
	cin >> pSifra;
	cout << "Glavni:";
	cin >> pGlavni;
	cout << "Lokacija ulica, broj, grad:";
	cin >> pLokacija.pUlica >> pLokacija.pBroj >> pLokacija.pGrad;
};

void kFilijala::fIzracunaj() {
	int pBrojObjekata;
	int pPoreskaStopaPausalno;
	cout << "Broj objekata:";
	cin >> pBrojObjekata;
	cout << "Poreska stopa pausalno dinara:";
	cin >> pPoreskaStopaPausalno;
	pNaplata = pBrojObjekata * pPoreskaStopaPausalno;
};

void kFilijala::fIspisi() {
	cout << "Filijala u " << pLokacija.pGrad << " je ostvarila naplatu pd " << pNaplata << " dinara." << endl << endl;
};

kFilijala::~kFilijala() {
	cout << "Naplata poreza je zavrsena." << endl << endl;
};
