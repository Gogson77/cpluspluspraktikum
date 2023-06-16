#include <iostream>
#include <string.h>
using namespace std;

struct sPolaznaTacka
{
	char pDatumPol[6];
	char pVrijemePol[5];
	char pMjestoPol[15];
};

union uBrojPrevoza
{
	int pBrojBusa;
	int pBrojLeta;
};

struct sKrajnjaTacka
{
	char pDatumDol[5];
	char pVrijemeDol[6];
	char pMjestoDol[15];
};

class kPutovanje
{
public:
	sPolaznaTacka pPolTac;
	uBrojPrevoza pBrojPrev;
	sKrajnjaTacka pKrajTac;
};

int main()
{
	kPutovanje mojePutovanje;
	strcpy_s(mojePutovanje.pPolTac.pDatumPol,"17.06.");
	strcpy_s(mojePutovanje.pPolTac.pVrijemePol, "05:00");
	strcpy_s(mojePutovanje.pPolTac.pMjestoPol, "Sarajevo");
	mojePutovanje.pBrojPrev.pBrojBusa = 15;
	strcpy_s(mojePutovanje.pKrajTac.pDatumDol, "18.06.");
	strcpy_s(mojePutovanje.pKrajTac.pVrijemeDol, "07:30");
	strcpy_s(mojePutovanje.pKrajTac.pMjestoDol, "Teslic");
	cout << mojePutovanje.pPolTac.pDatumPol << " "
		<< mojePutovanje.pPolTac.pVrijemePol << " "
		<< mojePutovanje.pPolTac.pMjestoPol << " "
		<< mojePutovanje.pBrojPrev.pBrojBusa << " "
		<< mojePutovanje.pKrajTac.pDatumDol << " "
		<< mojePutovanje.pKrajTac.pVrijemeDol << " "
		<< mojePutovanje.pKrajTac.pMjestoDol << endl;
	return 0;
}