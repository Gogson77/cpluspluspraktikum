#pragma once
class klasa
{
public:
	struct sNaziv {
		char pIme[15];
		char pPrezime[20];
	};

	sNaziv pNaziv;
	int pGodRod;

	klasa();

	klasa(sNaziv pN, int pGR);

	int fUpis();

	int fIspis();

	int fStarost();

	~klasa();
};

