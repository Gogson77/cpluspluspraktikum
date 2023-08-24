#include <iostream>
#include <fstream>
using namespace std;

class Radnik {
public:
    Radnik() {};
    ~Radnik() {};

    char* dohvatiIme() { return ime; }
    int dohvatMaticniBroj() { return maticniBroj;  }
    double dohvatiPlata() { return plata; }

    void upis();

    void upisImena(char* im) { strcpy_s(ime, im); }
    void upisMaticniBroj(int mb) { maticniBroj = mb; }
    void upisPlata(double pl) { plata = pl; }

private:
    char ime[20];
    int maticniBroj;
    double plata;
};

void Radnik::upis() {
    cout << "\nUnesi ime: ";
    cin >> ime;
    cout << "Unesi maticni broj: ";
    cin >> maticniBroj;
    cout << "Unesi iznos plate: ";
    cin >> plata;
}

int main()
{
    Radnik radnik;
    char imeDatoteke[80];
    char pom;
    int izbor=1;

    cout << "Unesi ime datoteke: ";
    cin >> imeDatoteke;

    //upisivanje datoteke
    ofstream fout(imeDatoteke, ios::app); //otvara datoteku za pisanje
    radnik.upis();
    fout << radnik.dohvatiIme() << " ";
    fout << radnik.dohvatMaticniBroj() << " ";
    fout << radnik.dohvatiPlata() << endl;

    //ispisivanje datoteke
    ifstream fin(imeDatoteke); //otvara datoteku za citanje
    cout << "\n\nSadrzaj datoteke:" << endl << endl;
    while (fin.get(pom))
        cout << pom;
    fin.close();

    //dodavanje slogova na kraj datoteke
    while (izbor!=0)
    {
        cout << "\nHoces li da upisujes jos slogova u datoteku(da-1 ili ne-0)?" << endl;
        cin >> izbor;
        if (izbor == 0) break;

        radnik.upis();
        fout << radnik.dohvatiIme() << " ";
        fout << radnik.dohvatMaticniBroj() << " ";
        fout << radnik.dohvatiPlata() << endl;
    }
    fout.close();

    //ispisivanje sadrzaja datoteke
    fin.open(imeDatoteke); //otvara datoteku za citanje
    cout << "\n\nSadrzaj datoteke:" << endl << endl;
    while (fin.get(pom))
        cout << pom;
    fin.close();

    cout << endl;
    return 0;
}