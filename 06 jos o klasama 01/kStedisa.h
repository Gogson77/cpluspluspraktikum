#pragma once
#define MAX_IME 30

class kStedisa
{
    int pRedniBroj;
    char pIme[MAX_IME + 1];
    int pStedRacun;
    double pStanje;

public:
    static int pBrojac; 

    kStedisa();

    void fUpis();
    void fUplata(double);
    void fIsplata(double);
    void fListaj();
    void fPrikazi();

    static void fIspisZaglavlja();
    static double fMax(const kStedisa* pokNizK);

    ~kStedisa();
};