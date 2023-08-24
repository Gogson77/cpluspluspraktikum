#include <iostream>
#include <stdexcept>
using namespace std;

class Radnik {
private:
    string ime;
    int maticniBroj;
    double plata;
    double stimulacija;

public:
    void unosPodataka() {
        cout << "Unesite ime: ";
        cin >> ime;
        cout << "Unesite maticni broj: ";
        cin >> maticniBroj;
        cout << "Unesite platu: ";
        cin >> plata;

        while (true) {
            try {
                cout << "Unesite stimulaciju: ";
                cin >> stimulacija;

                if (stimulacija == 0) {
                    throw runtime_error("Nema stimulacije.");
                }
                else if (stimulacija < 0) {
                    throw runtime_error("Nedozvoljena stimulacija.");
                }
                else if (stimulacija > 0.3 * plata) {
                    throw runtime_error("Prevelika stimulacija.");
                }
                break;
            }
            catch (const exception& e) {
                cerr << "Greska: " << e.what() << " Ponovite unos." << endl;
            }
        }
    }

    void kreditiranje(double visinaKredita) {
        if (plata >= 2 * visinaKredita) {
            cout << "Kredit odobren." << endl;
        } else {
            throw runtime_error("Nemoguce odobriti kredit.");
        }
    }

    void pisiPlatu() {
        cout << "Plata: " << plata << endl;
    }

    void pisiStimulaciju() {
        cout << "Stimulacija: " << stimulacija << endl;
    }
};

int main() {
    Radnik* pokazivacNaRadnika = new Radnik(); 
    pokazivacNaRadnika->unosPodataka();

    int izbor;
    double visinaKredita;

    while (true) {
        cout << "\nIzaberite opciju:" << endl;
        cout << "1. Odobravanje kredita" << endl;
        cout << "2. Ispis plate" << endl;
        cout << "3. Ispis stimulacije" << endl;
        cout << "4. Izlaz" << endl;
        cin >> izbor;

        switch (izbor) {
        case 1:
            cout << "Unesite visinu kredita: ";
            cin >> visinaKredita;
            try {
                if(visinaKredita>0)
                    pokazivacNaRadnika->kreditiranje(visinaKredita);
                else { cout << "Nepravilan unos iznosa za kredit." << endl; }
            }
            catch (const exception& e) {
                cerr << "Greska: " << e.what() << endl;
            }
            break;

        case 2:
            pokazivacNaRadnika->pisiPlatu();
            break;

        case 3:
            pokazivacNaRadnika->pisiStimulaciju();
            break;

        case 4:
            delete pokazivacNaRadnika;
            cout << "Hvala na koristenju programa!" << endl;
            return 0;

        default:
            cout << "Nepostojeca opcija. Pokusajte ponovo." << endl;
            break;
        }
    }

    return 0;
}
