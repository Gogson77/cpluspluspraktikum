#include "knjiga.h"
#include <iostream>

using namespace std;

kKnjiga::kKnjiga(const char* naziv, eFormat format, const sIme& pisac, const char* izdavac, int brStrana, double popust, int prodato)
{
    strcpy_s(pNaziv, naziv);
    pFormat = format;
    strcpy_s(pPisac.pIme, pisac.pIme);
    strcpy_s(pPisac.pPrezime, pisac.pPrezime);
    strcpy_s(pIzdavac, izdavac);
    pBrStrana = brStrana;
    pPopust = popust;
    pProdato = prodato;
}

void kKnjiga::fUpis()
{
    cout << "Unesite naziv knjige: ";
    cin.getline(pNaziv, 25);

    int format;
    cout << "Unesite format knjige (0 - tvrdi, 1 - meki, 2 - dzepno): ";
    cin >> format;
    cin.ignore();
    pFormat = static_cast<eFormat>(format);

    cout << "Unesite ime pisca: ";
    cin.getline(pPisac.pIme, 15);

    cout << "Unesite prezime pisca: ";
    cin.getline(pPisac.pPrezime, 20);

    cout << "Unesite naziv izdavaca: ";
    cin.getline(pIzdavac, 20);

    cout << "Unesite broj strana knjige: ";
    cin >> pBrStrana;

    cout << "Unesite procenat popusta: ";
    cin >> pPopust;

    cout << "Unesite broj prodatih primjeraka knjige: ";
    cin >> pProdato;
}

void kKnjiga::fIzracunaj()
{
    double cenaStrane;

    switch (pFormat) {
    case tvrdi:
        cenaStrane = 10;
        break;
    case meki:
        cenaStrane = 8;
        break;
    case dzepno:
        cenaStrane = 5;
        break;
    default:
        cout << "Nepoznat format knjige!" << endl;
        return;
    }

    double cenaKnjige = pBrStrana * cenaStrane * (1 - pPopust / 100);
    cout << "Cena knjige: " << cenaKnjige << " dinara" << endl;
}

void kKnjiga::fIspisi()
{
    cout << "Ovo je knjiga " << pNaziv << " koja ima " << pBrStrana << " strana i formata je ";

    switch (pFormat) {
    case tvrdi:
        cout << "tvrdi";
        break;
    case meki:
        cout << "meki";
        break;
    case dzepno:
        cout << "dzepno";
        break;
    default:
        cout << "nepoznat";
        break;
    }

    cout << "." << endl;
    cout << "Napisao je " << pPisac.pIme << " " << pPisac.pPrezime << "." << endl;
    cout << "Knjigu je izdao " << pIzdavac << "." << endl;
    cout << "Knjiga je trenutno na popustu od " << pPopust << " procenata." << endl;
}

void kKnjiga::fHonorar()
{
    double honorar = pProdato * 50 + 50000;
    cout << "Honorar pisca: " << honorar << " dinara" << endl;
}

kKnjiga::~kKnjiga()
{
    cout << "Knjiga je procitana." << endl;
}

iRoman::iRoman(const char* naziv, eFormat format, const sIme& pisac, const char* izdavac, int brStrana, double popust, int prodato, double rashodi, double proc)
    : kKnjiga(naziv, format, pisac, izdavac, brStrana, popust, prodato)
{
    pRashodi = rashodi;
    pProc = proc;
}

void iRoman::fUpis()
{
    kKnjiga::fUpis();

    cout << "Unesite ostvarene rashode prilikom izdavanja knjige: ";
    cin >> pRashodi;

    cout << "Unesite procenat poreza: ";
    cin >> pProc;
}

double iRoman::fIzracunaj()
{
    double cenaStrane;

    switch (pFormat) {
    case tvrdi:
        cenaStrane = 10;
        break;
    case meki:
        cenaStrane = 8;
        break;
    case dzepno:
        cenaStrane = 5;
        break;
    default:
        cout << "Nepoznat format knjige!" << endl;
        return 0; // Vratiti neku podrazumevanu vrednost ili rukovati greškom na odgovarajući način
    }

    double troskovi;

    if (pProc > 15)
        troskovi = (pProc / 100 + 0.5) * pRashodi;
    else
        troskovi = ((pProc + 1.5) / 100 + 1) * pRashodi;

    double cenaRomana = pBrStrana * cenaStrane - troskovi;
    return cenaRomana;
}

void iRoman::fRomanIspisi()
{
    kKnjiga::fIspisi();
    double cenaRomana = fIzracunaj();
    cout << "Roman kosta " << cenaRomana << " dinara." << endl;
}

void iRoman::fPisac()
{
    kKnjiga::fHonorar();
}

iRoman::~iRoman()
{
    cout << "Roman " << pNaziv << " je odlican." << endl;
}
