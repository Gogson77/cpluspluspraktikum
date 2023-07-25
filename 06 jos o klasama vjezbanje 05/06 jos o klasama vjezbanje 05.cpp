#include "kImenik.h"
#include <iostream>

using namespace std;

void fGreska(void);

int main() {

    kImenik* pokK;
    int i, n;
    cout << "Unesi broj prijatelja koje zelis da upises u imenik: ";
    cin >> n;
    pokK = new kImenik[n];
    if (pokK == NULL) fGreska();

    cout << "\n~~~~~~~~~~~~~~~~~~ UNOS ADRESA ~~~~~~~~~~~~~~~~~~" << endl;
    for (i = 0; i < n; i++)
        pokK[i].fUpis();

    int izbor = 1;

    while (izbor != 0) {
        cout << "\n===============M E N I===============\n"
            "\n1 - Ispis svih\n"
            "\n2 - Prikaz odredjenog\n"
            "\n0 - Kraj\n\n";

        cout << "Unesi svoj izbor: ";
        cin >> izbor;

        switch (izbor) {
        case 1:
            cout << "\n~~~~~~~~~~~~~~~~~~ISPIS ADRESA~~~~~~~~~~~~~~~~~~" << endl;
            for (i = 0; i < n; i++)
                pokK[i].fListaj();
            break;
        case 2:
            cout << "Unesi redni broj:";
            int rb;
            cin >> rb;
            if (rb >= 1 && rb <= n)
                pokK[rb - 1].fPrikazi();
            else
                cout << "Neispravan redni broj!\n";
            break;
        case 0:
            cout << "U imeniku se nalazi " << kImenik::pBroj << " osoba";
            cout << endl << endl;
            delete[] pokK;
            return 0;

        default:
            cout << "\nPogresan izbor!!!\n\n";
        }
    }

    delete[] pokK;
    return 0;
}

void fGreska(void) {
    cout << "Nije uspela dodela memorije." << endl;
    exit(1);
}
