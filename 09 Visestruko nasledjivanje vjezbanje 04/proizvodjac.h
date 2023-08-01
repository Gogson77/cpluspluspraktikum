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
	char pIme[15];
	kProizvodjac() {};
	void fCitanje();
	void fPisanje() const;
	~kProizvodjac() {};
};