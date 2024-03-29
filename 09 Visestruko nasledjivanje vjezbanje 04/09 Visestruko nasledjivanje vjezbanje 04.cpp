#include "izvedene.h"
#include <iostream>

using namespace std;

void main()
{
	int tip, pDana, pPak;
	float pom, pFab, pProc, pRab;

	tip = 1;
	while (tip != 4) 
	{
		iLekovi* pokL = new iLekovi;

		cout << "\nSta je doktor preporucio" << endl << endl;
		cout << "1-Tablete\n2-Sirup\n3-Injekcije\n4-Zdrav si\n\n";
		cin >> tip;

		switch (tip)
		{
		case 1: pokL = new iTableta; break;
		case 2: pokL = new iSirup; break;
		case 3: pokL = new iInjekcije; break;
		case 4: 
		default:
			delete pokL; exit(1);
			break;
		}

		if (pokL == 0) { cout << "Nema mjesta u memoriji!!!" << endl; exit(1); }

		//upisivanje podataka
		pokL->fUpisivanje();

		//izracunavanje koliko pakovanja kupiti
		cout << "\nKoliko dana traje terapija: ";
		cin >> pDana;
		pPak = pokL->fKupovina(pDana);
		cout << "\nTreba da kupis " << pPak << " pakovanja.";

		//izracunavanje koliko lijek kosta
		cout << "\n\nUnesi fabricku cijenu: ";
		cin >> pFab;
		cout << "\nUnesi procenat poreza: ";
		cin >> pProc;
		cout << "\nUnesi vrijednost rabata: ";
		cin >> pRab;
		pom = pokL->fFormirajCenu(pFab, pProc, pRab);
		cout << "\nLijek kosta " << pom << " dinara." << endl << endl;

		delete pokL;
	}
}