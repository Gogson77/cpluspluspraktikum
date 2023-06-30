#include <iostream>
using namespace std;

class kOtac {
public:
	int pGod;
	char pIme[30];
	kOtac();
	kOtac(int pG, const char* pI);
	~kOtac();
};

kOtac::kOtac() { pGod = 50; strcpy_s(pIme, "Petar"); }
kOtac::kOtac(int pG, const char* pI) { pGod = pG; strcpy_s(pIme, pI); }
kOtac::~kOtac() { cout << "Destruktor Oca" << endl; }

class iDete : public kOtac
{
public:
	int pDzeparac;
	iDete();
	iDete(int pDzep);
	iDete(int pG, const char* pI, int pDzep);
	~iDete();
};

iDete::iDete() : kOtac() { pDzeparac = 100; }
iDete::iDete(int pDzep) : kOtac() { pDzeparac = pDzep; }
iDete::iDete(int pG, const char* pI, int pDzep) : kOtac(pG, pI) { pDzeparac = pDzep; }
iDete::~iDete() { cout << "Destruktor Dete" << endl; }

int main()
{
	kOtac oMoj;
	kOtac oTvoj(30, "Mika");
	iDete oPrviSin;
	iDete oDrugiSin(200);
	iDete oCerka(35, "Laza", 300);

	cout << oMoj.pIme << " " << oMoj.pGod << endl;
	cout << oTvoj.pIme << " " << oTvoj.pGod << endl;
	cout << oPrviSin.pIme << " " << oPrviSin.pGod << " " << oPrviSin.pDzeparac << endl;
	cout << oDrugiSin.pIme << " " << oDrugiSin.pGod << " " << oDrugiSin.pDzeparac << endl;
	cout << oCerka.pIme << " " << oCerka.pGod << " " << oCerka.pDzeparac << endl;
	return 0;
}
