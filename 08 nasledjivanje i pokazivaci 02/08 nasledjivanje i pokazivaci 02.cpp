#include <iostream>
#include <string.h>
using namespace std;

class kPice {
private:
	char pNaziv[25];
	double pCijena;
public:
	static double pUkupnaCijena;
	kPice();
	void fUpisPica();
	double fDohvatiCijenu();
	const char* fDohvatiNaziv();
	void fUkupnaCijena(kPice*, int);
	void fListaj(kPice*, int);
	~kPice();
};

double kPice::pUkupnaCijena(0.00);

kPice::kPice() { 
	strcpy_s(pNaziv, ""); 
	pCijena = 0.00; 
}

void kPice::fUpisPica() {
	cout << "Unesi naziv pica: "; cin >> pNaziv;
	cout << "Unesi cijenu pica: "; cin >> pCijena;
	cout << endl;
}

double kPice::fDohvatiCijenu() {
	return pCijena;
};

const char* kPice::fDohvatiNaziv() { 
	return pNaziv; 
};

void kPice::fUkupnaCijena(kPice* nizPica, int n) {
	pUkupnaCijena = 0.00;
	for (int i = 0; i < n; i++) {
		pUkupnaCijena += nizPica[i].fDohvatiCijenu();
	}
};

void kPice::fListaj(kPice* nizPica, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Pice:\t" << nizPica[i].pNaziv;
		cout << ",\t\tcijena: " << nizPica[i].pCijena;
		cout << endl;
	}
};

kPice::~kPice() {};

class iKoktel : public kPice {
private:
	char pIme[15];
public:
	double pCijenaPicaZaKoktel;
	static double pCijenaKoktela;
	iKoktel();
	void fUpisKoktela(kPice*, int);
	void fCijenaKoktela(iKoktel*);
	void fListaj(iKoktel*);
	~iKoktel();
};

double iKoktel::pCijenaKoktela(0.00);

iKoktel::iKoktel() { 
	strcpy_s(pIme, "");
	pCijenaPicaZaKoktel = 0.00;
}

void iKoktel::fUpisKoktela(kPice* nizPica, int n) { 
	cout << "Unesite ime koktela: "; 
	cin >> pIme; cout << endl;
	int izbor = -1;
	while (izbor != 0) {
		cout << "Od kojih pica se pravi " << pIme << " koktel?\n";
		for (int i = 0; i < n; i++) {
			cout << "\nKoristi li se " << nizPica[i].fDohvatiNaziv();
			cout << " za pravljenje koktela " << pIme << " (1)Da (2)Ne (0)Kraj? ";
			cin >> izbor;
			switch (izbor)
			{
			case 1:
				pCijenaPicaZaKoktel += nizPica[i].fDohvatiCijenu();
				break;
			case 2:
				break;
			case 0: 
				izbor = 0; 
				break;
			default:
				cout << "Unesite pravilan izbor!!!\n";
			}
			if (izbor == 0) break;
		}
		break;
	}
};

void  iKoktel::fCijenaKoktela(iKoktel* pKoktela) {
	pKoktela->pCijenaKoktela = pKoktela->pCijenaPicaZaKoktel * 0.50;
};

void iKoktel::fListaj(iKoktel* pKoktela) {
	cout << "Koktel:\t" << pKoktela->pIme;
	cout << ",\tcijena: " << pCijenaKoktela;
	cout << endl;
}

iKoktel::~iKoktel() {};

int main() {
	kPice* nizPica = 0;
	iKoktel* pKoktela = 0;

	void(kPice:: * pokFPic)(kPice*, int);
	void(iKoktel:: * pokFKok)(iKoktel*);

	int i;
	int n, izbor = 1;

	while (izbor != 0) {
		cout << "\n~~~~~~~~~~~~ MENI ~~~~~~~~~~~~";
		cout << "\n\n1 - Unos pica";
		cout << "\n2 - Ukupna cijena pica";
		cout << "\n3 - Unos koktela";
		cout << "\n4 - Cijena koktela";
		cout << "\n5 - Listaj pica";
		cout << "\n6 - Ocisti ekran - clear screen";
		cout << "\n0 - Kraj\n\n";
		cout << "Unesi svoj izbor: ";
		cin >> izbor;
		cout << endl;
		system("cls");
		switch (izbor)
		{
		case 1:
			cout << "Unesi broj pica: "; 
			cin >> n;
			cout << endl;
			delete[] nizPica;
			if (n <= 0) { cout << "Greska!!!" << endl; exit(1); }
			nizPica = new kPice[n];
			if (nizPica == 0) { cout << "Nema dovoljno memorije!!!\n"; exit(2); }
			for (i = 0; i < n; i++) { nizPica[i].fUpisPica(); }
			break;
		case 2:
			if (nizPica == 0) { cout << "Nisi unio pice!!!\n"; break; }
			pokFPic = &kPice::fUkupnaCijena;
			(nizPica->*pokFPic)(nizPica, n);
			cout << "Ukupna cijena pica je " << kPice::pUkupnaCijena << " dinara.\n";
			break;
		case 3:
			if (nizPica == 0) { cout << "Nisi unio pice!!!\n"; break; }
			delete pKoktela;
			if (n <= 0) { delete pKoktela; cout << "Greska!!!" << endl; exit(1); }
			pKoktela = new iKoktel;
			if (pKoktela == 0) { cout << "Nema dovoljno memorije!!!\n"; exit(2); }
			pKoktela->fUpisKoktela(nizPica, n);
			pokFKok = &iKoktel::fCijenaKoktela;
			(pKoktela->*pokFKok)(pKoktela);
			break;
		case 4:
			if (nizPica == 0) { cout << "Nisi unio pice!!!\n"; break; }
			else if (pKoktela == 0 || pKoktela->pCijenaPicaZaKoktel == 0) { cout << "Nisi unio pica za koktel!!!\n"; break; }
			else if (pKoktela->pCijenaPicaZaKoktel != 0) {
				pokFKok = &iKoktel::fCijenaKoktela;
				(pKoktela->*pokFKok)(pKoktela);
				cout << "Cijena koktela je " << pKoktela->pCijenaKoktela << " dinara.\n";
			} else { cout << "Greska!!!\n"; break; }
			break;
		case 5:
			if (nizPica == 0) { cout << "Nisi unio pice!!!\n"; break; } 
			nizPica->fListaj(nizPica, n);
			if (pKoktela != 0 && pKoktela->pCijenaKoktela != 0) pKoktela->fListaj(pKoktela);
			break;
		case 6:
			system("cls");
			break;
		case 0:
			izbor = 0;
			delete pKoktela; delete[] nizPica;
			break;
		default:
			cout << "Unesite pravilan izbor!!!\n";
		}
	}
	return 0;
};
