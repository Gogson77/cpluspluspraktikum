#include <iostream>
#define MAX 10

using namespace std;

void fCitaNiz(int x[],int n);
void fStampaNiz(int x[],int n,int broj);
void fOriginalni(int x[], int n);
void fInverzni(int x[], int n);

int main()
{
	int n, opcija, niz[MAX];

	cout << "Unesi duzinu niza:";
	cin >> n;
	fCitaNiz(niz, n);

	cout << "\n1.Originalni niz";
	cout << "\n2.Inverzni niz";
	cout << "\n\nIzbor:";

	do cin >> opcija; 
	while (opcija<1 || opcija>2);

	fStampaNiz(niz, n, opcija);
	cout << endl;
}

void fCitaNiz(int x[], int n) {
	int i;
	cout << "\nUnesite elemente niza:";
	for (i=0; i<n; i++) { cin >> x[i]; }
};

void fStampaNiz(int x[], int n, int broj) {
	void(*ptr)(int x[],int n);
	if (broj == 1)
		ptr = fOriginalni;
	else
		ptr = fInverzni;
	ptr(x, n);
};

void fOriginalni(int x[], int n) {
	int i;
	cout << "\nZadani niz: " << endl;
	for (i = 0; i < n; i++)
		cout << x[i] << endl;
};

void fInverzni(int x[], int n) {
	int i;
	cout << "\nInverzni niz: " << endl;
	for (i = n - 1; i >= 0; i--)
		cout << x[i] << endl;
};
