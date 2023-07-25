#include "kFilm.h"
#include <iostream>

using namespace std;

kFilm::kFilm() {
    strcpy_s(pNaziv, "");
    strcpy_s(pReziser.pIme, "");
    strcpy_s(pReziser.pPrezime, "");
    honorarFilm = 0.00;
    honorarGlum = 0.00;
    brojGledalaca = 0;
    cenaKarte = 0.00;
    brojSati = 0.00;
    cenaSata = 0.00;
}

void kFilm::fUpis() {
    cout << "Unesite naziv filma: ";
    cin.getline(pNaziv, 25);
    cout << "Unesite ime rezisera: ";
    cin.getline(pReziser.pIme, 15);
    cout << "Unesite prezime rezisera: ";
    cin.getline(pReziser.pPrezime, 20);
}

void kFilm::fIzracunajFilm(int& brojGledalaca, double& cenaKarte) {
    honorarFilm = brojGledalaca * cenaKarte;
    fIspisi();
}

void kFilm::fIzracunajGlum(double& brojSati, double& cenaSata) {
    honorarGlum = brojSati * cenaSata;
    fIspisi();
}

void kFilm::fIspisi() {
    cout << "\nHonorar za film " << pNaziv << " je " << honorarFilm << " dinara." << endl;
    cout << "Honorar za glumca filma " << pNaziv << " je " << honorarGlum << " dinara." << endl;
}

kFilm::~kFilm() { cout << "\nFilm je zavrsen." << endl; }