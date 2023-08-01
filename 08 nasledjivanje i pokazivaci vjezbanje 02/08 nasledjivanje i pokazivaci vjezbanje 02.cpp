#include <iostream>
#include "trougao.h"

using namespace std;

void main()
{
	Trougao* niz, pom;
	int i, j, n;

	cout << "Unesi duzinu niza: ";
	cin >> n;

	while (n > 0)
	{
		// ucitavanje niza trouglova
		niz = new Trougao[n];
		if (niz == 0) { cout << "Nema dovoljno memorije" << endl; exit(1); }
		for (i = 0; i < n; i++)
			niz[i].citaj();

		// uredivanje niza prema površinama u neopadajucem redosledu
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (niz[i].P() > niz[j].P())
				{
					Trougao pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}

		// ispisivanje uredenog niza
		cout << "Niz uredjenih trouglova: " << endl;
		for (i = 0; i < n; i++)
		{
			niz[i].pisi(); cout << endl;
		}

		delete[] niz;

		cout << "Unesi duzinu niza: ";
		cin >> n;
	}

}