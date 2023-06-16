#include <iostream>
#include <string.h>
using namespace std;

struct sAdresa
{
	char pUlica[15];
	int pBroj;
	char pMjesto[15];
};

union uDiploma
{
	char pFaks[20];
	char pSkola[25];
};

class kVizitKarta
{
public:
	char pIme[25];
	sAdresa pAdr;
	long int pTelefon;
	uDiploma pZvanje;
	kVizitKarta(char pI[25],char pU[15],int pB,char pM[15],long int pT,char pZ[25]);
	int fPisi();
	~kVizitKarta();
};

kVizitKarta::kVizitKarta(char pI[25],char pU[15],int pB,char pM[15],long int pT,char pZ[25]) {
	strcpy_s(pIme, pI);
	strcpy_s(pAdr.pUlica,pU);
	pAdr.pBroj = pB;
	strcpy_s(pAdr.pMjesto, pM);
	pTelefon = pT;
	strcpy_s(pZvanje.pSkola, pZ);
};
int kVizitKarta::fPisi() {
	cout << pIme << endl;
	cout << pAdr.pUlica << " " << pAdr.pBroj << " " << pAdr.pMjesto << endl;
	cout << pTelefon << endl;
	cout << pZvanje.pFaks << endl;
	return 0;
};
kVizitKarta::~kVizitKarta() {
	cout << "Kraj" << endl;
};

int main()
{
	kVizitKarta oMoja("Pera Peric", "Bulevar", 25, "Beograd", 13456789, "VZS");
	oMoja.fPisi();
	return 0;
}