#include <iostream>
#include "kFilm.h"

using namespace std;

int main() {
    kFilm* film = new kFilm();
    film->fUpis();
    int izbor;
    bool pKraj = false;
    while (!pKraj) 
    {
        cout << "(0)Izlaz (1)Honorar film (2)Honorar glumca " << endl;
        cin >> izbor;
        switch (izbor) 
        {
        case 1: film->fIzracunajFilm(); break;
        case 2: film->fIzracunajGlum(); break;
        default: pKraj = true; break;
        }
        if (pKraj) break;
    };
    film->fIspisi();
    delete film;
    return 0;
}