#pragma once
#include <string.h>
#define cUvecanje 0.320

//deklaracija klase
class kRadnik
{
public:
    char pPrezime[20];
    char pIme[15];
    float pKoef;
    int pGodStaza;
    float pBrojSati;
    int pPlata;
    kRadnik(char pP[20], char pI[15], float pK, int pGS, float BS);
    int fPlata();
    int fIsplata();
    ~kRadnik();
};

