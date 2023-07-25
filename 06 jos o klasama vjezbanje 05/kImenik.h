#pragma once
#define MAX_BROJ 100
#define MAX_IME 30

class kImenik {
	struct sAdresa {
		char pUlica[MAX_IME + 1];
		int pBroj;
		char pGrad[MAX_IME + 1];
	};
	sAdresa pAdr;
	int pRedniBroj;
	char pIme[MAX_IME + 1];
	char pTelefon[15];
public:
	static int pBroj;

	kImenik();
	void fUpis();
	void fListaj() const;
	void fPrikazi() const;
	~kImenik();
};