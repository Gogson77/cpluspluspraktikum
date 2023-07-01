#include <iostream>
#include <math.h>
using namespace std;

class kPiramida {
public:
	float pDonjaBaza;
	float pOmotac;
	float pVisina;
	kPiramida(float pD, float pO, float pV) {
		pDonjaBaza = pD;
		pOmotac = pO;
		pVisina = pV;
	};
	int fPovrsina() { 
		cout << "Povrsina piramide je " << pDonjaBaza + pOmotac << endl; return 0; 
	};
	int fZapremina() {
		cout << "Zapremina piramide je " << (pDonjaBaza * pVisina) / 3 << endl; return 0;
	};
	~kPiramida() { cout << "Piramida je unistena." << endl; };
};

class iZarubljenaPiramida : public kPiramida {
public:
	float pGornjaBaza;
	iZarubljenaPiramida(float pD, float pO, float pV, float pG) : kPiramida(pD, pO, pV) { pGornjaBaza = pD; };
	int fPovrsina() {
		cout << "Povrsina zarubljene piramide je " << pDonjaBaza + pOmotac + pOmotac << endl; return 0;
	};
	int fZapremina() {
		cout << "Zapremina zarubljene piramide je " << (pDonjaBaza + sqrt(pDonjaBaza * pGornjaBaza) + pGornjaBaza) << endl; return 0;
	};
	~iZarubljenaPiramida() { cout << "Zarubljena piramida je unistena." << endl; };
};

int main()
{
	kPiramida oPiramida(10.00, 20.55, 6.00);
	iZarubljenaPiramida oZarubljena(15.00, 32.50, 7.10, 13.40);
	oPiramida.fPovrsina();
	oPiramida.fZapremina();
	oZarubljena.fPovrsina();
	oZarubljena.fZapremina();
	return 0;
}