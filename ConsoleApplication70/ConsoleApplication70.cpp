#include <iostream>
#define MAX 50

using namespace std;

int fRazliciti(int niz[MAX], int duzina)
{
	int i, j, broj = 0;

	for (i = 0; i < duzina; i++) {
		j = 1;
		while ( niz[i] != niz[j]) j++;
		if (i == j) broj++;
	}
	return broj;
};

int fUmetanje(int na, int a[MAX], int nb, int b[MAX], int k) 
{
	int i, broj;
	for (i = 0; i < nb; i++) 
	{
		a[k + nb] = a[k];
		a[k] = b[i];
		k++;
	}

	cout << "\nNovi niz je : " << endl;
	for (i = 0; i < na + nb; i++)
		cout << a[i] << " ";

	cout << "\nBroj razlicitih elemenata novog niza je: ";
	broj = fRazliciti(a, na + nb);
	cout << broj;

	return 0;
};

int main()
{
	int i, na, nb, k, a[MAX], b[MAX], razliciti;

	cout << "Unesite duzinu prvog niza: ";
	cin >> na;

	cout << "\nUnesite elemente prvog niza: ";
	for (i = 0; i < na; i++)cin >> a[i];

	cout << "\nUnesite duzinu drugog niza: ";
	cin >> nb;

	cout << "\nUnesite elemente drugog niza: ";
	for (i = 0; i < nb; i++)cin >> b[i];

	cout << "\nBroj razlicitih elemenata prvog niza je: ";
	razliciti = fRazliciti(a, na);
	cout << razliciti;

	cout << "\nBroj razlicitih elemenata drugog niza je: ";
	razliciti = fRazliciti(b, nb);
	cout << razliciti << endl;

	cout << "\nUnesite poziciju od koje se drugi niz umece u prvi niz: ";
	cin >> k;
	fUmetanje(na, a, nb, b, k);
	cout << endl << endl;

	return 0;
}