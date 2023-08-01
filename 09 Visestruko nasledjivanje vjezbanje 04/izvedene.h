#pragma once
#include "lekovi.h"

class iTableta:public iLekovi
{
	int pKomada;
	float pKoliko;
	int pDoziranje;
public:
	iTableta() {};
	void fUpisivanje();
	void fIspisivanje() const;
	int fDohvatiKomada() const { return pKomada; }
	float fDohvatiKoliko() const { return pKoliko; }
	int fDohvatiDoz() const { return pDoziranje; }
	int fKupovina(int pDana);
	~iTableta() {};
};

class iSirup : public iLekovi 
{
	int pKolicinaFlas;
	float pKolicinaDoz;
	int pDoziranje;
public:
	iSirup() {}
	void fUpisivanje();
	void fIspisivanje() const;
	int fDohvatiKolicinuFlas() const { return pKolicinaFlas; }
	float fDohvatiKolicinuDoz() const { return pKolicinaDoz; }
	int fDohvatiDoz() const { return pDoziranje; }
	int fKupovina(int pDana);
	~iSirup() {}
};

class iInjekcije :public iLekovi 
{
	int pKolicinaPak;
	float pKolicinaAmp;
	int pDoziranje;
public:
	iInjekcije() {}
	void fUpisivanje();
	void fIspisivanje() const;
	int fDohvatiKolicinuPak() const { return pKolicinaPak; }
	float fDohvatiKolicinuAmp() const { return pKolicinaAmp; }
	int fDohvatiDoz() const { return pDoziranje; }
	int fKupovina(int pDana);
	~iInjekcije() {}
};