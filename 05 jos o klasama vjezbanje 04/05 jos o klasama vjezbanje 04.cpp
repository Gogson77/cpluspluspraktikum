#include "kTacka.h"
#include <iostream>

using namespace std;

void main()
{
	int n;
	cout << "\nBroj tacaka? ";
	cin >> n;
	kTacka* niz = new kTacka[n];
	cout << "Niz tacaka? ";
	for (int i = 0; i < n; i++)
		niz[i].fCitaj();
	double x, y;
	cout << "\nReferentna tacka? ";
	cin >> x >> y;
	kTacka t;
	t.fPravi(x, y);
	cout << "Koordinate: (" << t.fApcisa() << ", " << t.fOrdinata() << ")" << endl;
	kTacka w = t.fNajbliza(niz, n);
	cout << "\nNajbliza tacka: ";
	w.fPisi();
	cout << "\nUdaljenost od referentne tacke: " << t.fRastojanje(w) << endl << endl << endl;
	delete[] niz;

}