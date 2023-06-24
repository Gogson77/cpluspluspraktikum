#include <iostream>
#include <string>
//#include <string.h>
using namespace std;

typedef enum eStimulans { Da, Ne };

class kTakmicenje
{
public:
	string pUcesnik;
	int pMjesto;
	int pOsnova;
	float pVrijednost;
	eStimulans pDoping;
	kTakmicenje(
		string pU,
		int pM,
		int pO,
		float pV,
		eStimulans pD
	);
	int fNagrada();
	~kTakmicenje();
};

kTakmicenje::kTakmicenje(
	string pU,
	int pM,
	int pO,
	float pV,
	eStimulans pD
) {
	pUcesnik = pU;
	pMjesto = pM;
	pOsnova = pO;
	pVrijednost = pV;
	pDoping = pD;
};

int kTakmicenje::fNagrada() {
	float pNagrada;
	cout << "UCESNIK: " << endl;
	cout << pUcesnik << endl;
	cout << "Doping kontrola je " << pDoping << endl;
	cout << "Osnova je " << pOsnova << endl;
	pNagrada = (pMjesto == 1 && pDoping != Da)
		? (++pOsnova) * pVrijednost
		: (pOsnova++) * pVrijednost;
	cout << "Nagrada je " << pNagrada << " dinara." << endl;
	cout << "Nova osnova je " << pOsnova << endl << endl;
	return 0;
};

kTakmicenje::~kTakmicenje() {
	cout << "Takmicenje je zavrseno!" << endl << endl;
};


int main()
{
	kTakmicenje oAtletika("Mika_Peric", 1, 45, 450.80, Ne);
	kTakmicenje oTenis("Vlada_Tadic", 3, 45, 450.80, Ne);
	oAtletika.fNagrada();
	cout << endl;
	oTenis.fNagrada();
 	return 0;
}