#pragma once
#include "proizvodjac.h"

class iLekovi : public kProizvodjac {
	char pNaziv[15];
	char pSifra[20];
	kProizvodjac pProiz;
public:
	iLekovi() {};
	float fFormirajCenu(float pFabCena, float pProc, float pRabat ) const;
	virtual void fUpisivanje();
	virtual void fIspisivanje() const;
	virtual int fKupovina(int pDana) { return 0; }
	~iLekovi() {};
};
