#include "izbacivanje_elementa.h"

void izbaciElement(int*& niz, int& n, int trazenaVrednost) {
    int indeksBrisanja = -1;
    for (int i = 0; i < n; i++) {
        if (niz[i] == trazenaVrednost) {
            indeksBrisanja = i;
            break;
        }
    }

    if (indeksBrisanja != -1) {
        for (int i = indeksBrisanja; i < n - 1; i++) {
            niz[i] = niz[i + 1];
        }
        n--;
    }
}
