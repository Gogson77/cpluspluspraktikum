#include <iostream>
//#include <iomanip>
//#include <cstring>

using namespace std;

class kPlatno {
protected:
	char pVrsta[15];
	char pBoja[20];
	int pCijena;

public:
	kPlatno() {
		strcpy_s(pVrsta , "Nista");
		strcpy_s(pBoja, "Nema");
		pCijena = 0.00;
	};

	kPlatno(const char* pV, const char* pB, int pC) {
		strcpy_s(pVrsta, pV);
		strcpy_s(pBoja, pB);
		pCijena = pC;
	};

	void fStampa() {
		cout << "Vrsta " << pVrsta << ", boja " << pBoja << ", cijena " << pCijena << " KM" << endl;
		cout << "Vjezbanje naslijedjivanja." << endl << endl;
	}

	~kPlatno() { cout << "Gotovo platno." << endl; };
};

class iPantalone : public kPlatno {
private:
	int pVelicina;

public:
	iPantalone() : kPlatno() {
		pVelicina = 0;
	}

	iPantalone(	const char* pV, const char* pB, int pC, int pVel) : kPlatno(pV, pB, pC) {
		pVelicina = pVel;
	}

	~iPantalone() { cout << "Gotove pantalone." << endl; }
};


int main()
{
	kPlatno oNepoznato;
	oNepoznato.fStampa();

	kPlatno oPoznato( "Crni", "Somot", 500.0 );
	oPoznato.fStampa();

	iPantalone oNove;
	oNove.fStampa();

	iPantalone oStare("C", "D", 200, 42);
	oStare.fStampa();

	return 0;
}