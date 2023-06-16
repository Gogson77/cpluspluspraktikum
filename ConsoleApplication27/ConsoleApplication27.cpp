# include <iostream>
# include <string.h>
using namespace std;

struct sAdresa 
{
	char pUlica[15];
	int pBroj;
	char pMjesto[15];
};

union uMobilni 
{
	long int pM063;
	long int pM064;
};

struct sTelefon
{
	long int pFiksni;
	uMobilni pMob;
};

class kAdresar 
{
public:
	char pIme[15];
	sAdresa pAdr;
	sTelefon pTel;
};

int main()
{
	kAdresar oDrug;
	strcpy_s(oDrug.pIme,"Petar");
	strcpy_s(oDrug.pAdr.pUlica, "Nemanjina");
	oDrug.pAdr.pBroj = 15;
	strcpy_s(oDrug.pAdr.pMjesto, "Beograd");
	oDrug.pTel.pFiksni = 1567894;
	
	oDrug.pTel.pMob.pM063 = 2598647;
	cout << oDrug.pIme << " " << oDrug.pAdr.pUlica << " " << 
		oDrug.pAdr.pBroj << " " << oDrug.pAdr.pMjesto << " " <<
		oDrug.pTel.pFiksni << " 063" << oDrug.pTel.pMob.pM063 << endl;
	
	oDrug.pTel.pMob.pM064 = 2896877;
	cout << oDrug.pIme << " " << oDrug.pAdr.pUlica << " " <<
		oDrug.pAdr.pBroj << " " << oDrug.pAdr.pMjesto << " " <<
		oDrug.pTel.pFiksni << " 064" << oDrug.pTel.pMob.pM064 << endl;

	cout << oDrug.pIme << " " << oDrug.pAdr.pUlica << " " <<
		oDrug.pAdr.pBroj << " " << oDrug.pAdr.pMjesto << " " <<
		oDrug.pTel.pFiksni << " 063" << oDrug.pTel.pMob.pM063 << endl;

	return 0;
}