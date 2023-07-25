#include <iostream>
#include "kRadnici.h"

using namespace std;

kRadnici::kRadnici() {
    pPodaci = nullptr;
}

kRadnici::~kRadnici() {
    delete[] pPodaci;
}

void kRadnici::unosRadnika(int index) {
    if (index <= 0) {
        cout << "Greska: Index mora biti pozitivan broj." << endl;
        return;
    }

    pPodaci = new sRadnik[index];

    for (int i = 0; i < index; i++) {
        cout << "Unesite ime radnika " << i + 1 << ": ";
        cin.ignore();
        cin.getline(pPodaci[i].pIme, 20);

        cout << "Unesite maticni broj radnika " << i + 1 << ": ";
        cin.getline(pPodaci[i].pMatBr, 13);

        cout << "Unesite godine starosti radnika " << i + 1 << ": ";
        cin >> pPodaci[i].pGodine;

        cout << "Unesite platu radnika " << i + 1 << ": ";
        cin >> pPodaci[i].pPlata;
    }
}

void kRadnici::prikazRadnika(int index) {
    if (index <= 0) {
        cout << "Greska: Index mora biti pozitivan broj." << endl;
        return;
    }

    for (int i = 0; i < index; i++) {
        cout << "Podaci za radnika " << i + 1 << ":" << endl;
        cout << "Ime: " << pPodaci[i].pIme << endl;
        cout << "Maticni broj: " << pPodaci[i].pMatBr << endl;
        cout << "Godine: " << pPodaci[i].pGodine << endl;
        cout << "Plata: " << pPodaci[i].pPlata << endl;
        cout << endl;
    }
}
