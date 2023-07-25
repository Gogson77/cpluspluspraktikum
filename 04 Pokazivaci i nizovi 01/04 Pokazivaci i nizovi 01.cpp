#include <iostream>
#include "sortiranje.h"

using namespace std;

int main() {
    int n;
    int* niz;

    do {
        cout << "Unesite duzinu niza (0 za kraj): ";
        cin >> n;

        if (n <= 0) {
            break;
        }

        niz = new int[n];

        unosNiza(niz, n);
        sortirajNiz(niz, n);
        ispisNiza(niz, n);

        delete[] niz;
    } while (true);

    return 0;
}

/*
1. Napisati sledeće funkcije: (pokazivači i nizovi)
	a) za čitanje niza preko glavnog ulaza,
	b) za ispisivanje niza preko glavnog izlaza,
	c) za sortiranje niza po neopadajućem redosledu vrednosti elemenata.
Napisati glavni program koji korišćenjem navedenih funkacija pročita niz, uredi niz, ispiše niz i ponavlja prethodne korake sve dok je čitanje niza uspešno (tj. dok se za dužinu niza ne unese 0).
Zadatak raditi u tri datoteke.
*/