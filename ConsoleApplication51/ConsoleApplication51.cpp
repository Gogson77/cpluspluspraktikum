#include <iostream>
using namespace std;

class kOtac {
private:
	int pKola;
	int fUzmiKola() { cout << "Kola" << endl; return 0; };
protected:
	int pNovac;
	int fUzmiNovac() { cout << "Novac" << endl; return 0;
	};
public:
	int pTv;
	int fGledajTv() { cout << "TV" << endl; return 0;
	};
	kOtac() { pKola = 0; pNovac = 0; pTv = 0; }
};

class iSin : public kOtac {
private:
	int pDjevojka;
	int fIzvestiDjevojku() { cout << "Djevojka" << endl; return 0; };
public:
	int fUcenje() { cout << "Ucim" << endl; return 0; };
	iSin() { pNovac = 1; pTv = 1; pDjevojka = 1; }
};

int main()
{	
	int pK, pN, pT, pD;

	kOtac oVeliki;
	iSin oMali;

	pT = oMali.pTv; cout << "oMali.pTv = " << pT << endl;
	pT = oVeliki.pTv; cout << "oVeliki.pTv = " << pT << endl;

	oVeliki.fGledajTv();
	oMali.fGledajTv();
	oMali.fUcenje();

	return 0;
}
