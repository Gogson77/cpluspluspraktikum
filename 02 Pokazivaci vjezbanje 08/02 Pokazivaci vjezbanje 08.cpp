#include <iostream>
using namespace std;

struct sIme {
	char pIme[15];
	char pPrezime[20];
};

class kKnjiga {
private:
	sIme pPisac;
	int pStrana;
public:
	char pNaziv[25];
	float pCijena;
	kKnjiga();
	void fUpis();
	void fIzracunaj(float pCijenaStrane, float *pCijenaKnjige);
	void fIspisi(float *pCijenaKnjige);
	~kKnjiga();
};

kKnjiga::kKnjiga() {
	strcpy_s(pPisac.pIme, "Nema");
	strcpy_s(pPisac.pPrezime, "Nema");
	strcpy_s(pNaziv, "Nema");
	pCijena = 0.00;
	pStrana = 0;	
};

void kKnjiga::fUpis(){
	cout << "Ime omiljene knjige je: ";
	cin >> pNaziv;
	cout << "Ime pisca je: ";
	cin >> pPisac.pIme;
	cout << "Prezime pisca je: ";
	cin >> pPisac.pPrezime;
	cout << "Koliko strana ima knjiga: ";
	cin >> pStrana;
	cout << endl;
};


void kKnjiga::fIzracunaj(float pCijenaStrane, float *pCijenaKnjige) {
	*pCijenaKnjige = pStrana * pCijenaStrane;
	pCijena = *pCijenaKnjige;
};

void kKnjiga::fIspisi(float* pCijenaKnjige)
{
	cout << "\nKnjiga " << pNaziv << " preko pokazivaca kosta " << *pCijenaKnjige << endl;
	cout << "Knjiga " << pNaziv << " preko atributa kosta " << pCijena << endl;
};


kKnjiga::~kKnjiga() {
	cout << "\nDestruktor se izvrsio." << endl << endl;
};

void main()
{
	float pCijena, pStrana;
	kKnjiga oDobra;
	oDobra.fUpis();
	pCijena = 0.00;
	cout << "\nUnesi cijenu strane: ";
	cin >> pStrana;
	oDobra.fIzracunaj(pStrana, &pCijena);
	cout << "\nCijena knjige van funkcije je " << pCijena;
	oDobra.fIspisi(&pCijena);
}