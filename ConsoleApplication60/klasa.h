#pragma once

struct sNaziv {
	char pIme[15];
	char pPrezime[20];
};

class klasa
{
public:
	sNaziv pNaziv;
	int pGodRod;
	int pStarost;

	klasa();
	klasa(sNaziv pN, int pGR);

	void fUpis();
	void fIspis();
	int fStarost();

	~klasa();
};

