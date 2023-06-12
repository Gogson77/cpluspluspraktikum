#include <iostream>
#include "Osoba.h"

int main()
{
    Osoba Nepoznati;
    Nepoznati.prikazPodataka();
    Nepoznati.mestoBoravka();
        
    Osoba pera ("Pera", "Peric", "0704956678943", "Beograd");
    pera.prikazPodataka();
    pera.mestoBoravka();

    Osoba mika("Mika", "Miric", "2603978669925", "Pancevo");
    mika.prikazPodataka();
    mika.mestoBoravka();

    return 0;
}
