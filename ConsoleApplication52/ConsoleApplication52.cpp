#include <iostream>
using namespace std;

class kCokolada {
	char pMarka[20];
	float pCijena100;
	float pCijena200;
	float pCijena1000;

protected:
	int fMinCijena();

public:
	kCokolada();
	kCokolada(const char* pM, float pC1, float pC2, float pC3);
	int fUpisCijena();
	int fProsjecnaCijena();
	int fPojedenaKolicina();
	~kCokolada();
};

kCokolada::kCokolada() {
	strcpy_s(pMarka, "Nema");
	pCijena100 = 0.00;
	pCijena200 = 0.00;
	pCijena1000 = 0.00;
};

kCokolada::kCokolada(const char* pM, float pC1, float pC2, float pC3) {
	strcpy_s(pMarka, pM);
	pCijena100 = pC1;
	pCijena200 = pC2;
	pCijena1000 = pC3;
};

int kCokolada::fUpisCijena() {
	cout << "Unesi marku cokolada: "; cin >> pMarka;
	cout << "Upisi cijenu " << pMarka << " cokolade od 100 grama: "; cin >> pCijena100; 
	cout << "Upisi cijenu " << pMarka << " cokolade od 200 grama: "; cin >> pCijena200; 
	cout << "Upisi cijenu " << pMarka << " cokolade od 1000 grama: "; cin >> pCijena1000;
	return 0;
};

int kCokolada::fProsjecnaCijena() {
	float pProsjek;
	pProsjek = (pCijena100+pCijena200+pCijena1000) / (100+200+1000);
	cout << "Prosjecna cijena jednog grama cokolade je " << pProsjek << " dinara." << endl << endl;
	return 0;
};

int kCokolada::fPojedenaKolicina() {
	float pPojedeno = 0;
	int i, x;
	cout << "Unesi broj pojedenih cokolada od 100, 200 i 1000 grama, marke ";
	cout << pMarka << ":" << endl;
	for (i = 0; i < 3; i++) {
		cin >> x;
		pPojedeno = pPojedeno + x;
	}
	cout << "Ukupno je pojedeno " << pPojedeno << " cokolada." << endl << endl;
	return 0;
};

int kCokolada::fMinCijena() {
	float pMin;
	int pGram;
	pMin = pCijena100 / 100;
	pGram = 100;
	if (pMin > pCijena200 / 200) { pMin = pCijena200; pGram = 200; }
	if (pMin > pCijena1000 / 1000) { pMin = pCijena1000; pGram = 1000; }
	cout << "Najpovoljnije je kupiti cokoladu od " << pGram << " grama." << endl;
	cout << "Cijena po gramu je " << pMin << " dinara." << endl;
	return 0;
};

kCokolada::~kCokolada() { cout << endl << "Cokolada marke " << pMarka << " je pojedena." << endl; };


class iTorta : public kCokolada {
	char pIme[15];
public:
	iTorta();
	int fUpis();
	int fPovoljno();
	~iTorta();
};

iTorta::iTorta() { strcpy_s(pIme, "Nema"); };

int iTorta::fUpis() {
	cout << "Unesi naziv torte: " << endl;
	cin >> pIme; cout << endl;
	return 0;
};

int iTorta::fPovoljno() {
	fUpisCijena();
	cout << endl;
	fProsjecnaCijena();
	fMinCijena();
	return 0;
};

iTorta::~iTorta() { cout << endl << "Torta je pojedena" << endl; };

int main()
{
	kCokolada oPoklon;
	oPoklon.fUpisCijena();
	oPoklon.fProsjecnaCijena();
	oPoklon.fPojedenaKolicina();
	
	iTorta oRodjendan;
	oRodjendan.fUpis();
	oRodjendan.fPovoljno();

	return 0;
}