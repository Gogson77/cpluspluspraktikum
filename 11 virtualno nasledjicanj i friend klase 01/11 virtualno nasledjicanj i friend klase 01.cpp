#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Proizvodjac {
private:
	string nazivProizvodjaca;
	string lokacija;

public:
	Proizvodjac(const string& nzvProiz, const string& lokacija) 
		: nazivProizvodjaca(nzvProiz), lokacija(lokacija) {}

	void upisivanje() {
		cout << "Upisi naziv proizvodjaca: "; cin >> nazivProizvodjaca;
		cout << "Upisi lokaciju proizvodjaca: "; cin >> lokacija;
	}
	void ispisivanje() const {
		cout << "naziv proizvodjaca: " << nazivProizvodjaca << endl;
		cout << "lokacija proizvodjaca: " << lokacija << endl;
	}
};

class Pica {
protected:
	string nazivPica;

public:
	Pica(const string& nzvPica) 
		: nazivPica(nzvPica) {}
	virtual void upisivanje() = 0;
	virtual void ispisivanje() const = 0;
    virtual double izracunavanjeCene() const = 0;
	virtual int getPlaceno() const = 0;
	virtual int getSifra() const = 0;
	virtual int getKolicina() const = 0;
	virtual string getNaziv() const { return nazivPica; };
};

class KupljenaPica : public Proizvodjac, public Pica {
protected:
	int sifra;
	int redniBroj;
	double nabavnaCenaPoKomadu;
	int brojKomadaUPakovanju;
	int brojNabavljenihPakovanja;
	double kolicinaUPakovanju;
	int status;
	int nacinPlacanja;
	string primioRobu;

public:
	int placeno;
	static int glavniRedniBroj;

	KupljenaPica(const string& nazivPica, const string& nazivProizvodjaca,const string& lokacija, int sifra, int redniBroj, double nabavnaCenaPoKomadu, int brojKomadaUPakovanju, int brojNabavljenihPakovanja, double kolicinaUPakovanju, int status, int nacinPlacanja, int placeno, const string& osoba) : Pica(nazivPica), Proizvodjac(nazivProizvodjaca, lokacija), sifra(sifra), redniBroj(redniBroj), nabavnaCenaPoKomadu(nabavnaCenaPoKomadu), brojKomadaUPakovanju(brojKomadaUPakovanju), brojNabavljenihPakovanja(brojNabavljenihPakovanja), kolicinaUPakovanju(kolicinaUPakovanju), status(status), nacinPlacanja(nacinPlacanja), placeno(placeno), primioRobu(osoba) {}

	void upisivanje() override {
		redniBroj = glavniRedniBroj++;
		cout << "Unesi naziv pica: "; cin >> nazivPica;
		Proizvodjac::upisivanje();
		cout << "Unesi sifru za pice: "; cin >> sifra;	
		cout << "Unesi nabavnu cenu po komadu pica: "; cin >> nabavnaCenaPoKomadu;
		cout << "Unesi broj komada u pakovanju pica: "; cin >> brojKomadaUPakovanju;
		cout << "Unesi broj nabavljenih pakovanja pica: "; cin >> brojNabavljenihPakovanja;
		cout << "Unesi kolicinu u pakovanju pica: "; cin >> kolicinaUPakovanju;
		cout << "Unesi status pica (1-na skladistu, 2-aktivno, 3-potroseno): "; cin >> status;
		cout << "Unesi nacin placanja pica (1-kes, 2-racun, 3-kredit): "; cin >> nacinPlacanja;
		cout << "Unesi placeno za pice (1-placeno, 0-neplaceno): "; cin >> placeno; placeno = (placeno == 1 ? 1 : 0);
		cout << "Unesi ime osobe koja je primila robu: "; cin >> primioRobu;
	}
	void ispisivanje() const override {
		cout << "redni broj: " << redniBroj << endl;
		cout << "naziv pica: " << nazivPica << endl;
		Proizvodjac::ispisivanje();
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
	}
	double izracunavanjeCene() const override {
		return ukupnaCena();
	}
	double ukupnaCena() const {
		return brojNabavljenihPakovanja * nabavnaCenaPoKomadu * brojKomadaUPakovanju;
	}
	int getPlaceno() const override {
		return placeno;
	};	
	int getSifra() const override {
		return sifra;
	};	
	int getKolicina() const override {
		return brojNabavljenihPakovanja * brojKomadaUPakovanju;
	};
};
int KupljenaPica::glavniRedniBroj(1);

class ZestokaPica : public KupljenaPica {
private:
	double doziranje;

public:
	ZestokaPica(const string& nazivPica, const string& nazivProizvodjaca, const string& lokacija, int sifra, int redniBroj, double nabavnaCenaPoKomadu, int brojKomadaUPakovanju, int brojNabavljenihPakovanja, double kolicinaUPakovanju, int status, int nacinPlacanja, int placeno, const string& osoba, double doziranje) : KupljenaPica(nazivPica, nazivProizvodjaca, lokacija, sifra, redniBroj, nabavnaCenaPoKomadu, brojKomadaUPakovanju, brojNabavljenihPakovanja, kolicinaUPakovanju, status, nacinPlacanja, placeno, osoba), doziranje(doziranje) {}

	void naslov() const { 
		cout << "\nZestoko pice\n";
	}
	void upisivanje() override {
		naslov();
		KupljenaPica::upisivanje();
		cout << "Unesi doziranje: "; cin >> doziranje;
	}
	void ispisivanje() const override {
		naslov();
		KupljenaPica::ispisivanje();
		cout << "doziranje: " << doziranje << endl;
		cout << "cena: " << izracunavanjeCene() << endl;
	}
	double izracunavanjeCene() const {
		return (nabavnaCenaPoKomadu / kolicinaUPakovanju / doziranje) * 3.5;
	}
};

class Flasice : public KupljenaPica {
public:
	Flasice(const string& nazivPica, const string& nazivProizvodjaca, const string& lokacija,int sifra, int redniBroj, double nabavnaCenaPoKomadu, int brojKomadaUPakovanju, int brojNabavljenihPakovanja, double kolicinaUPakovanju, int status, int nacinPlacanja, int placeno, const string& osoba) : KupljenaPica(nazivPica, nazivProizvodjaca, lokacija, sifra, redniBroj, nabavnaCenaPoKomadu, brojKomadaUPakovanju, brojNabavljenihPakovanja, kolicinaUPakovanju, status, nacinPlacanja, placeno, osoba) {}

	void naslov() const { 
		cout << "\nPice u flasici\n"; 
	};
	void upisivanje() override {
		naslov();
		KupljenaPica::upisivanje();
	}
	void ispisivanje() const override {
		naslov();
		KupljenaPica::ispisivanje();
		cout << "cena: " << izracunavanjeCene() << endl;
	}
	double izracunavanjeCene() const {
		return nabavnaCenaPoKomadu * 2.5;
	}
};

class Rinfuza : public KupljenaPica {
private:
	double doziranje;

public:
	Rinfuza(const string& nazivPica, const string& nazivProizvodjaca, const string& lokacija, int sifra, int redniBroj, double nabavnaCenaPoKomadu, int brojKomadaUPakovanju, int brojNabavljenihPakovanja, double kolicinaUPakovanju, int status, int nacinPlacanja, int placeno, const string& osoba, double doziranje) : KupljenaPica(nazivPica, nazivProizvodjaca, lokacija, sifra, redniBroj, nabavnaCenaPoKomadu, brojKomadaUPakovanju, brojNabavljenihPakovanja, kolicinaUPakovanju, status, nacinPlacanja, placeno, osoba), doziranje(doziranje) {}

	void naslov() const { 
		cout << "\nPice u rinfuzi\n"; 
	};
	void upisivanje() override {
		naslov();
		KupljenaPica::upisivanje();
		cout << "Unesi doziranje: "; cin >> doziranje;
	}
	void ispisivanje() const override {
		naslov();
		KupljenaPica::ispisivanje();
		cout << "doziranje: " << doziranje << endl;
		cout << "cena: " << izracunavanjeCene() << endl;
	}
	double izracunavanjeCene() const {
		return  (nabavnaCenaPoKomadu / kolicinaUPakovanju / doziranje) * 2.5;
	}
};

int main() {
	vector<Pica*> kupljenaPica;

	int izbor;

	do {
		cout << "\nIzaberite opciju:\n";
		cout << "1. Unos kupljenih pica\n";
		cout << "2. Ispis kupljenih pica\n";
		cout << "3. Ukupno stanje na skladistu\n";
		cout << "4. Listanje (sifra, kolicina, cena)\n";
		cout << "5. Pronadji po nazivu\n";
		cout << "0. Izlaz\n";
		cout << "Vas izbor: ";
		cin >> izbor;

		switch (izbor) {

		case 1: {
			int typeChoice;
			cout << "\nIzaberite vrstu pica:\n";
			cout << "1. Zestoko pice\n";
			cout << "2. Pice u flasici\n";
			cout << "3. Pice u rinfuzi\n";
			cout << "Vas izbor: ";
			cin >> typeChoice;

			Pica* novoPice = nullptr;

			switch (typeChoice) {
				case 1: {
					novoPice = new ZestokaPica("", "", "", 0, 0, 0.0, 0, 0, 0.0, 0, 0, 0, "", 0.0);
					break;
				}
				case 2: {
					novoPice = new Flasice("", "", "", 0, 0, 0.0, 0, 0, 0.0, 0, 0, 0, "");
					break;
				}
				case 3: {
					novoPice = new Rinfuza("", "", "", 0, 0, 0.0, 0, 0, 0.0, 0, 0, 0, "", 0.0);
					break;
				}
				default: {
					cout << "\nNevazeci unos. Pice nije uneseno.\n";
					break;
				}
			}

			if (novoPice) {
				novoPice->upisivanje();
				kupljenaPica.push_back(novoPice);
				cout << "\nPice je uspesno uneseno.\n";
			}

			break;
		}

		case 2: {
			if (kupljenaPica.empty()) {
				cout << "\nNema unetih kupljenih pica.\n";
			} else {
				cout << "\nLista kupljenih pica:\n";
				for (const Pica* pica : kupljenaPica) {
					pica->ispisivanje();
				}
			}
			break;
		}

		case 3: {
			double ukupnoPlaceno = 0.0;
			double ukupnoNeplaceno = 0.0;

			for (const Pica* pica : kupljenaPica) {
				if (pica->getPlaceno()==1) {
					ukupnoPlaceno += pica->izracunavanjeCene();
				} else {
					ukupnoNeplaceno += pica->izracunavanjeCene();
				}
			}

			double ukupnoStanje = ukupnoPlaceno + ukupnoNeplaceno;

			cout << "\nUkupno placeno: " << ukupnoPlaceno << " dinara\n";
			cout << "Ukupno neplaceno: " << ukupnoNeplaceno << " dinara\n";
			cout << "Ukupno stanje na skladistu: " << ukupnoStanje << " dinara\n";

			break;
		}

		case 4: {
			if (kupljenaPica.empty()) {
				cout << "\nNema unetih kupljenih pica.\n";
			}
			else {
				cout << "\nLista kupljenih pica:\n";
				cout << "Sifra\tKolicina\tCena\n";
				for (const Pica* pica : kupljenaPica) {
					double cena = pica->izracunavanjeCene();
					cout << pica->getSifra() << "\t" << pica->getKolicina() << "\t" << cena << endl;
				}
			}
			break;
		}

		case 5: {
			if (kupljenaPica.empty()) {
				cout << "\nNema unetih kupljenih pica.\n";
			}
			else {
				string trazeniNaziv;
				cout << "\nUnesite naziv pica za pretragu: ";
				cin.ignore();
				getline(cin, trazeniNaziv);

				cout << "\nRezultati pretrage za naziv '" << trazeniNaziv << "':\n";
				for (const Pica* pica : kupljenaPica) {
					if (pica->getNaziv() == trazeniNaziv) {
						pica->ispisivanje();
						cout << endl;
					}
				}
			}
			break;
		}

		case 0: {
			cout << "\nHvala na koriscenju programa!\n";
			break;
		}

		default: {
			cout << "\nNevazeci unos. Molimo izaberite ponovo.\n";
			break;
		}

		}
	} while (izbor != 0);

	for (Pica* pica : kupljenaPica) {
		delete pica;
	}

	return 0;
}
