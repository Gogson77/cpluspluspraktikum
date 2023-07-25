#pragma once
#define MAX_IME 30

class kStedisa
{
	int pBroj;
	char pIme[MAX_IME + 1];
	int pBrRacuna;
	double pStanje;

public:
	static int pRedniBroj;

	kStedisa();

	void fUpis();
	void fUplata();
	void fIsplata();
	void fListaj();
	void fPrikazi();
	void fMax();

	~kStedisa();
};

