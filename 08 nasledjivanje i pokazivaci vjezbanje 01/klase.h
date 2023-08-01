#pragma once

class kCokolada {
	char pMarka[20];
	double pCena;
public:
	kCokolada();
	void fUpisCoko();
	double fDohvatiCenu() { return pCena; };
	double fProsecnaCena(kCokolada*, int);
	~kCokolada() {};
};

class iTorta : public kCokolada {
	char pIme[15];
public:
	iTorta();
	void fUpis();
	double fMinCena(kCokolada*, int);
	~iTorta() {};
};
