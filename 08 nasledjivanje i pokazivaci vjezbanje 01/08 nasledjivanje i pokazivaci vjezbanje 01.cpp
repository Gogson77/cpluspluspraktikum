#include "klase.h"
#include <iostream>

using namespace std;

int main()
{
	int i;
	double pom;
	kCokolada* pCoko = 0;
	iTorta* pTor = 0;
	double (iTorta::*pokF)(kCokolada*,int);
	int n, izbor = 1;
	while (izbor != 0) {
		cout << "\n~~~~~~~~~~~~ MENI ~~~~~~~~~~~~";
		cout << "\n\n1 - Unos cokolade";
		cout << "\n2 - Prosecna cena cokolade";
		cout << "\n3 - Unos torte";
		cout << "\n4 - Preporuka za tortu";
		cout << "\n0 - Kraj\n\n";
		cout << "Unesi svoj izbor: ";
		cin >> izbor;

		switch (izbor)
		{
		case 1: cout << "Unesi broj cokolada: ";
			cin >> n;
			delete[] pCoko;
			delete pTor;
			if (n <= 0) {
				delete[] pCoko;
				cout << "Greska!!!" << endl;
				exit(1);
			}
			pCoko = new kCokolada[n];
			if (pCoko == 0) { cout << "\nNema dovoljno memorije!!!"; exit(2); }
			for (i = 0; i < n; i++)
				pCoko[i].fUpisCoko();
			break;

		case 2: if (pCoko == 0) { cout << "\nNisi uneo cokolade!!!"; break; }
			  pokF = &iTorta::fProsecnaCena;
			  pom = (pTor->*pokF)(pCoko,n);
			  cout << "Prosecna cena cokolade je " << pom << " dinara.\n";
			break;

		case 3: delete pTor;
			pTor = new iTorta;
			if (pTor == 0) { cout << "\nNema dovoljno memorije!!!"; break; }
			pTor->fUpis();
			break;

		case 4: if (pCoko == 0) { cout << "\nNisi uneo cokolade!!!"; break; }
			  if (pTor == 0) { cout << "\nNisi uneo torte!!!"; break; }
			  pokF = &iTorta::fMinCena;
			  pom = (pTor->*pokF)(pCoko, n);
			  cout << "Tortu je najpovoljije praviti sa cokoladom koja kosta " << pom << " dinara." << endl;
			break;

		case 0: delete pTor; delete[]pCoko; 
			break;

		default: cout << "\nPogresan izbor!!!" << endl;
		}
	}
	return 0;
}