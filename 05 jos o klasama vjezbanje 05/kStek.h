#pragma once
class kStek
{
	static kStek* vrh;
	kStek* preth;
	int pBroj;
public:
	static void fDodaj(int);
	static int fUzmi();
	static int fPrazan() { return vrh == 0; };
	static void fBrisi();
};