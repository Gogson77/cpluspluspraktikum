#include <iostream>

using namespace std;

struct sIme {
	char pIme[15];
	char pPrezime[20];
};

class kFilm {
public:
	char pNaziv[25];
	sIme pReziser;
	int pBrGled;
	float pCijenaKarte;
	float pHonorar;
	kFilm();
	void fUpis();
	void fIzracunaj();
	void fIspisi();
	~kFilm();
};

kFilm::kFilm() {
	strcpy_s(pNaziv, "Nema");
	strcpy_s(pReziser.pIme, "Nema");
	strcpy_s(pReziser.pPrezime, "Nema");
	pBrGled = 0;
	pCijenaKarte = 0.00;
	pHonorar = 0;
};

void kFilm::fUpis(){
	cout << "Upisite naziv filma : "; cin >> pNaziv;
	cout << "Upisite ime rezisera: "; cin >> pReziser.pIme;
	cout << "Upisite prezime rezisera: "; cin >> pReziser.pPrezime;
};

void kFilm::fIzracunaj(){ 
	cout << "Upisite broj gledalaca: "; cin >> pBrGled;
	cout << "Upisite cijenu karte: "; cin >> pCijenaKarte;
	cout << endl;
	pHonorar = pBrGled * pCijenaKarte;
};

void kFilm::fIspisi(){
	cout << "Film " << pNaziv  << " je ostvario honorar od od " << pHonorar/1000000 << " miliona dolara." << endl << endl;
};

kFilm::~kFilm() { cout << "Film je zavrsen." << endl << endl; }

void main()
{
	kFilm oTriler;
	oTriler.fUpis();
	oTriler.fIzracunaj();
	oTriler.fIspisi();
}