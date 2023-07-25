#pragma once

struct sAdresa {
	char pUlica[25];
	int pBroj;
	char pGrad[20];
};

class kFilijala {
private:
	char pSifra[10];
	char pGlavni[25];
	sAdresa pLokacija;
	float pNaplata;
public:
	kFilijala();

	void fUpis();
	void fIzracunaj();
	void fIspisi();

	~kFilijala();
};
