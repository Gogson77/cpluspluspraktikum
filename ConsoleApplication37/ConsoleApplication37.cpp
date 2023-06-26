#include <iostream>
#include <string>
using namespace std;

class kKopirnica {
public:
    struct sAdresa {
        string pUlica;
        int pBroj;
        string pMjesto;
    } pAdresa;

    struct sCijena {
        double pMax;
        double pMin;
    } pCijena;

    string pNaziv;
    int pStrana;
    int pVrsta;
    double iznos;

    kKopirnica(
        string naziv, 
        string ulica, 
        int broj, 
        string mjesto,
        double maxCijena, 
        double minCijena) {
        pNaziv = naziv;
        pAdresa.pUlica = ulica;
        pAdresa.pBroj = broj;
        pAdresa.pMjesto = mjesto;
        pCijena.pMax = maxCijena;
        pCijena.pMin = minCijena;
    };

    void fIzracunajCijenu() {
        if (pStrana >= 1000 && pVrsta == 1) {
            iznos = pCijena.pMax * pStrana;
        }
        else if (pStrana > 1000 && pVrsta == 2) {
            iznos = pCijena.pMin * pStrana;
        }
    };

    void fPisiCijenu() { 
        cout << "Iznos: " << iznos << endl << endl; };

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