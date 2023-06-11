// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

class kArtikal
{
public:
    char pSifra[10];
    char pNaziv[15];
    double pCena;

    kArtikal(
        char pSi[10], 
        char pNa[15], 
        double pCe
    );//konstruktor

    int fKojiArtikal();

    ~kArtikal();
};

//definicija konstruktora
kArtikal::kArtikal(
    char pSi[10], 
    char pNa[15], 
    double pCe
    )
    {
    strcpy(pSifra, pSi);
    strcpy(pNaziv, pNa);
    pCena = pCe;
};

//definicija funkcije fKojiArtikal
int kArtikal::fKojiArtikal() 
{
    cout << "Ovo je artikal " << pNaziv << ", sifra mu je " << pSifra << " i kosta ";
    cout << pCena << " dinara." << endl;
    return 0;
};

//definicija destruktora
kArtikal::~kArtikal() 
{
    cout << "Artikal je unisten.";
};

int main()
{
    kArtikal oCokolada("123456789", "Cokolada", 0.50);//definicija objekta oCokolada klase kArtikal
    kArtikal oKola("987654321", "Kola", 1.55);//definicija objekta oKola klase kArtikal

    oCokolada.fKojiArtikal();
    oKola.fKojiArtikal();

    return 0;
}