// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

//klasa kVozilo
class kVozilo 
{
public: 
    char pNaziv[15];
    int pMaxBrzina;
    char pBoja[15];

    kVozilo( 
        char pNaz[15], 
        int pMax, 
        char pBo[15]
    );//konstruktor

    int fKojaKola(); //funkcija fKojaKola

    ~kVozilo(); //destruktor
};

//definisanje konstruktora
kVozilo::kVozilo( 
    char pNaz[15], 
    int pMax, 
    char pBo[15] 
    )
    {
    strcpy(pNaziv, pNaz);
    pMaxBrzina = pMax;
    strcpy(pBoja, pBo);
};

//definisanje funkcije fKojaKola
int kVozilo::fKojaKola()
{
    cout << "\nOvo je " << pNaziv << ", maksimalna brzina mu je " << pMaxBrzina;
    cout << "km/h, boja " << pBoja << "." << endl << endl;
    return 0;
};

//definisanje destruktora
kVozilo::~kVozilo()
{ 
    cout << "Vozilo je unisteno." << endl; 
};

int main()
{
    kVozilo oGolf("Golf", 160, "crvena");//objekat oGolf klase kVozilo
    kVozilo oZastava("Zastava", 120, "bela");//objekat oZastava klase kVozilo

    oGolf.fKojaKola();//poziv funkcije fKojaKola objekta oGolf
    oZastava.fKojaKola();//poziv funkcije fKojaKola objekta oZastava

    cout << endl;
    return 0;
}
