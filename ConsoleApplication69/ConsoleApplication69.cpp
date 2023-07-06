#include "knjiga.h"
#include <iostream>

using namespace std;

int main()
{
    // Kreiranje objekata
    kKnjiga oMat("Matematika 1", tvrdi, { "Marko", "Markovic" }, "Izdavac 1", 200, 10, 1000);
    kKnjiga oProgram("Programiranje", meki, { "Ana", "Anic" }, "Izdavac 2", 300, 15, 1500);
    iRoman oDrama("Drama 1", meki, { "Petar", "Petrovic" }, "Izdavac 3", 150, 20, 500, 2000, 10);
    iRoman oKrimi("Krimi 1", dzepno, { "Jovan", "Jovanovic" }, "Izdavac 4", 100, 10, 800, 1000, 20);

    // Unos vrednosti objekata
    oMat.fUpis();
    oProgram.fUpis();
    oDrama.fUpis();
    oKrimi.fUpis();

    // Izračunavanje cene i ispis za objekte klase kKnjiga
    oMat.fIzracunaj();
    oMat.fIspisi();
    oProgram.fIzracunaj();
    oProgram.fIspisi();

    // Izračunavanje cene i ispis za objekte klase iRoman
    oDrama.fIzracunaj();
    oDrama.fRomanIspisi();
    oKrimi.fIzracunaj();
    oKrimi.fRomanIspisi();

    // Pozivanje funkcije fHonorar za objekte klase kKnjiga
    oMat.fHonorar();
    oProgram.fHonorar();

    // Pozivanje funkcije fPisac za objekte klase iRoman
    oDrama.fPisac();
    oKrimi.fPisac();

    return 0;
}
