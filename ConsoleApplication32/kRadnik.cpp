#include <iostream>
#include <string.h>
#include "kRadnik.h"
using namespace std;

kRadnik::kRadnik(char pP[20], char pI[15], float pK, int pGS, float pBS) {
	strcpy_s(pPrezime, pP);
	strcpy_s(pIme, pI);
	pKoef = pK;
	pGodStaza = pGS;
	pBrojSati = pBS;
};

int kRadnik::fPlata() {
	pPlata = (int)((pGodStaza < 20 || pKoef > 2.550) 
		? pBrojSati * pKoef * pGodStaza 
		: pBrojSati * (pKoef + cUvecanje) * pGodStaza);
	cout << "Za radnika " << pPrezime << " " << pIme;
	cout << " plata je " << pPlata << " dinara." << endl;
	return 0;
};

int kRadnik::fIsplata() {
	cout << "Nain isplate:" << endl;
	cout << pPlata / 1000 << " novcanica od 1000 dinara." << endl;
	cout << (pPlata % 1000) / 200 << " novcanica od 200 dinara." << endl;
	cout << ((pPlata % 1000) % 200) / 50 << " novcanica od 50 dinara." << endl;
	cout << (((pPlata % 1000) % 200) % 50) / 10 << " novcanica od 10 dinara." << endl;
	cout << ((((pPlata % 1000) % 200) % 50) % 10) / 1 << " novcanica od 1 dinar." << endl;
	return 0;
};

kRadnik::~kRadnik() {
	cout << "Plata je isplacena!" << endl;
};
