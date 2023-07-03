#include <iostream>
#include <math.h>
using namespace std;

class kKupa {
public:
	float pPoluprecnik;
	float pIzvodnica;
	float pVisina;
	const double PI = 3.14;
	kKupa(float pP, float pI, float pV) {
		pPoluprecnik = pP;
		pIzvodnica = pI;
		pVisina = pV;
	};
	int fOmotac() {
		float M = pPoluprecnik * PI * pIzvodnica;
		cout << "Omotac je " << M << endl;
		return 0;
	};
	int fPovrsina() {
		float P = pPoluprecnik * PI * (pPoluprecnik + pIzvodnica);
		cout << "Povrsina je " << P << endl;
		return 0;
	};
	int fZapremina() {
		float V = (PI * pow(pPoluprecnik, 2) * pVisina) / 3;
		cout << "Zapremina je " << V << endl;
		return 0;
	};
	~kKupa() { cout << "Kupa je unistena." << endl; };
};

class kZarubljenaKupa : public kKupa{
public:
	float pGPoluprecnik;
	kZarubljenaKupa(float pP, float pI, float pV, float pGP) : kKupa(pP, pI, pV) { pGPoluprecnik = pGP; };
	int fOmotac() {
		float M = PI * pIzvodnica * (pPoluprecnik+ (2*pPoluprecnik));
		cout << "Omotac je " << M << endl;
		return 0;
	};
	int fPovrsina() {
		float P = PI * (pow(pPoluprecnik,2) + pow((2*pPoluprecnik),2) + pIzvodnica * (pPoluprecnik + (2 * pPoluprecnik)));
		cout << "Povrsina je " << P << endl;
		return 0;
	};
	int fZapremina() {
		float V = (PI * pVisina * (pow(pPoluprecnik,2) + pPoluprecnik * (2*pPoluprecnik) + pow((2*pPoluprecnik),2))) / 3;
		cout << "Zapremina je " << V << endl;
		return 0;
	};
	~kZarubljenaKupa() { cout << "Zarubljena kupa je unistena." << endl; };
};

int main()
{
	kKupa oKupa(1,2,3);
	kZarubljenaKupa oZarubljena(1,2,3,4);
	oKupa.fOmotac();
	oKupa.fPovrsina();
	oKupa.fZapremina();
	oZarubljena.fOmotac();
	oZarubljena.fPovrsina();
	oZarubljena.fZapremina();

	return 0;
}