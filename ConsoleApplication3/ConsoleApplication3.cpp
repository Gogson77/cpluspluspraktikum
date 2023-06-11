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

    kArtikal(char pSi[10], char pNa[15], double pCe);

    int fKojiArtikal();

    ~kArtikal();
};

//definicija konstruktora
kArtikal::kArtikal(char pSi[10], char pNa[15], double pCe) 
{
    strcpy(pSifra, pSi);
    strcpy(pNaziv, pNa);
    pCena = pCe;
};

//definicija funkcije fKojiArtikal
int kArtikal::fKojiArtikal() {
    cout << "Ovo je artikal " << pNaziv << ", sifra mu je " << pSifra << " i kosta " << pCena << " dinara." << endl;
    return 0;
};

//definicija destruktora
kArtikal::~kArtikal() 
{
    cout << "Artikal je unisten.";
};

int main()
{
    kArtikal oCokolada("A123456789","Cokolada",0.50);//definicija objekta oCokolada klase kArtikal
    kArtikal oKola("B987654321","Kola", 1.55);//definicija objekta oKola klase kArtikal

    oCokolada.fKojiArtikal();
    oKola.fKojiArtikal();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
