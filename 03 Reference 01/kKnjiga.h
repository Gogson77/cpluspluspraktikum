#pragma once
struct sIme {
	char pIme[15];
	char pPrezime[20];
};

typedef enum eFormat { tvrdi = 0, meki = 1, dzepno = 2 };

class kKnjiga {
private:
	char pNaziv[25];
	sIme pPisac;
	char pIzdavac[20];
	eFormat pFormat;
public:
	int pBrojStrana;
	int pCijenaStrane;
	int pCijenaKnjige;
	kKnjiga();
	void fUpis();
	void fIzracunaj();
	void fIspisi();
	~kKnjiga();
};

