#pragma once
#define MAX_IME 30

class kStedisa
{
    int pRedniBroj;
    char pIme[MAX_IME + 1];
    int pStedRacun;

public:

    double pStanje;

    static int pBrojac;

    kStedisa();

    void fUpis();

    void fUplata(double iznos);   
    void fIsplata(double iznos); 

    kStedisa operator++();
    kStedisa operator--();
    kStedisa& operator += (kStedisa pom);		// a += b
    kStedisa& operator -= (kStedisa pom);		// a -= b
    friend kStedisa operator + (kStedisa pom1, kStedisa pom2);  // c = a + b

    void fListaj();
    void fPrikazi();

    static void fIspisZaglavlja();
    static double fMax(const kStedisa* pokNizK);

    ~kStedisa();
};