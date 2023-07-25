#include "Sfera.h"
#include <iostream>

using namespace std;

int main()
{
	int i, j;
	for (;;)
	{
		Sfera* niz;
		int n;

		cout << "n? ";
		cin >> n;
		if (n <= 0) break;

		// učitavanje niza sfera
		niz = new Sfera[n];
		int pravi_n = 0;
		cout << "Unesi x, y, z koordinate centra i poluprecnik: ";
		for (i = 0; i < n; i++)
			niz[i].citaj();

		// uređivanje niza prema zapreminama u neopadajućem redosledu
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (niz[i].zapremina() > niz[j].zapremina())
				{
					Sfera pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}

		// ispisivanje niza uređenih sfera
		cout << "Niz uredjenih sfera prema zapreminama: " << endl;
		for (i = 0; i < n; i++)
		{
			niz[i].pisi(); cout << endl;
		}

		// pomeranje sfera za isti pomak
		double xx, yy, zz;
		cout << "Unesi pomake za x, y, z koordinate centra: ";
		cin >> xx >> yy >> zz;
		for (i = 0; i < n; i++)
		{
			niz[i].c_pomak(xx, yy, zz);
			niz[i].pisi();
			cout << endl;
		}

		// pronalaženje najbliže i najudaljenije sfere od koordinatnog početka
		double min = niz[0].udaljenost(); int imin = 0;
		double max = niz[0].udaljenost(); int imax = 0;
		for (int i = 1; i < n; i++) {
			if (niz[i].udaljenost() > max)
			{
				max = niz[i].udaljenost(); imax = i;
			}
			if (niz[i].udaljenost() < min)
			{
				min = niz[i].udaljenost(); imin = i;
			}
		}
		cout << "\nNajbliza sfera koordinatnom pocetku" << endl;
		niz[imin].pisi();
		cout << "\nNajudaljenija sfera od koordinatnom pocetka" << endl;
		niz[imax].pisi();

		// pronalaženje najbližeg para sfera
		double dmin = niz[0].rastojanje(niz[1]);
		int prva = 0; int druga = 1;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (dmin > niz[i].rastojanje(niz[j]))
				{
					dmin = niz[0].rastojanje(niz[1]);
					prva = i; druga = j;
				}
		cout << "\nNajblizi par sfera je: " << endl;
		niz[prva].pisi();
		niz[druga].pisi();
		cout << "Rastojanje izmedju njih je " << dmin;
		cout << endl << endl;

		delete[] niz; 	// oslobađanje memorije
	}
	return 0;
}