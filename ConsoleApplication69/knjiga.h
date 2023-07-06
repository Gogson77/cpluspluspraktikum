#ifndef KNJIGA_H
#define KNJIGA_H

struct sIme {
    char pIme[15];
    char pPrezime[20];
};

enum eFormat {
    tvrdi,
    meki,
    dzepno
};

class kKnjiga {
public:
    char pNaziv[25];
    eFormat pFormat;
    sIme pPisac;
    char pIzdavac[20];
    int pBrStrana;
    double pPopust;
    int pProdato;

public:
    kKnjiga(const char* naziv, eFormat format, const sIme& pisac, const char* izdavac, int brStrana, double popust, int prodato);
    void fUpis();
    void fIzracunaj();
    void fIspisi();
    void fHonorar();
    ~kKnjiga();
};

class iRoman : public kKnjiga {
private:
    double pRashodi;
    double pProc;

public:
    iRoman(const char* naziv, eFormat format, const sIme& pisac, const char* izdavac, int brStrana, double popust, int prodato, double rashodi, double proc);
    void fUpis();
    double fIzracunaj();
    void fRomanIspisi();
    void fPisac();
    ~iRoman();
};

#endif
