#include <iostream>
#include "kFilm.h"

using namespace std;

kFilm::kFilm() {
    strcpy_s(pNaziv, "");
    strcpy_s(pReziser.pIme, "");
    strcpy_s(pReziser.pPrezime, "");
    honorarFilm = 0.00;
    honorarGlum = 0.00;
}

void kFilm::fUpis() {
    cout << "Unesite naziv filma: ";
    cin.getline(pNaziv, 25);
    cout << "Unesite ime rezisera: ";
    cin.getline(pReziser.pIme, 15);
    cout << "Unesite prezime rezisera: ";
    cin.getline(pReziser.pPrezime, 20);
}

void kFilm::fIzracunajFilm() {
    int brojGledalaca;
    double cenaKarte;
    cout << "Unesite broj gledalaca: ";
    cin >> brojGledalaca;
    cout << "Unesite cenu karte: ";
    cin >> cenaKarte;
    honorarFilm = brojGledalaca * cenaKarte;
    cout << "Honorar za film " << pNaziv << " je " << honorarFilm << " dinara." << endl;
}

void kFilm::fIzracunajGlum() {
    double brojSati;
    double cenaSata;
    cout << "Unesite broj sati koje je glumac proveo na snimanju: ";
    cin >> brojSati;
    cout << "Unesite cenu sata glumca: ";
    cin >> cenaSata;
    honorarGlum = brojSati * cenaSata;
    cout << "Honorar za glumca filma " << pNaziv << " je " << honorarGlum << " dinara." << endl;
}

void kFilm::fIspisi() {
    cout << "Honorar za film " << pNaziv << " je " << honorarFilm << " dinara." << endl;
    cout << "Honorar za glumca filma " << pNaziv << " je " << honorarGlum << " dinara." << endl;
}

kFilm::~kFilm() {cout << "Film je zavrsen." << endl; }