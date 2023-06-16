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
    kDijete oSin, oKcerka;
    strcpy_s(oSin.pIme, "Zoran");
    oSin.pGodRod = 1980;
    oSin.pDim.pVisina = 170;
    oSin.pDim.pTezina = 73;
    strcpy_s(oSin.pNazHob.pSport, "fudbal");
    
    strcpy_s(oKcerka.pIme, "Mila");
    oKcerka.pGodRod = 1985;
    oKcerka.pDim.pVisina = 170;
    oKcerka.pDim.pTezina = 60;
    strcpy_s(oKcerka.pNazHob.pInstrument, "klavir");


    cout << oSin.pIme << " " << oSin.pGodRod << " "
        << oSin.pDim.pVisina << " " << oSin.pDim.pTezina << " "
        << oSin.pNazHob.pSport << endl << endl;

    cout << oKcerka.pIme << " " << oKcerka.pGodRod << " "
        << oKcerka.pDim.pVisina << " " << oKcerka.pDim.pTezina << " "
        << oKcerka.pNazHob.pInstrument << endl << endl;

    strcpy_s(oSin.pNazHob.pInstrument, "gitara");

    cout << oSin.pIme << " " << oSin.pGodRod << " "
        << oSin.pDim.pVisina << " " << oSin.pDim.pTezina << " "
        << oSin.pNazHob.pInstrument << endl << endl;
    
    return 0;
}
