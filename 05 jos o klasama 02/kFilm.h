#pragma once

struct sIme {
    char pIme[15];
    char pPrezime[20];
};

class kFilm {
private:
    char pNaziv[25];
    sIme pReziser;
    double honorarFilm;
    double honorarGlum;
    int brojGledalaca;
    double cenaKarte;
    double brojSati;
    double cenaSata;

public:
    kFilm();

    void fUpis();
    void fIzracunajFilm(int& brojGledalaca, double& cenaKarte);
    void fIzracunajGlum(double& brojSati, double& cenaSata);
    void fIspisi();

    ~kFilm();
};