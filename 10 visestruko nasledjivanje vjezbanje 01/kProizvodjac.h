#pragma once
class kProizvodjac
{
	struct sAdresa
	{
		char pUlica[25];
		int pBroj;
		char pGrad[20];
	};
	sAdresa pAdr;
public:
	char pIme[25];
	kProizvodjac() {}
	void fCitaj();
	void fPisi() const;
	~kProizvodjac() {}
};
