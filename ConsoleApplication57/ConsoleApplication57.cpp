#include <iostream>
using namespace std;

class kVozilo {
public:
	char pNaziv[15];
	int pMaxBrzina;
	char pBoja[15];

	kVozilo( const char* pN, int pMB, const char* pB
	) {
		strcpy_s(pNaziv, pN);
		pMaxBrzina = pMB;
		strcpy_s(pBoja, pB);
	};
	int fPisi() { 
		cout << "Ovo je " << pNaziv << ", maksimalna brzina mu je " << pMaxBrzina << ", boja " << pBoja << endl; return 0; 
	};
	~kVozilo() { cout << "Vozilo je unisteno." << endl; };
};

class iPutnicko : public kVozilo {
public:
	int pMaxOsoba;
	iPutnicko(const char* pN, int pMB, const char* pB, int pMO) : kVozilo(pN, pMB, pB) { 
		pMaxOsoba = pMO; 
	};
	int fPisi() {
		cout << "Ovo je " << pNaziv << ", maksimalna brzina mu je " << pMaxBrzina << ", boja " << pBoja << " i maksimalno moze da primi " << pMaxOsoba << endl;
		return 0;
	};
	~iPutnicko() { cout << "Putnicko vozilo je unisteno." << endl; };
};

int main()
{
	kVozilo oVozilo("Ford", 150, "plava");
	oVozilo.fPisi();

	iPutnicko oPutnicko("Peugeot", 168, "siva", 5);
	oPutnicko.fPisi();

	return 0;
}