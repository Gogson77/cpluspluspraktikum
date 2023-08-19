#include <iostream>
#include <string>

using namespace std;

class Pice 
{
protected:
	char naziv[15];
	char proizvodjac[20];
public:
	Pice();
	Pice(const char* naz, const char* proi);
	void upis();
	void testniUpis();
	void ispis() const;
	const char* dohvatiNaziv();
	~Pice() {};
};

Pice::Pice() 
{
	strcpy_s(naziv, "");
	strcpy_s(proizvodjac, "");
}

Pice::Pice(const char* naz, const char* proi) 
{
	strcpy_s(naziv, naz);
	strcpy_s(proizvodjac, proi);
};

void Pice::upis()
{
	cout << "\nUpisi naziv pica: "; cin >> naziv;
	cout << "Upisi proizvodjaca: "; cin >> proizvodjac;
}

void Pice::testniUpis() 
{
	strcpy_s(naziv, "pice");
	strcpy_s(proizvodjac, "proizvodjac");
}

void Pice::ispis() const
{
	cout << "\nNaziv pica: " << naziv << endl;
	cout << "Proizvodjac: " << proizvodjac << endl;
}

const char* Pice::dohvatiNaziv() 
{
	return (const char*)Pice::naziv;
};

class KupljenoPice : public Pice 
{
protected:
	int redniBroj;
	char sifra[15];
	double nabavnaCenaPoKomadu;
	int brojKomadaUPakovanju;
	int brojNabavljenihPakovanja;
	double kolicinaUAmbalazi;
	int status;
	int nacinPlacanja;
	bool placeno;
	char robuPrimio[35];

public:
	static double pUkupnaNabavnaCenaPica;
	KupljenoPice();
	KupljenoPice(
		const char* naz,
		const char* proi,
		int rbr,
		const char* sif,
		double nabc,
		int brkompak,
		int brnabpak,
		double kolamb,
		int stat,
		int nacpl,
		bool plac,
		const char* robprim
	);
	void upis();
	void testniUpis();
	void ispis() const;
	void ispis(KupljenoPice*, int) const;
	void ispisiVrstuPica() const;
	void ispisiZaglavlje() const;
	void petljaListPret() const;
	void listanje(KupljenoPice*, int) const;
	void pretraga(KupljenoPice*, const char*, int) const;
	int dohvatiStatus() { return status; }
	bool jePlaceno() { return placeno; }
	double nabavnaCenaPica();
	double ukupnaNabavnaCenaPica(KupljenoPice*, int);
	~KupljenoPice() {};
};

double KupljenoPice::pUkupnaNabavnaCenaPica(0.00);

KupljenoPice::KupljenoPice()
{
	redniBroj = 0;
	strcpy_s(sifra, "");
	nabavnaCenaPoKomadu = 0.00;
	brojKomadaUPakovanju = 0;
	brojNabavljenihPakovanja = 0;
	kolicinaUAmbalazi = 0.00;
	status = 0;
	nacinPlacanja = 1;
	placeno = false;
	strcpy_s(robuPrimio, "");
};

KupljenoPice::KupljenoPice(
	const char* naz,
	const char* proi,
	int rbr,
	const char* sif,
	double nabc,
	int brkompak,
	int brnabpak,
	double kolamb,
	int stat,
	int nacpl,
	bool plac,
	const char* robprim
) : Pice(naz, proi) {
	strcpy_s(naziv, naz);
	strcpy_s(proizvodjac, proi);
	redniBroj = rbr;
	strcpy_s(sifra, sif);
	nabavnaCenaPoKomadu = nabc;
	brojKomadaUPakovanju = brkompak;
	brojNabavljenihPakovanja = brnabpak;
	kolicinaUAmbalazi = kolamb;
	status = stat;
	nacinPlacanja = nacpl;
	placeno = plac;
	strcpy_s(robuPrimio, robprim);
};

void KupljenoPice::upis()
{
	Pice::upis();
	redniBroj++;
	cout << "Upisi sifru pica: ";
	cin >> sifra;
	cout << "Upisi nabavnu cenu po komadu: ";
	cin >> nabavnaCenaPoKomadu;
	cout << "Upisi broj komada u pakovanju: ";
	cin >> brojKomadaUPakovanju;
	cout << "Upisi broj nabavljenih pakovanja: ";
	cin >> brojNabavljenihPakovanja;
	cout << "Upisi kolicinu u ambalazi (u litrima): ";
	cin >> kolicinaUAmbalazi;
	cout << "Upisi status (0 - na skladistu, 1 - aktivan, 2 - potrosen): ";
	cin >> status;
	cout << "Upisi nacin placanja (1 - kes, 2 - racun, 3 - kredit): ";
	cin >> nacinPlacanja;
	cout << "Da li je placeno (1 - da, 0 - ne): ";
	cin >> placeno;
	placeno = (placeno == 1 ? true : false);
	cin.ignore();
	cout << "Upisi ime osobe koja je primila robu: ";
	cin.getline(robuPrimio, sizeof(robuPrimio));
}

void KupljenoPice::testniUpis() 
{
	Pice::testniUpis();
	redniBroj++;
	strcpy_s(sifra, "123");
	nabavnaCenaPoKomadu = 1.00;
	brojKomadaUPakovanju = 10;
	brojNabavljenihPakovanja = 1;
	kolicinaUAmbalazi = 1.00;
	status = 0;
	nacinPlacanja = 1;
	placeno = true;
	strcpy_s(robuPrimio, "gk");
};

void KupljenoPice::ispis() const
{
	Pice::ispis();
	cout << "Redni broj: " << redniBroj << endl;
	cout << "Sifra: " << sifra << endl;
	cout << "Nabavna cena po komadu: " << nabavnaCenaPoKomadu << endl;
	cout << "Broj komada u pakovanju: " << brojKomadaUPakovanju << endl;
	cout << "Broj nabavljenih pakovanja: " << brojNabavljenihPakovanja << endl;
	cout << "Kolicina u ambalazi (u litrima): " << kolicinaUAmbalazi << endl;
	cout << "Status (0-na skladistu, 1-aktivan, 2-potrosen): " << status << endl;
	cout << "Nacin placanja (1-kes, 2-racun, 3-kredit): " << nacinPlacanja << endl;
	cout << "Placeno (1-da, 0-ne): " << (placeno ? "Da" : "Ne") << endl;
	cout << "Osoba koja je primila robu: " << robuPrimio << endl;
};

void KupljenoPice::ispis(KupljenoPice* pok, int n) const
{
	for (int i = 0; i < n; i++)
	{
		pok[i].KupljenoPice::ispis();
	}
}

void KupljenoPice::ispisiVrstuPica() const
{
	cout << "\n~    Ispis kupljenih pica      ~\n";
}

void KupljenoPice::ispisiZaglavlje() const
{
	cout << "\nsifra:\tkol.:\tcena:\n";
}

void KupljenoPice::petljaListPret() const
{
	cout << sifra;
	cout << "\t" << brojKomadaUPakovanju * brojNabavljenihPakovanja;
	cout << "\t" << nabavnaCenaPoKomadu * brojKomadaUPakovanju * brojNabavljenihPakovanja;
	cout << endl;
}

void KupljenoPice::listanje(KupljenoPice* pok, int n) const
{
	KupljenoPice::ispisiZaglavlje();

	for (int i = 0; i < n; i++)
	{
		pok[i].KupljenoPice::petljaListPret();
	}
	cout << endl;
}

void KupljenoPice::pretraga(KupljenoPice* pok, const char* uzorak, int n) const
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(uzorak, pok[i].Pice::dohvatiNaziv()) == 0)
		{
			KupljenoPice::ispisiZaglavlje();
			KupljenoPice::petljaListPret();
		}
	}
}


double KupljenoPice::nabavnaCenaPica()
{
	double pNabavnaCenaPica = nabavnaCenaPoKomadu * brojKomadaUPakovanju * brojNabavljenihPakovanja;
	return pNabavnaCenaPica;
}

double KupljenoPice::ukupnaNabavnaCenaPica(KupljenoPice* pokKupljenoPice, int n)
{
	pUkupnaNabavnaCenaPica = 0.00;

	for (int i = 0; i < n; i++)
	{
		pUkupnaNabavnaCenaPica += pokKupljenoPice[i].nabavnaCenaPica();
	}
	return pUkupnaNabavnaCenaPica;
}

class ZestokoPice : public KupljenoPice 
{
protected:
	double doziranje;

public:
	ZestokoPice();
	ZestokoPice(
		const char* naz,
		const char* proi,
		int rbr,
		const char* sif,
		double nabc,
		int brkompak,
		int brnabpak,
		double kolamb,
		int stat,
		int nacpl,
		bool plac,
		const char* robprim,
		double doz
	);
	void upis();
	void testniUpis();
	void ispis() const;
	void ispis(ZestokoPice*, int) const;
	void ispisiVrstuPica() const;
	void listanje(ZestokoPice*, int) const;
	void pretraga(ZestokoPice*, const char*, int) const;
	virtual double izracunavanjeCene();
	virtual double ukupnoIzracunavanjeCene(ZestokoPice*, int) const;
	~ZestokoPice() {};
};

ZestokoPice::ZestokoPice() 
{ 
	doziranje = 0.00; 
}

ZestokoPice::ZestokoPice(
	const char* naz,
	const char* proi,
	int rbr,
	const char* sif,
	double nabc,
	int brkompak,
	int brnabpak,
	double kolamb,
	int stat,
	int nacpl,
	bool plac,
	const char* robprim,
	double doz
) : KupljenoPice(naz, proi, rbr, sif, nabc, brkompak, brnabpak, kolamb, stat, nacpl, plac, robprim) {
	strcpy_s(naziv, naz);
	strcpy_s(proizvodjac, proi);
	redniBroj = rbr;
	strcpy_s(sifra, sif);
	nabavnaCenaPoKomadu = nabc;
	brojKomadaUPakovanju = brkompak;
	brojNabavljenihPakovanja = brnabpak;
	kolicinaUAmbalazi = kolamb;
	status = stat;
	nacinPlacanja = nacpl;
	placeno = plac;
	strcpy_s(robuPrimio, robprim);
	doziranje = doz;
};

void ZestokoPice::upis()
{
	KupljenoPice::upis();
	cout << "Upisi doziranje (u litrima): ";
	cin >> doziranje;
}

void ZestokoPice::testniUpis()
{
	KupljenoPice::testniUpis();
	doziranje = 0.03;
}

void ZestokoPice::ispis(ZestokoPice* pok, int n) const
{
	for (int i = 0; i < n; i++)
	{
		pok[i].KupljenoPice::ispis();

		cout << "Doziranje (u litrima): " << pok[i].doziranje << endl;
		cout << "Pojedinacna cena pica: " << pok[i].izracunavanjeCene() << endl;
	}
}

void ZestokoPice::ispisiVrstuPica() const
{
	cout << "\n~    Ispis zestokih pica      ~\n";
}

void ZestokoPice::listanje(ZestokoPice* pok, int n) const 
{
	KupljenoPice::ispisiZaglavlje();

	for (int i = 0; i < n; i++)
	{
		pok[i].KupljenoPice::petljaListPret();
	}
	cout << endl;
}

void ZestokoPice::pretraga(ZestokoPice* pok, const char* uzorak, int n) const
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(uzorak, pok[i].Pice::dohvatiNaziv()) == 0)
		{
			KupljenoPice::ispisiZaglavlje();
			KupljenoPice::petljaListPret();
		}
	}
}

double ZestokoPice::izracunavanjeCene() 
{
	double pKolicinaUPakULitrima = kolicinaUAmbalazi * brojKomadaUPakovanju;
	double pPojedinacniIzracun = (nabavnaCenaPoKomadu / pKolicinaUPakULitrima / doziranje) * 3.5;
	return pPojedinacniIzracun;
};

double ZestokoPice::ukupnoIzracunavanjeCene(ZestokoPice* pokZestokoPice, int n) const 
{
	double pUkupnoIzracunavanjeCene = 0.00;

	for (int i = 0; i < n; i++) 
	{
		pUkupnoIzracunavanjeCene += pokZestokoPice[i].izracunavanjeCene();
	}
	return pUkupnoIzracunavanjeCene;
}

class Flasice : public KupljenoPice
{
public:
	Flasice();
	Flasice(
		const char* naz,
		const char* proi,
		int rbr,
		const char* sif,
		double nabc,
		int brkompak,
		int brnabpak,
		double kolamb,
		int stat,
		int nacpl,
		bool plac,
		const char* robprim
	);
	void upis();
	void testniUpis();
	void ispis() const;
	void ispis(Flasice*, int) const;
	void ispisiVrstuPica() const;
	void listanje(Flasice*, int) const;
	void pretraga(Flasice*, const char*, int) const;
	double izracunavanjeCene();
	double ukupnoIzracunavanjeCene(Flasice*, int) const;
	~Flasice() {};
};

Flasice::Flasice() {};

Flasice::Flasice(
	const char* naz,
	const char* proi,
	int rbr,
	const char* sif,
	double nabc,
	int brkompak,
	int brnabpak,
	double kolamb,
	int stat,
	int nacpl,
	bool plac,
	const char* robprim
) : KupljenoPice(naz, proi, rbr, sif, nabc, brkompak, brnabpak, kolamb, stat, nacpl, plac, robprim) {
	strcpy_s(naziv, naz);
	strcpy_s(proizvodjac, proi);
	redniBroj = rbr;
	strcpy_s(sifra, sif);
	nabavnaCenaPoKomadu = nabc;
	brojKomadaUPakovanju = brkompak;
	brojNabavljenihPakovanja = brnabpak;
	kolicinaUAmbalazi = kolamb;
	status = stat;
	nacinPlacanja = nacpl;
	placeno = plac;
	strcpy_s(robuPrimio, robprim);
};

void Flasice::upis()
{
	KupljenoPice::upis();
}

void Flasice::testniUpis()
{
	KupljenoPice::testniUpis();
}

void Flasice::ispis(Flasice* pok, int n) const 
{
	for (int i = 0; i < n; i++) 
	{
		pok[i].KupljenoPice::ispis();

		cout << "Poj5edinacna cena pica u flasicama: " << pok[i].izracunavanjeCene() << endl;
	}
}

void Flasice::ispisiVrstuPica() const
{
	cout << "\n~    Ispis flasica pica      ~\n";
}

void Flasice::listanje(Flasice* pok, int n) const
{
	KupljenoPice::ispisiZaglavlje();

	for (int i = 0; i < n; i++)
	{
		pok[i].KupljenoPice::petljaListPret();
	}
	cout << endl;
}

void Flasice::pretraga(Flasice* pok, const char* uzorak, int n) const
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(uzorak, pok[i].Pice::dohvatiNaziv()) == 0)
		{
			KupljenoPice::ispisiZaglavlje();
			KupljenoPice::petljaListPret();
		}
	}
}

double Flasice::izracunavanjeCene()
{
	return nabavnaCenaPoKomadu * 2.5;
}

double Flasice::ukupnoIzracunavanjeCene(Flasice* pokFlasice, int n) const
{
	double pUkupnoIzracunavanjeCene = 0.00;

	for (int i = 0; i < n; i++) {
		pUkupnoIzracunavanjeCene += pokFlasice[i].izracunavanjeCene();
	}
	return pUkupnoIzracunavanjeCene;
}

static int brojacA=0;
static int brojacB=0;
static int brojacC=0;

int main() {
	KupljenoPice* pokKupljenoPice = nullptr;
	ZestokoPice* pokZestokoPice = nullptr;
	Flasice* pokFlasice = nullptr;

	int izbor = -1;

	int a, b, c;

	int brojPlaceno1, brojNeplaceno1, brojUkupno1;
	int brojPlaceno2, brojNeplaceno2, brojUkupno2;
	int brojPlaceno3, brojNeplaceno3, brojUkupno3;
	int brojPlacenoSve, brojNeplacenoSve, brojUkupnoSve;

	char traziNaziv[15];

	while (izbor != 0) {
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n~ 1-Unos pica                  ~";
		cout << "\n~ 2-Ispis pica                 ~";
		cout << "\n~ 3-Ukupno stanje na skladistu ~";
		cout << "\n~ 4-Listanje                   ~";
		cout << "\n~ 5-Pronadji po nazivu         ~";
		cout << "\n~ 6-Unos istih test vrijednosti~";
		cout << "\n~ 7-Raznovrsne test vrijednosti~";
		cout << "\n~ 0-Izlaz                      ~";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n~ Unesite vas izbor            ~\n\n";
		cin >> izbor;
		system("cls");

		switch (izbor) {

		case 1:
			cout << "\n~     Unos kupljenih pica      ~";
			cout << "\nKoliko kupljenih pica unosite: ";
			cin >> a;
			if (a > 0) {
				brojacA = 0;
				if(pokKupljenoPice) 
					delete[] pokKupljenoPice;
				pokKupljenoPice = new KupljenoPice[a];
				if (pokKupljenoPice == 0) { 
					cout << "Nema dovoljno memorije!!!\n";
					exit(1); 
				}
				for (int i = 0; i < a; i++)
					pokKupljenoPice[i].upis();
				brojacA = a;
			}
			cout << "\n~      Unos zestokih pica      ~";
			cout << "\nKoliko zestokih pica unosite:  ";
			cin >> b;
			if (b > 0) {
				if(pokZestokoPice)
					delete[] pokZestokoPice;
				pokZestokoPice = new ZestokoPice[b];
				if (pokZestokoPice == 0) { 
					cout << "Nema dovoljno memorije!!!\n"; 
					exit(2); 
				}
				for (int i = 0; i < b; i++)
					pokZestokoPice[i].upis();
				brojacB = b;
			}
			cout << "\n~      Unos flasica pica       ~";
			cout << "\nKoliko pica u flasici unosite: ";
			cin >> c;
			if (c > 0) {
				if(pokFlasice)
					delete[] pokFlasice;
				pokFlasice = new Flasice[c];
				if (pokFlasice == 0) { 
					cout << "Nema dovoljno memorije!!!\n"; 
					exit(3); 
				}
				for (int i = 0; i < c; i++)
					pokFlasice[i].upis();
				brojacC = c;
			} 
			break;

		case 2:
			if (pokKupljenoPice == 0)
				cout << "\nNisi unio kupljena pica!\n";
			if (pokKupljenoPice != 0) {

				pokKupljenoPice->ispis(pokKupljenoPice, brojacA);
				cout << "\nUkupna nabavna cena pica: ";
				cout << pokKupljenoPice->ukupnaNabavnaCenaPica(pokKupljenoPice, brojacA) << endl;
			}
			if (pokZestokoPice == 0)
				cout << "\nNisi unio zestoka pica!\n";;
			if (pokZestokoPice != 0) {
				cout << "\n~     Ispis zestokih pica      ~" << endl;
				pokZestokoPice->ispis(pokZestokoPice, brojacB);
				cout << "\nUkupna cena zestokog pica: ";
				cout << pokZestokoPice->ukupnoIzracunavanjeCene(pokZestokoPice, brojacB) << endl;
			}
			if (pokFlasice == 0)
				cout << "\nNisi unio flasice pica!\n";
			if (pokFlasice != 0) {
				cout << "\n~     Ispis flasica pica       ~" << endl;
				pokFlasice->ispis(pokFlasice, brojacC);
				cout << "\nUkupna cena flasica pica: ";
				cout << pokFlasice->ukupnoIzracunavanjeCene(pokFlasice, brojacC) << endl;
			}
			break;

		case 3:
			brojPlaceno1 = 0; brojNeplaceno1 = 0; brojUkupno1 = 0;
			brojPlaceno2 = 0; brojNeplaceno2 = 0; brojUkupno2 = 0;
			brojPlaceno3 = 0, brojNeplaceno3 = 0; brojUkupno3 = 0;
			brojPlacenoSve = 0; brojNeplacenoSve = 0; brojUkupnoSve = 0;

			if (pokKupljenoPice == 0)
				cout << "\nNisi unio kupljena pica!\n";
			else if (pokKupljenoPice != 0) {
				pokKupljenoPice->ispisiVrstuPica();
				for (int i = 0; i < brojacA; i++) {
					if (pokKupljenoPice[i].dohvatiStatus() == 0) {
						if (pokKupljenoPice[i].jePlaceno()) {
							brojPlaceno1++;
						}
						else {
							brojNeplaceno1++;
						}
					}
				}
				brojUkupno1 = brojPlaceno1 + brojNeplaceno1;
				cout << "\nplaceno: " << brojPlaceno1;
				cout << ", neplaceno: " << brojNeplaceno1;
				cout << ", ukupno: " << brojUkupno1 << endl;
			}
			if (pokZestokoPice == 0)
				cout << "\nNisi unio zestoka pica!\n";
			else if (pokZestokoPice != 0) {
				pokZestokoPice->ispisiVrstuPica();
				for (int i = 0; i < brojacB; i++) {
					if (pokZestokoPice[i].dohvatiStatus() == 0) {
						if (pokZestokoPice[i].jePlaceno()) {
							brojPlaceno2++;
						}
						else {
							brojNeplaceno2++;
						}
					}
				}
				brojUkupno2 = brojPlaceno2 + brojNeplaceno2;
				cout << "\nplaceno: " << brojPlaceno2;
				cout << ", neplaceno: " << brojNeplaceno2;
				cout << ", ukupno: " << brojUkupno2 << endl;
			}
			if (pokFlasice == 0)
				cout << "\nNisi unio flasice pica!\n";
			else if (pokFlasice != 0) {
				pokFlasice->ispisiVrstuPica();
				for (int i = 0; i < brojacC; i++) {
					if (pokFlasice[i].dohvatiStatus() == 0) {
						if (pokFlasice[i].jePlaceno()) {
							brojPlaceno3++;
						}
						else {
							brojNeplaceno3++;
						}
					}
				}
				brojUkupno3 = brojPlaceno3 + brojNeplaceno3;
				cout << "\nplaceno: " << brojPlaceno3;
				cout << ", neplaceno: " << brojNeplaceno3;
				cout << ", ukupno: " << brojUkupno3 << endl;
			}
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout << "\n~  Ukupno stanje na skladistu  ~";
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			brojPlacenoSve = brojPlaceno1 + brojPlaceno2 + brojPlaceno3;
			brojNeplacenoSve = brojNeplaceno1 + brojNeplaceno2 + brojNeplaceno3;
			brojUkupnoSve = brojPlacenoSve + brojNeplacenoSve;
			cout << "\nBroj pica placeno: " << brojPlacenoSve;
			cout << "\nBroj pica neplaceno: " << brojNeplacenoSve;
			cout << "\nUkupno stanje na skladistu: " << brojUkupnoSve << endl;
			break;

		case 4:
			if (pokKupljenoPice == 0)
				cout << "\nNisi unio kupljena pica!\n";
			if (pokKupljenoPice != 0)
			{
				pokKupljenoPice->ispisiVrstuPica();
				pokKupljenoPice->listanje(pokKupljenoPice, brojacA);
			}
			if (pokZestokoPice == 0)
				cout << "\nNisi unio zestoka pica!\n";;
			if (pokZestokoPice != 0) 
			{
				pokZestokoPice->ispisiVrstuPica();
				pokZestokoPice->listanje(pokZestokoPice, brojacB);
			}
			if (pokFlasice == 0)
				cout << "\nNisi unio flasice pica!\n";
			if (pokFlasice != 0) 
			{
				pokFlasice->ispisiVrstuPica();
				pokFlasice->listanje(pokFlasice, brojacC);
			}
			break;

		case 5:
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout << "\n~    Pretraga po nazivu        ~";
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout << "\n~ Unesite naziv za pretragu    ~\n\n";
			cin >> traziNaziv;
			if (pokKupljenoPice == 0)
				cout << "\nNisi unio kupljena pica!\n";
			if (pokKupljenoPice != 0)
			{
				pokKupljenoPice->ispisiVrstuPica();
				pokKupljenoPice->pretraga(pokKupljenoPice, traziNaziv, brojacA);
			}
			if (pokZestokoPice == 0)
				cout << "\nNisi unio zestoka pica!\n";;
			if (pokZestokoPice != 0)
			{
				pokZestokoPice->ispisiVrstuPica();
				pokZestokoPice->pretraga(pokZestokoPice, traziNaziv, brojacB);
			}
			if (pokFlasice == 0)
				cout << "\nNisi unio flasice pica!\n";
			if (pokFlasice != 0)
			{
				pokFlasice->ispisiVrstuPica();
				pokFlasice->pretraga(pokFlasice, traziNaziv, brojacC);
			}
			break;

		case 6:
			cout << "\n~ 6-Unos testnih vrijednosti   ~";
			a = 2;
			if (a > 0) {
				brojacA = 0;
				if (pokKupljenoPice)
					delete[] pokKupljenoPice;
				pokKupljenoPice = new KupljenoPice[a];
				if (pokKupljenoPice == 0) {
					cout << "Nema dovoljno memorije!!!\n";
					exit(1);
				}
				for (int i = 0; i < a; i++)
					pokKupljenoPice[i].testniUpis();
				brojacA = a;
			}
			b = 2;
			if (b > 0) {
				if (pokZestokoPice)
					delete[] pokZestokoPice;
				pokZestokoPice = new ZestokoPice[b];
				if (pokZestokoPice == 0) {
					cout << "Nema dovoljno memorije!!!\n";
					exit(2);
				}
				for (int i = 0; i < b; i++)
					pokZestokoPice[i].testniUpis();
				brojacB = b;
			}
			c = 2;
			if (c > 0) {
				if (pokFlasice)
					delete[] pokFlasice;
				pokFlasice = new Flasice[c];
				if (pokFlasice == 0) {
					cout << "Nema dovoljno memorije!!!\n";
					exit(3);
				}
				for (int i = 0; i < c; i++)
					pokFlasice[i].testniUpis();
				brojacC = c;
			}
			break;

		case 7:
			cout << "\n~ 7-Raznovrsne test vrijednosti~";
			a = 2;
			if (a > 0) {
				brojacA = 0;
				if (pokKupljenoPice)
					delete[] pokKupljenoPice;

				pokKupljenoPice = new KupljenoPice[a]
				{
					KupljenoPice("kola", "sky", 1, "123", 1.00, 20, 1, 1.00, 0, 1, true, "gk"),
					KupljenoPice("sok", "orange", 2, "234", 1.50, 15, 2, 2.50, 0, 1, true, "gk")
				};

				if (pokKupljenoPice == 0) {
					cout << "Nema dovoljno memorije!!!\n";
					exit(1);
				}

				brojacA = a;
			}
			b = 2;
			if (b > 0) {
				if (pokZestokoPice)
					delete[] pokZestokoPice;

				pokZestokoPice = new ZestokoPice[b]
				{
					ZestokoPice("viski", "johnny", 2, "345", 1.50, 15, 2, 1, 0, 1, true, "gk", 0.03),
					ZestokoPice("votka", "vigor", 2, "456", 1.50, 15, 2, 0.7, 0, 1, true, "gk", 0.03)
				};

				if (pokZestokoPice == 0) {
					cout << "Nema dovoljno memorije!!!\n";
					exit(2);
				}

				brojacB = b;
			}
			c = 2;
			if (c > 0) {
				if (pokFlasice)
					delete[] pokFlasice;

				pokFlasice = new Flasice[c]
				{
					Flasice("jabuka", "fructal", 2, "567", 1.50, 15, 2, 0.2, 0, 1, true, "gf"),
					Flasice("kruska", "fructal", 2, "678", 1.50, 15, 2, 0.2, 0, 1, true, "gf")
				};

				if (pokFlasice == 0) {
					cout << "Nema dovoljno memorije!!!\n";
					exit(3);
				}

				brojacC = c;
			}
			break;
		case 0:

			izbor = 0;
			break;

		default:
			cout << "\nUnesite pravilan izbor!!!";
	}
}

delete[] pokKupljenoPice;
delete[] pokZestokoPice;
delete[] pokFlasice;

return 0;
}