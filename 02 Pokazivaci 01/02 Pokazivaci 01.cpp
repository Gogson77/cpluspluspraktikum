#include <iostream>

using namespace std;

class kFilm {
private:
	struct sIme {
		char pIme[15];
		char pPrezime[20];
	};

public:
	char pNaziv[25];
	sIme pReziser;
	int pBrGled;
	double pCijenaKarte;
	long int pHonorar;

	kFilm() {
		strcpy_s(pNaziv, "Nema");
		strcpy_s(pReziser.pIme, "Nema");
		strcpy_s(pReziser.pPrezime, "Nema");
		pBrGled = 0;
		pCijenaKarte = 0.00;
		pHonorar = 0;
	};

	int fUpisi() {
		cout << "Upisite naziv filma: "; 
		cin >> pNaziv;
		cout << "\nUpisite ime rezisera: "; 
		cin >> pReziser.pIme; 
		cout << "\nUpisite prezime rezisera: "; 
		cin >> pReziser.pPrezime; 
		cout << "\nUpisite broj gledalaca: "; 
		cin >> pBrGled; 
		cout << "\nUpisite cijena karte: "; 
		cin >> pCijenaKarte; 
		cout << endl;
		return 0;
	};

	int fIzracunajHonorar() {
		pHonorar = pBrGled * (int)pCijenaKarte;
		cout << "Film je ostvario honorar od ulaznica u vrijednosti od " << pHonorar << " dinara." << endl;
		return 0;
	};

	int fIspisi() {
		cout << "Film " << pNaziv << " je gledalo " << pBrGled << " gledalaca." << endl << endl;
		return 0;
	};

	~kFilm() { cout << "Film je zavrsen." << endl; };
};

class iZabava : public kFilm {
private:
	int fHonGlumca() {
		double pHonGlumca = pProfit * 0.20;
		cout << "Honorar glumca je " << pHonGlumca << " dinara" << endl << endl;
		return 0;
	};

public:
	long int pRashodi;
	double pPoreznaStopa;
	long int pPoreznaOsnovica;
	long int pPorez;
	long int pProfit;

	iZabava() : kFilm() {
		pRashodi = 0;
		pPoreznaStopa = 0.00;
		pPoreznaOsnovica = 0;
		pPorez = 0;
		pProfit = 0;
	};

	int fUpisi() {
		cout << "Upisite naziv filma: "; 
		cin >> pNaziv;
		cout << "\nUpisite broj gledalaca: "; 
		cin >> pBrGled;
		cout << "\nUpisite cijenu karte: "; 
		cin >> pCijenaKarte;
		cout << "\nUpisite troskove filma: "; 
		cin >> pRashodi;
		cout << "\nUpisite poreznu stopu: "; 
		cin >> pPoreznaStopa; 
		cout << endl;
		return 0;
	};

	int fIzracunajProfit() {
		pHonorar = pBrGled * (int)pCijenaKarte;
		pPoreznaOsnovica = pHonorar - pRashodi;
		pPorez = (pPoreznaOsnovica * (int)pPoreznaStopa) / 100;
		pProfit = pHonorar - pRashodi - pPorez;
		return 0;
	};

	int fZabIspisi() {
		kFilm::fIspisi();
		cout << pProfit << " dinara PROFITA = " << pHonorar << " dinara HONORARA - " << pRashodi << " dinara TROSKOVA - " << pPorez << " dinara POREZA" << endl << "porez = POREZNA STOPA " << pPoreznaStopa << "% na OSNOVICU od " << pPoreznaOsnovica << " dinara, osnovica = " << pHonorar << " honorar - " << pRashodi << " rashodi" << endl << endl;
		return 0;
	};

	int fGlumac() {
		fHonGlumca();
		return 0;
	};

	~iZabava() { cout << "Zabava je zavrsena." << endl; };
};


int main()
{
	kFilm oMojFilm;
	oMojFilm.fUpisi();
	oMojFilm.fIzracunajHonorar();
	oMojFilm.fIspisi();

	iZabava oTvojFilm;
	oTvojFilm.fUpisi();
	oTvojFilm.fIzracunajProfit();
	oTvojFilm.fZabIspisi();
	oTvojFilm.fGlumac();

	iZabava oTriler;
	oTriler.fUpisi();
	oTriler.fIzracunajProfit();
	oTriler.fZabIspisi();
	oTriler.fGlumac();

	long int pUkupniProfit = 0;
	cout << "Unesi honorar od " << oMojFilm.pHonorar << " dinara za film " << oMojFilm.pNaziv
		<< ", zatim profit od " << oTvojFilm.pProfit << " dinara za film " << oTvojFilm.pNaziv
		<< " i profit od " << oTriler.pProfit << " dinara za film " << oTriler.pNaziv << " zaredom:" << endl;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		pUkupniProfit = pUkupniProfit + x;
	}
	cout << "To je ukupno " << pUkupniProfit << " dinara za tri filma ili u prosjeku " << pUkupniProfit / 3 << " dinara profita po filmu." << endl << endl;

	//	cout << "Prosjecni profit je " << (oMojFilm.pHonorar + oTriler.pProfit + oTvojFilm.pProfit) / 3 << " dinara" << endl;

	return 0;
}