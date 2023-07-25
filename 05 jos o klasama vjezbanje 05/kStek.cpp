#include "kStek.h"
#include <stdlib.h>

kStek* kStek::vrh = 0;

void kStek::fDodaj(int i) 
{
	kStek* novi = new kStek;
	if (!novi) exit(1);
	novi->pBroj = i;
	novi->preth = vrh;
	vrh = novi;
};

int kStek::fUzmi() 
{
	if (!vrh) exit(2);
	int i = vrh->pBroj;
	kStek* stari = vrh;
	vrh = vrh->preth;
	delete stari;
	return i;
};

void kStek::fBrisi() 
{
	while (vrh)
	{
		fUzmi();
	}
};