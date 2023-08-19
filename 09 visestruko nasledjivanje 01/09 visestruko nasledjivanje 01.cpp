#include <iostream>
#include <string.h>
using namespace std;

class kPica {
private:
	char pNaziv[15];
	char pProizvodjac[20];
public:
	kPica();
	void fUpisivanje();
	void fIspisivanje() const;
	~kPica() {};
};

kPica::kPica(){
	strcpy_s(pNaziv, "");
	strcpy_s(pProizvodjac, "");
}

void kPica::fUpisivanje() {
	cout << "\nUpisi naziv pica: ";
	cin >> pNaziv;
	cout << "\nUpisi proizvodjaca: ";
	cin >> pProizvodjac;
}

void kPica::fIspisivanje() const {
	cout << "\nNaziv pica: ";
	cout << pNaziv;
	cout << "\nProizvodjac: ";
	cout << pProizvodjac;
}

class iKupljenaPica : public kPica {
private:
	char pSifra[15];
	int pRedniBroj;
	double pKolLitUKom;
	double pNabCPoKom;
	int pBrKomUPak;
	int pBrNabPak;
	//typedef 
		enum eStatus { na_skladistu = 0, aktivan = 1, potrosen = 2  };
	//typedef 
		enum eNacinPlac { kes = 0, racun = 1, kredit = 3 };
	//typedef 
		enum ePlaceno { da, ne };
	struct sRobuPrimio { char pIme[15]; char pPrezime[20]; };
	
	kPica oPica;
public:
	static double pUkupnaNabCijena;
	eStatus pStatus;
	eNacinPlac pNacinPlac;
	ePlaceno pPlaceno;
	sRobuPrimio pRobuPrimio;
	iKupljenaPica();
	void fUpisivanje();
	void fIspisivanje(kPica*, int);
	double fUkupnaNabCijena();
	~iKupljenaPica() {};
};

double iKupljenaPica::pUkupnaNabCijena(0.00);

iKupljenaPica::iKupljenaPica() {
	strcpy_s(pSifra, "");
	pRedniBroj = 0;
	pKolLitUKom = 0.00;
	pNabCPoKom = 0.00;
	pBrKomUPak = 0;
	pBrNabPak = 0;
	pStatus = potrosen;
	pNacinPlac = kes;
	pPlaceno = ne;
	strcpy_s(pRobuPrimio.pIme, "");
	strcpy_s(pRobuPrimio.pPrezime, "");
}

void iKupljenaPica::fUpisivanje() {
	kPica *pokPica = new kPica;
	pokPica->fUpisivanje();
	++pRedniBroj;
	cout << "\nUpisi kolicinu u litrima: ";
	cin >> pKolLitUKom;
	cout << "\nUpisi sifru pica: ";
	cin >> pSifra;
	cout << "\nUpisi nabavnu cijenu po komadu: ";
	cin >> pNabCPoKom;
	cout << "\nUpisi broj komada u pakovanju: ";
	cin >> pBrKomUPak;
	cout << "\nUpisi broj nabavljenih pakovanja: ";
	cin >> pBrNabPak;
	cout << endl;
	delete pokPica;
}

void iKupljenaPica::fIspisivanje(kPica* pokPica,int n) {
	//for (int i = 0; i < n; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		kPica::fIspisivanje();
		cout << "\nRedni broj: " << pRedniBroj;
		cout << "\nSifra: " << pSifra;
		cout << "\nKolicina(l):" << pKolLitUKom;
		cout << "\nNabavna cijena/kom.: " << pNabCPoKom;
		cout << "\nBr.kom. u pakovanju: " << pBrKomUPak;
		cout << "\nBr.nabavljenih pakovanja: " << pBrNabPak;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << endl;
	//}
}

double iKupljenaPica::fUkupnaNabCijena() {
	pUkupnaNabCijena = pNabCPoKom * pBrKomUPak * pBrNabPak;
	return pUkupnaNabCijena;
}

class iZestokaPica : public iKupljenaPica {
private:
	double pDoziranje;
public:
	iZestokaPica();
	void fUpisivanje();
	void fIspisivanje() const;
	virtual double fIzracunavanjeC();
	~iZestokaPica() {};
};

iZestokaPica::iZestokaPica() {
	pDoziranje = 0.00;
}

void iZestokaPica::fUpisivanje() {
	iKupljenaPica *pokKupPica = new iKupljenaPica;
	pokKupPica->fUpisivanje();
	cout << "\nUpisi kolicinu doziranja zestokog pica: ";
	cin >> pDoziranje;
	delete pokKupPica;
}

void iZestokaPica::fIspisivanje() const {
	&kPica::fIspisivanje;
	&iKupljenaPica::fIspisivanje;
	cout << "\nDoziranje:";
	cout << pDoziranje;
}

//(cena = (nabavna cena / količina u pakovanju(u litrima) / doziranje) * 3.5)
double iZestokaPica::fIzracunavanjeC() {
	return (double)(fUkupnaNabCijena() / pDoziranje) * 3.5;
}

class kFlasice : public iKupljenaPica {
public:
	virtual double fIzracunavanjeC();
};

double kFlasice::fIzracunavanjeC() {
	return (double)(fUkupnaNabCijena() * 2.5);
}

int main()
{
	//int i;

	int izbor = -1;

	while (izbor != 0)
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n~ 1-Unos kupljenih pica        ~";
		cout << "\n~ 2-Ispis kupljenih pica       ~";
		cout << "\n~ 3-Ukupno stanje na skladistu ~";
		cout << "\n~ 4-Listanje                   ~";
		cout << "\n~ 5-Pronadji po nazivu         ~";
		cout << "\n~ 0-Izlaz                      ~";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n~ Unesite vas izbor            ~\n\n";
		cin >> izbor;
		system("cls");

		switch (izbor)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			//-	ukupno stanje na skladištu (plaćeno, neplaćeno, ukupno=plaćeno+neplaćeno)
			break;
		case 4:
			//-listanje(šifra, količina, cena)
			break;
		case 5:
			break;
			//-	pronađi po nazivu (naziv, šifra, cena)
		case 0:
			izbor = 0;
			break;
		default:
			cout << "\nUnesite pravilan izbor!!!";
		}
	}

	return 0;
}
