// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

//klasa kOsoba
class kOsoba
{
public:
    char pIme[15];
    char pPrezime[20];
    char pMatBroj[13];
    char pMesto[25];

    kOsoba(
        char pI[15], 
        char pP[20], 
        char pMBroj[13], 
        char pM[25]
    );

    int fKoSi();
    int fGdeSi();

    ~kOsoba();
};

//definisanje konstruktora
kOsoba::kOsoba
(
    char pI[15],
    char pP[20],
    char pMBroj[13],
    char pM[25]
 ){
    strcpy(pIme, pI);
    strcpy(pPrezime, pP);
    strcpy(pMatBroj, pMBroj);
    strcpy(pMesto, pM);
};

//definisanje funkcije fKoSi
int kOsoba::fKoSi()
{
    cout << "Ja sam " << pIme << " " << pPrezime << endl;
    cout << "Moj maticni broj je " << pMatBroj << endl;
    return 0;
};

//definisanje funkcije fGdeSi
int kOsoba::fGdeSi()
{
    cout << "Stanujem u " << pMesto << endl;
    return 0;
};

//definisanje destruktora
kOsoba::~kOsoba()
{
    cout << "Osoba je unistena." << endl;
};

int main()
{
    //objekat oJa klase kOsoba
    kOsoba oJa("Pera", "Peric", "0704956678943", "Beograd");

    //objekat oTi klase kOsoba
    kOsoba oTi("Mika", "Miric", "2603978669925", "Pancevo");

    oJa.fKoSi();//poziv funkcije fKoSi objekta oJa
    oJa.fGdeSi();//poziv funkcije fGdeSi objekta oJa

    oTi.fKoSi();//poziv funkcije fKoSi objekta oTi
    oTi.fGdeSi();//poziv funkcije fGdeSi objekta oTi

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
