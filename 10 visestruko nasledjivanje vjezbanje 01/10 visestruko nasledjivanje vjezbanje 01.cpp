#include <iostream>
#include <string>

using namespace std;

#include "izvedene.h"

void main()
{
	int tip, pDana, pPak;
	float pom, pFab, pProc, pRab;
	tip = 1;
	while (tip != 4)
	{
		kLekovi* pokL = new kLekovi;
		cout << "\nSta je doktor preporucio" << endl << endl;
		cout << "1-Tablete\n2-Sirup\n3-Injekcije\n4-Zdrav si\n\n";
		cin >> tip;
		switch (tip)
		{
		case 1: pokL = new iTableta; break;
		case 2: pokL = new iSirup; break;
		case 3: pokL = new iInjekcije; break;
		case 4:default: delete pokL; exit(1);
		}
		if (pokL == 0) { cout << "Nema mesta u memoriji!!!" << endl; exit(1); }

		// upisivanje podataka
		pokL->fUpisivanje();

		// izracunavanje koliko pakovanja kupiti
		cout << "\nKoliko dana traje terapija: ";
		cin >> pDana;
		pPak = pokL->fKupovina(pDana);
		cout << "\nTreba da kupis " << pPak << " pakovanja.";

		// izracunavanje koliko lek kosta
		cout << "\n\nUnesi fabricku cenu: ";
		cin >> pFab;
		cout << "\nUnesi procenat poreza: ";
		cin >> pProc;
		cout << "\nUnesi vrednost rabata: ";
		cin >> pRab;
		pom = pokL->fFormirajCenu(pFab, pProc, pRab);
		cout << "\nLek kosta " << pom << " dinara." << endl << endl;

		delete pokL;
	}
}
