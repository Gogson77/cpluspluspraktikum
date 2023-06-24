#include "kTakmicenje.h"
#include <iostream>
#include <string>
using namespace std;

kTakmicenje::kTakmicenje(
	string pU,
	int pM,
	int pO,
	float pV,
	eStimulans pD
) {
	pUcesnik = pU;
	pMjesto = pM;
	pOsnova = pO;
	pVrijednost = pV;
	pDoping = pD;
};

int kTakmicenje::fNagrada() {
	float pNagrada;
	cout << "UCESNIK: " << endl;
	cout << pUcesnik << endl;
	cout << "Doping kontrola je " << pDoping << endl;
	cout << "Osnova je " << pOsnova << endl;
	pNagrada = (pMjesto == 1 && pDoping != Da)
		? (++pOsnova) * pVrijednost
		: (pOsnova++) * pVrijednost;
	cout << "Nagrada je " << pNagrada << " dinara." << endl;
	cout << "Nova osnova je " << pOsnova << endl << endl;
	return 0;
};

kTakmicenje::~kTakmicenje() {
	cout << "Takmicenje je zavrseno!" << endl << endl;
};