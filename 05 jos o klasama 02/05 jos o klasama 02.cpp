#include "kFilm.h"
#include <iostream>

using namespace std;

int main() {
    kFilm* film = new kFilm();
    film->fUpis();

    int izbor;
    bool pKraj = false;

    while (!pKraj)
    {
        cout << "\n(1)Izracunaj dobit filma\t(2)Izracunaj honorar glumca\t(3)Prekid:" << endl;
        cin >> izbor;
        switch (izbor)
        {
        case 1: {
            cout << "Unesite broj gledalaca: ";
            int bG;
            cin >> bG;
            cout << "Unesite cenu karte: ";
            double cK;
            cin >> cK;
            film->fIzracunajFilm(bG, cK);
            break;
        }
        case 2: {
            cout << "Unesite broj sati koje je glumac proveo na snimanju: ";
            double bS;
            cin >> bS;
            cout << "Unesite cenu sata glumca: ";
            double cS;
            cin >> cS;
            film->fIzracunajGlum(bS, cS);
            break;
        }
        case 3: {
            pKraj = true;
            break;
        }
        default:
            cout << "\nPogresan unos\n";
            break;
        }
    };

    delete film;
    return 0;
}