// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

//klasa kVozilo
class kVozilo {
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
    char pBo[15] ) 
{
    strcpy(pNaziv, pNaz);
    pMaxBrzina = pMax;
    strcpy(pBoja, pBo);
};

//definisanje funkcije fKojaKola
int kVozilo::fKojaKola()
{
    cout << "\nOvo je "<<pNaziv<<", maksimalna brzina mu je "<<pMaxBrzina<<"km/h, boja "<<pBoja<<"."<<endl<<endl;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
