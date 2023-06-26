#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class kKopirnica {
public:
    string pNaziv;
    struct {
        string pUlica;
        int pBroj;
        string pMjesto;
    } pAdresa;
    struct {
        double pMax;
        double pMin;
    } pCijena;


    int pStrana, pVrsta;

    kKopirnica(string naziv, string ulica,int broj, string mjesto,double maxCijena, double minCijena) {
        pNaziv = naziv;
        pAdresa.pUlica = ulica;
        pAdresa.pBroj = broj;
        pAdresa.pMjesto = mjesto;
        pCijena.pMax = maxCijena;
        pCijena.pMin = minCijena;
    };

    double fIzracunajCijenu() {
        if (pVrsta == 1 || pStrana <= 1000) {
            return pCijena.pMax * pStrana;
        } else if (pVrsta == 2 || pStrana > 1000) {
            return pCijena.pMin * pStrana;
        } 
    };

    void fPisiCijenu() {
        cout << "Cijena kopiranja u kopirnici " << pNaziv << ": " << fixed << setprecision(2) << fIzracunajCijenu() << endl << endl;
    };

    ~kKopirnica() { cout << "Zavrsetak rada koprinice." << endl; };
};


int main()
{
kKopirnica oJeftina("Antika", "Studenska", 22, "Beograd", 2.00, 0.60);

    cout << "Kopirnica: " << oJeftina.pNaziv << endl;
    cout << "Adresa: " << oJeftina.pAdresa.pUlica << " " << oJeftina.pAdresa.pBroj << ", " << oJeftina.pAdresa.pMjesto << endl;

    cout << "Unesi broj strana: ";
    cin >> oJeftina.pStrana;
    cout << "Unesi jednostranu= 1 ili dvostranu= 2 vrstu stampanja: ";
    cin >> oJeftina.pVrsta;

    oJeftina.fIzracunajCijenu();
    oJeftina.fPisiCijenu();

    kKopirnica oSkupa("KopiCentar", "Beogradska", 15, "Pancevo", 3.00, 0.90);

    cout << "Kopirnica: " << oSkupa.pNaziv << endl;
    cout << "Adresa: " << oSkupa.pAdresa.pUlica << " " << oSkupa.pAdresa.pBroj << ", " << oSkupa.pAdresa.pMjesto << endl;

    cout << "Unesi broj strana: ";
    cin >> oSkupa.pStrana;
    cout << "Unesi jednostranu= 1 ili dvostranu= 2 vrstu stampanja: ";
    cin >> oSkupa.pVrsta;

    oSkupa.fIzracunajCijenu();
    oSkupa.fPisiCijenu();


    return 0;
}