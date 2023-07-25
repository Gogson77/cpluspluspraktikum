#pragma once
class kTacka
{
	double x, y;
public:
	void fPravi(double a, double b) { x = a; y = b; }
	double fApcisa() const { return x; }
	double fOrdinata() const { return y; }
	double fPocetak() const;
	double fRastojanje(kTacka) const;
	kTacka fNajbliza(kTacka*, int) const;
	void fCitaj();
	void fPisi() const;
};
