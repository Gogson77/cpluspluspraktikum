#include <iostream>
#include <string>

using namespace std;

class kPice {
protected:
    string pNaziv;
    double pCena;

public:
    kPice(string naziv, double cena) : pNaziv(naziv), pCena(cena) {}
    virtual ~kPice() {}

    virtual void fUpisPica() {
        cout << "Unesite naziv pica: ";
        getline(cin >> ws, pNaziv);

        cout << "Unesite cenu pica: ";
        cin >> pCena;
    }

    double fDohvatiCenu() const {
        return pCena;
    }

    static double fUkupnaCena(kPice** piceNiz, int brojPica) {
        double ukupnaCena = 0;
        for (int i = 0; i < brojPica; i++) {
            ukupnaCena += piceNiz[i]->fDohvatiCenu();
        }
        return ukupnaCena;
    }

    static void fListaj(kPice** piceNiz, int brojPica) {
        cout << "Lista svih pica:" << endl;
        for (int i = 0; i < brojPica; i++) {
            cout << "Naziv: " << piceNiz[i]->pNaziv << ", Cena: " << piceNiz[i]->pCena << endl;
        }
    }
};

class iKoktel : public kPice {
private:
    string pIme;

public:
    iKoktel(string naziv, double cena) : kPice(naziv, cena) {}
    ~iKoktel() {}

    void fUpis() {
        cout << "Unesite ime koktela: ";
        getline(cin >> ws, pIme);
    }

    double fCena(kPice** piceNiz, int brojPica) {
        double ukupnaCenaPica = kPice::fUkupnaCena(piceNiz, brojPica);
        return ukupnaCenaPica * 0.5;
    }

    // Public getter function for pIme
    string getIme() const {
        return pIme;
    }
};

int main() {
    const int MAX_PICA = 100;
    kPice** piceNiz = new kPice * [MAX_PICA];
    int brojPica = 0;

    int opcija;
    do {
        cout << "\nMeni:" << endl;
        cout << "1 - Unos pica" << endl;
        cout << "2 - Ukupna cena pica" << endl;
        cout << "3 - Unos koktela" << endl;
        cout << "4 - Cena koktela" << endl;
        cout << "0 - Izlaz" << endl;
        cout << "Izaberite opciju: ";
        cin >> opcija;

        switch (opcija) {
        case 1: {
            if (brojPica >= MAX_PICA) {
                cout << "Dostignut maksimalan broj pica." << endl;
            }
            else {
                piceNiz[brojPica] = new kPice("", 0);
                piceNiz[brojPica]->fUpisPica();
                brojPica++;
            }
            break;
        }
        case 2: {
            if (brojPica == 0) {
                cout << "Unesite barem jedno pice pre nego sto racunate ukupnu cenu." << endl;
            }
            else {
                double ukupnaCena = kPice::fUkupnaCena(piceNiz, brojPica);
                cout << "Ukupna cena pica: " << ukupnaCena << endl;
            }
            break;
        }
        case 3: {
            if (brojPica == 0) {
                cout << "Unesite barem jedno pice pre nego sto unosite koktel." << endl;
            }
            else {
                piceNiz[brojPica] = new iKoktel("", 0);
                piceNiz[brojPica]->fUpisPica();
                iKoktel* koktel = dynamic_cast<iKoktel*>(piceNiz[brojPica]);
                if (koktel != nullptr) {
                    koktel->fUpis(); // Pozivamo funkciju fUpis() za unos imena koktela
                }
                else {
                    cout << "Greska pri pravljenju koktela." << endl;
                }
                brojPica++;
            }
            break;
        }
        case 4: {
            if (brojPica == 0) {
                cout << "Unesite barem jedno pice pre nego sto racunate cenu koktela." << endl;
            }
            else {
                piceNiz[brojPica] = new iKoktel("", 0);
                piceNiz[brojPica]->fUpisPica();
                iKoktel* koktel = dynamic_cast<iKoktel*>(piceNiz[brojPica]);
                if (koktel != nullptr) {
                    koktel->fUpis(); // Pozivamo funkciju fUpis() za unos imena koktela
                    double cenaKoktela = koktel->fCena(piceNiz, brojPica);
                    cout << "Cena koktela '" << koktel->getIme() << "': " << cenaKoktela << endl;
                }
                else {
                    cout << "Greska pri pravljenju koktela." << endl;
                }
                brojPica++;
            }
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << "Nepoznata opcija. Pokusajte ponovo." << endl;
            break;
        }
        }

    } while (opcija != 0);

    for (int i = 0; i < brojPica; i++) {
        delete piceNiz[i];
    }
    delete[] piceNiz;

    return 0;
}
