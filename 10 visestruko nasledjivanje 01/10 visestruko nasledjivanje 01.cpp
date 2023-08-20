#include <iostream>
#include <string>
using namespace std;

class Proizvodjac {
private:
	string nazivProizvodjaca;
	string lokacija;
public:
	Proizvodjac() : nazivProizvodjaca(""), lokacija("") {};
	void upis();
	void ispis();
	~Proizvodjac() {}
};
void Proizvodjac::upis(){
	cout << "Upisi naziv proizvodjaca: "; cin >> nazivProizvodjaca;
	cout << "Upisi lokaciju proizvodjaca: "; cin >> lokacija;
};
void Proizvodjac::ispis(){ 
	cout << "naziv proizvodjaca: " << nazivProizvodjaca << endl;
	cout << "lokacija proizvodjaca: " << lokacija << endl;
}

class Pica {
protected:
	string nazivPica;
public:
	Pica() : nazivPica("") {}
	void upis();
	void ispis();
	~Pica() {}
};
void Pica::upis() { cout << "Upisi naziv pica: "; cin >> nazivPica; };
void Pica::ispis() { cout << "naziv pica: " << nazivPica << endl; };

class KupljenaPica : public Pica, public Proizvodjac {
protected:
	int rbr;
	string sifra;
	double nabavnaCenaPoKomadu;
	int brojKomadaUPakovanju;
	int brojNabavljenihPakovanja;
	double kolicinaUPakovanju;
	int status; 
	int nacinPlacanja; 
	string primioRobu;
public:
	int placeno;
	static int redniBroj;
	KupljenaPica() : 
		sifra(""), 
		rbr(0),
		nabavnaCenaPoKomadu(0.00), 
		brojKomadaUPakovanju(0),
		brojNabavljenihPakovanja(0), 
		kolicinaUPakovanju(0.00), 
		status(0), 
		nacinPlacanja(0),
		placeno(0), 
		primioRobu("") {}
	void upisivanje() { 
		Proizvodjac::upis(); 
		Pica::upis(); 
		cout << "Unesi sifru za pice: "; cin >> sifra;
		rbr = redniBroj++;
		cout << "Unesi nabavnu cenu po komadu pica: "; cin >> nabavnaCenaPoKomadu;
		cout << "Unesi broj komada u pakovanju pica: "; cin >> brojKomadaUPakovanju;
		cout << "Unesi broj nabavljenih pakovanja pica: "; cin >> brojNabavljenihPakovanja;
		cout << "Unesi kolicinu u pakovanju pica: "; cin >> kolicinaUPakovanju;
		cout << "Unesi status pica (1-na skladistu, 2-aktivno, 3-potroseno): "; cin >> status;
		cout << "Unesi nacin placanja pica (1-kes, 2-racun, 3-kredit): "; cin >> nacinPlacanja;
		cout << "Unesi placeno za pice (1-placeno, 0-neplaceno): ";
		cin >> placeno; 
		placeno = (placeno == 1 ? 1 : 0);
		cout << "Unesi ime osobe koja je primila robu: "; cin >> primioRobu;
	};
	void ispisivanje() { 
		cout << "redni broj: " << rbr << endl;
		Proizvodjac::ispis(); 
		Pica::ispis(); 
		cout << "sifra: " << sifra << endl;
		cout << "nabavna cena po komadu: " << nabavnaCenaPoKomadu << endl;
		cout << "broj komada u pakovanju: " << brojKomadaUPakovanju << endl;
		cout << "broj nabavljenih pakovanja: " << brojNabavljenihPakovanja << endl;
		cout << "kolicina u pakovanju: " << kolicinaUPakovanju << endl;
		cout << "status (1-na skladistu, 2-aktivno, 3-potroseno): " << status << endl;
		cout << "nacin placanja (1-kes, 2-racun, 3-kredit): " << nacinPlacanja << endl;
		cout << "placeno (1-da, 0-ne): " << (placeno ? "da" : "ne") << endl;
		cout << "ime osobe koja je primila robu: " << primioRobu << endl;
		cout << "ukupna cena: " << ukupnaCena() << endl;
	};
	void listanje() {
		cout << "naziv pica: " << nazivPica << endl;
		cout << "sifra: " << sifra << endl;
		cout << "kolicina: " << (brojKomadaUPakovanju * brojNabavljenihPakovanja) << endl;
	}
	int pretraga(string uzorak) {
		int rez = uzorak.compare(Pica::nazivPica);
		if (rez == 0) { listanjePretrage(); }
		else { cout << "pretraga bez rezultata." << endl; }
		return rez;
	}
	void listanjePretrage() {
		cout << "naziv pica: " << nazivPica << endl;
		cout << "sifra: " << sifra << endl;
	}
	double ukupnaCena() { 
		double ukupnaCena = brojNabavljenihPakovanja * nabavnaCenaPoKomadu * brojKomadaUPakovanju;
		return ukupnaCena; 
	};
	~KupljenaPica() {}
};

int KupljenaPica::redniBroj(1);

class ZestokaPica : public KupljenaPica{
private:
	double doziranje;
public:
	ZestokaPica() : doziranje(0.00) {};
	void naslov() { cout << endl << "Zestoko pice" << endl; }
	void upisivanje() { 
		naslov();
		KupljenaPica::upisivanje(); 
		cout << "Unesi doziranje: "; cin >> doziranje;
	};
	void ispisivanje() { 
		naslov();
		KupljenaPica::ispisivanje(); 
		cout << "doziranje: " << doziranje << endl;
		cout << "cena: " << izracunavanjeCene() << endl;
	};
	void listanje() { 
		naslov();
		KupljenaPica::listanje(); 
		cout << "cena: " << izracunavanjeCene() << endl;
	}
	void pretraga(string uzorak) {
		naslov();
		int rez = KupljenaPica::pretraga(uzorak);
		if (rez == 0) { cout << "cena: " << izracunavanjeCene() << endl; }
	}
	double virtual izracunavanjeCene() { 
		double izracunavanjeCene = (nabavnaCenaPoKomadu / kolicinaUPakovanju / doziranje) * 3.5;
		return izracunavanjeCene; 
	};
	~ZestokaPica() {}
};

class Flasice : public KupljenaPica {
public:
	Flasice() {}
	void naslov() { cout << endl << "Pice u flasici" << endl; };
	void upisivanje() {
		naslov();
		KupljenaPica::upisivanje();
	};
	void ispisivanje() {
		naslov();
		KupljenaPica::ispisivanje();
		cout << "cena: " << izracunavanjeCene() << endl;
	};
	void listanje() {
		naslov();
		KupljenaPica::listanje();
		cout << "cena: " << izracunavanjeCene() << endl;
	}
	void pretraga(string uzorak) {
		naslov();
		int rez = KupljenaPica::pretraga(uzorak);
		if (rez == 0) { cout << "cena: " << izracunavanjeCene() << endl; }
	}
	double virtual izracunavanjeCene(){ 
		double izracunavanjeCene = nabavnaCenaPoKomadu * 2.5;
		return izracunavanjeCene; 
	};
	~Flasice() {}
};

class Rinfuza : public KupljenaPica {
private:
	double doziranje;
public:
	Rinfuza() : doziranje(0.00) {};
	void naslov() { cout << endl << "Pice u rinfuzi" << endl; };
	void upisivanje() {
		naslov();
		KupljenaPica::upisivanje();
		cout << "Unesi doziranje: "; cin >> doziranje;
	};
	void ispisivanje() {
		naslov();
		KupljenaPica::ispisivanje();
		cout << "doziranje: " << doziranje << endl;
		cout << "cena: " << izracunavanjeCene() << endl;
	};
	void listanje() {
		naslov();
		KupljenaPica::listanje();
		cout << "cena: " << izracunavanjeCene() << endl;
	}
	void pretraga(string uzorak) {
		naslov();
		int rez = KupljenaPica::pretraga(uzorak);
		if (rez == 0) { cout << "cena: " << izracunavanjeCene() << endl; }
	}
	double virtual izracunavanjeCene() { double izracunavanjeCene = (nabavnaCenaPoKomadu / kolicinaUPakovanju / doziranje) * 2.5;
		return izracunavanjeCene; };
	~Rinfuza() {}
};

int main()
{
	ZestokaPica* pokZestokaPica = new ZestokaPica;
	Flasice* pokFlasice = new Flasice;
	Rinfuza* pokRinfuza = new Rinfuza;

	int izbor = -1;

	static string uzorak;

	while (izbor != 0)
	{
		cout << "\n0-Izlaz";
		cout << "\n1-Unos kupljenih pica";
		cout << "\n2-Ispis kupljenih pica";
		cout << "\n3-Ukupno stanje na skladistu";
		cout << "\n4-Listanje"; 
		cout << "\n5-Pronadji po nazivu"; 
		cout << "\nUnesite vas izbor: ";
		cin >> izbor;

		switch (izbor)
		{
		case 0:
			izbor = 0;
			break;
		case 1:
			pokZestokaPica->upisivanje();
			pokFlasice->upisivanje();
			pokRinfuza->upisivanje();
			break;
		case 2:
			pokZestokaPica->ispisivanje();
			pokFlasice->ispisivanje();
			pokRinfuza->ispisivanje();
			break;
		case 3:
			cout << endl;
			cout << "Zestoko pice " << (pokZestokaPica->placeno ? "je" : "nije") << " placeno" << endl;
			cout << "Pice u flasici " << (pokFlasice->placeno ? "je" : "nije") << " placeno" << endl;
			cout << "Pice u rinfuzi " << (pokRinfuza->placeno ? "je" : "nije") << " placeno" << endl;

			int x, y, z;
			x = (int)(pokZestokaPica->placeno);
			y = (int)(pokFlasice->placeno);
			z = (int)(pokRinfuza->placeno);
			cout << "placeno pice: " << (x + y + z) << endl;

			int a; a = 0; if (pokZestokaPica->placeno == 0) { ++a; };
			int b; b = 0; if (pokFlasice->placeno == 0) { ++b; };
			int c; c = 0; if (pokRinfuza->placeno == 0) { ++c; };
			cout << "neplaceno pice: " << (a + b + c) << endl;

			cout << "ukupno placeno i neplaceno pice: " << (x + y + z) + (a + b + c) << endl;
			break;
		case 4: 
			pokZestokaPica->listanje();
			pokFlasice->listanje();
			pokRinfuza->listanje();
			break;
		case 5:
			cout << endl << "Unesi naziv pica: ";
			cin >> uzorak;
			pokZestokaPica->pretraga(uzorak);
			pokFlasice->pretraga(uzorak);
			pokRinfuza->pretraga(uzorak);
			break;
		default:
			cout << endl << "Unesite pravilan izbor!" << endl;
		}
	}
	delete pokZestokaPica;
	delete pokFlasice;
	delete pokRinfuza;
}
