# include <iostream>
using namespace std;

// klasa kVozilo
class kVozilo
{
    public:
        char pNaziv[15];
        int pMaxBrzina;
        char pBoja[15];
    kVozilo( char pNaz[15], int pMax, char pBo[15] ); // konstruktor
    int fKojaKola( char pNaziv[15], int pMaxBrzina, char pBoja[15] ); // funkcija fKojaKola
    ~kVozilo(); // destruktor
};

// definisanje konstruktora
kVozilo::kVozilo( char pNaz[15], int pMax, char pBo[15] )
{ strcpy (pNaziv,pNaz); pMaxBrzina = pMax; strcpy (pBoja, pBo); };

// definisanje funkcije fKojaKola
int kVozilo::fKojaKola( char pNaziv[15], int pMaxBrzina, char pBoja[15])
{ cout << "\nOvo je " << pNaziv << ", maksimalna brzina mu je " << pMaxBrzina << " km/h, boja " << pBoja << "." << endl << endl;
return 0; };

// definisanje destruktora
kVozilo::~kVozilo(){ cout << "Ja sam destruktor." << endl; };

int main(){
kVozilo oMoje ("Zastava", 120, "plava"); // poziva se konstruktor
cout << "Ovo je " << oMoje.pNaziv << ", maksimalna brzina mu je " << oMoje.pMaxBrzina << " km/h, boja " << oMoje.pBoja << "." << endl;

oMoje.fKojaKola ("Golf", 160, "crvena"); // poziva se funkcija fKojaKola
cout << "Ovo je " << oMoje.pNaziv << ", maksimalna brzina mu je " << oMoje.pMaxBrzina << " km/h, boja " << oMoje.pBoja << "." << endl;
cout << endl;
return 0;
}