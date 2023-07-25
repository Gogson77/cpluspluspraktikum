#include "sortiranje.h"

#include <iostream>
#include "sortiranje.h"

using namespace std;

void unosNiza(int* niz, int n) {
    cout << "Unesite elemente niza: ";
    for (int i = 0; i < n; i++) {
        cin >> niz[i];
    }
}

void ispisNiza(int* niz, int n) {
    cout << "Sortirani niz: ";
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
}

void sortirajNiz(int* niz, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (niz[j] > niz[j + 1]) {
                int temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
        }
    }
}
