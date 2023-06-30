#include <iostream>
#include <string.h>
using namespace std;

class kZivotinje {
public:
	char pNaziv[15];
	float pTezina;
	kZivotinje(const char* pN,float pT);
	int fTezina();
	~kZivotinje();
};

kZivotinje::kZivotinje(const char* pN, float pT) { 
	strcpy_s(pNaziv, pN); 
	pTezina = pT; 
};

int kZivotinje::fTezina() {
	cout << pNaziv << ", tezina je " << pTezina << " kilograma." << endl;
	if (pTezina <= 10) cout << "Mala zivotinja." << endl << endl;
	else if (pTezina <= 50) cout << "Srednja zivotinja." << endl << endl;
	else cout << "Velika zivotinja." << endl << endl; 
	return 0;
};

kZivotinje::~kZivotinje() { cout << "Zivotinja je unistena." << endl; };

class iPtice : public kZivotinje {
public: 
	int pLeti;
	int pBrNogu;
	iPtice(const char* pN, float pT, int pL, int pBN);
	~iPtice();
};

iPtice::iPtice(const char* pN, float pT, int pL, int pBN) : kZivotinje(pN,pT){
	pLeti = pL;
	pBrNogu = pBN;
};

iPtice::~iPtice() { cout << "Ptica je unistena." << endl; };

class iRibe : public kZivotinje {
public:
	int pPeraja;
	iRibe(const char* pN, float pT, int pP);
	~iRibe();
};

iRibe::iRibe(const char* pN, float pT, int pP) : kZivotinje(pN, pT) {
	pPeraja = pP;
}

iRibe::~iRibe() { cout << "Riba je unistena." << endl; };

class iSisari : public kZivotinje {
public:
	int pBrNogu;
	iSisari(const char* pN, float pT, int pBN);
	~iSisari();
};

iSisari::iSisari(const char* pN, float pT, int pBN) : kZivotinje(pN,pT) { pBrNogu = pBN; };

iSisari::~iSisari() { cout << "Sisar je unisten." << endl; }

int main()
{
	iPtice oOrao("Bijeli", 5, 1, 2);
	iRibe oSom("Veliki", 3, 3);
	iSisari oLav("Riki", 150, 4);
	oOrao.fTezina();
	oSom.fTezina();
	oLav.fTezina();
	return 0;
}
