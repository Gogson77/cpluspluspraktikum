#pragma once
#include "kLekovi.h"
#include "kProizvodjac.h"

class iTableta :public kLekovi, public kProizvodjac
{
	int pKomada;		// komada u pakovanju
	float pKoliko;		// po koliko tableta se pije
	int pDoziranje;	// koliko puta na dan
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

class iSirup : public kLekovi, public kProizvodjac
{
	int pKolicinaFlas;		// ukupna kolicina flasice
	float pKolicinaDoz;		// kolicina koja se pije
	int pDoziranje;		// koliko puta na dan
public:
	iSirup() {};
	void fUpisivanje();
	void fIspisivanje() const;
	int fDohvatiKolicinuFlas() const { return pKolicinaFlas; }
	float fDohvatiKolicinuDoz() const { return pKolicinaDoz; }
	int fDohvatiDoz() const { return pDoziranje; }
	int fKupovina(int pDana);
	~iSirup() {};
};

class iInjekcije : public kLekovi, public kProizvodjac
{
	int pKolicinaPak;		// broj ampula u pakovanju
	float pKolicinaAmp;		// zapremina ampule
	int pDoziranje;		// koliko puta na dan
public:
	iInjekcije() {};
	void fUpisivanje();
	void fIspisivanje() const;
	int fDohvatiKolicinuPak() const { return pKolicinaPak; }
	float fDohvatiKolicinuAmp() const { return pKolicinaAmp; }
	int fDohvatiDoz() const { return pDoziranje; }
	int fKupovina(int pDana);
	~iInjekcije() {};
};
