#include <iostream>
#include <string.h>
using namespace std;

struct sDimenzije 
{
    float pVisina;
    float pTezina;
};

union uHobi
{
    char pSport[10];
    char pInstrument[10];
};

class kDijete 
{
public:
    char pIme[15];
    int pGodRod;
    sDimenzije pDim;
    uHobi pNazHob;
};

int main()
{
    kDijete tvojeDijete;
    strcpy_s(tvojeDijete.pIme, "Nikola");
    tvojeDijete.pGodRod = 1999;
    tvojeDijete.pDim.pTezina = 49.50;
    tvojeDijete.pDim.pVisina = 150.50;
    strcpy_s(tvojeDijete.pNazHob.pInstrument , "gitara");

    kDijete njenoDijete;
    strcpy_s(njenoDijete.pIme, "Dejan");
    njenoDijete.pGodRod = 2005;
    njenoDijete.pDim.pTezina = 37.50;
    njenoDijete.pDim.pVisina = 135.50;
    strcpy_s(njenoDijete.pNazHob.pSport, "bocanje");

    cout << tvojeDijete.pIme << " " << tvojeDijete.pGodRod << " "
        << tvojeDijete.pDim.pTezina << " "
        << tvojeDijete.pDim.pVisina << " "
        << tvojeDijete.pNazHob.pInstrument << endl << endl;

    cout << njenoDijete.pIme << " " << njenoDijete.pGodRod << " "
        << njenoDijete.pDim.pTezina << " "
        << njenoDijete.pDim.pVisina << " "
        << njenoDijete.pNazHob.pSport << endl;
    return 0;
}
