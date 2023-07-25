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

public:
    kFilm();

    void fUpis();
    void fIzracunajFilm();
    void fIzracunajGlum();
    void fIspisi();

    ~kFilm();
};