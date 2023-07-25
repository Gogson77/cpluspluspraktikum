#include <iostream>
#include "izbacivanje_elementa.h"

using namespace std;

int main() {
    int n;
    int* niz;

    cout << "Unesite duzinu niza: ";
    cin >> n;

    if (n > 0) {
        niz = new int[n];
        cout << "Unesite elemente niza: ";
        for (int i = 0; i < n; i++) {
            cin >> niz[i];
        }

        int trazenaVrednost;
        cout << "Unesite vrednost koju zelite izbaciti: ";
        cin >> trazenaVrednost;

        izbaciElement(niz, n, trazenaVrednost);

        cout << "Niz nakon izbacivanja:" << endl;
        for (int i = 0; i < n; i++) {
            cout << niz[i] << " ";
        }
        cout << endl;

        delete[] niz;
    }
    else {
        cout << "Greska: Niz mora imati bar jedan element." << endl;
    }

    return 0;
}

/*
2. Iz realnog niza izbaciti sve elemente koji su jednaki zadatoj vrednosti. Izbaciti znači pomeriti za jedno mesto ulevo i smanjiti dužinu niza za jedan.(lab 2-3) (pokazivači i nizovi)
*/