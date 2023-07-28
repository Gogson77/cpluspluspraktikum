#include "kStedisa.h"
#include <iostream>

using namespace std;

typedef void (kStedisa::* pokFArg)(double);
typedef void (kStedisa::* pokF)();

int main()
{
    int n;
    cout << "Koliko stednih racuna zelite otvoriti za unos: ";
    cin >> n;
    cout << endl;

    kStedisa* pokNizK = new kStedisa[n];

    for (int i = 0; i < n; i++) {
        pokNizK[i].fUpis();
    }

    pokFArg pokFUplata = &kStedisa::fUplata;
    pokFArg pokFIsplata = &kStedisa::fIsplata;
    pokF pokFListaj = &kStedisa::fListaj;
    pokF pokFPrikazi = &kStedisa::fPrikazi;

    int izbor = -1;
    double iznos;
    int rbr;

    while (izbor != 0)
    {
        cout << "(0)Izlaz\t(1)Uplata\t(2)Isplata\n(3)Listaj\t(4)Prikazi\t(5)Max" << endl;
        cin >> izbor;

        switch (izbor)
        {
        case 0:
            izbor = 0;
            break;
        case 1:
            for (int i = 0; i < n; i++) {
                cout << "Unesite iznos uplate na racun pod rednim brojem " << i+1 << ": ";
                cin >> iznos;
                pokNizK[i].pStanje += iznos;
                //(pokNizK[i].*pokFUplata)(iznos);
            }
            cout << endl;
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                cout << "Unesite iznos isplate sa racuna pod rednim brojem " << i+1 << ": ";
                cin >> iznos;
                pokNizK[i].pStanje -= iznos;
                //(pokNizK[i].*pokFIsplata)(iznos);
            }
            cout << endl;
            break;
        case 3:
            kStedisa::fIspisZaglavlja();
            for (int i = 0; i < n; i++) {
                (pokNizK[i].*pokFListaj)();
            }
            cout << endl;
            break;
        case 4:
            cout << "Unesite redni broj racuna stedise koji zelite prikazati: ";
            cin >> rbr;
            kStedisa::fIspisZaglavlja();
            (pokNizK[rbr - 1].*pokFPrikazi)();
            cout << endl;
            break;
        case 5:
            kStedisa::fIspisZaglavlja();
            kStedisa::fMax(pokNizK);
            break;
        default:
            cout << "Neispravan odabir\n\n";
        }
    }

    delete[] pokNizK;

    return 0;
}