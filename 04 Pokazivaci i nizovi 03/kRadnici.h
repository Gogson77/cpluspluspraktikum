#ifndef KRADNICI_H
#define KRADNICI_H

struct sRadnik {
    char pIme[20];
    char pMatBr[13];
    int pGodine;
    double pPlata;
};

class kRadnici {
private:
    sRadnik* pPodaci;
public:
    kRadnici();
    ~kRadnici();

    void unosRadnika(int index);
    void prikazRadnika(int index);
};

#endif // KRADNICI_H