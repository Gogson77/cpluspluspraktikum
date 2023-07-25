#include "kRadnici.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Unesite broj radnika: ";
    cin >> n;

    if (n > 0) {
        kRadnici oSpisak;
        oSpisak.unosRadnika(n);
        oSpisak.prikazRadnika(n);
    }
    else {
        cout << "Greska: Broj radnika mora biti veci od 0." << endl;
    }

    return 0;
}

/*
3. a)	Definisati strukturu  sRadnik  koja sadrži: (pokazivači, nizovi struktura i klase)
            pIme – ime radnika, dužine 20 karaktera,
            pMatBr  - matični broj radnika, dužine 13 karaktera,
            pGodine – godine starosti radnika,
            pPlata – prosečna plata radnika, zaokružena na dve decimale.
b)	Deklarisati klasu  kRadnici  koja  sadrži:
-	atribut  pPodaci, koji je tipa  sRadnik
-	konstruktor
-	funkcije za unos i prikaz niza od  n  radnika
-	destruktor
c)	Definisati tražene funkcije.
d)	Kreirati objekat  oSpisak  klase  kRadnici.
e)	Napisati glavni program koji proverava ispravnost napisanih funkcija.

Napomena: Zadatak raditi u tri datoteke.
*/