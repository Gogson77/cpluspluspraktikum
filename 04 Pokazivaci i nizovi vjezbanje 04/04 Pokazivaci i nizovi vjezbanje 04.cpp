#include <iostream>
#define MAX 10

using namespace std;

class kNiz {
public:
	int niz[MAX];
	int n, izbor;
	kNiz();
	void fCita(int niz[],int n);
	void fStampaNiz(kNiz& ob, int niz[], int n, int izbor);
	void fOriginalni(int niz[], int n);
	void fInverzni(int niz[], int n);
	~kNiz();
};

kNiz::kNiz() {
	n = 0; 
	izbor = 0;
	int i;
	for (i = 0; i < MAX; i++)
		niz[i] = 0;
}

void kNiz::fCita(int niz[], int n) {
	int i;
	cout << "\nUnesite elemente niza:";
	for (i = 0; i < n; i++)
		cin >> niz[i];
};

void kNiz::fOriginalni(int niz[], int n) {
	int i;
	cout << "\nZadati niz:" << endl;
	for (i = 0; i < n; i++)
		cout << niz[i] << endl;
};

void kNiz::fInverzni(int niz[], int n) {
	int i;
	cout << "\nInverzni niz:" << endl;
	for (i = n - 1; i >= 0; i--)
		cout << niz[i] << endl;
};

void kNiz::fStampaNiz(kNiz& ob, int x[], int n, int izbor) {
	void (kNiz::* ptr)(int niz[], int n);
	if (izbor == 1)
		ptr = &kNiz::fOriginalni;
	else
		ptr = &kNiz::fInverzni;
	(ob.*ptr)(x, n);
};


kNiz::~kNiz() {
	cout << "Kraj" << endl;
}

int main()
{
	kNiz oNiz;
	int n, opcija, x[MAX];
	cout << "Unesi duzinu niza:";
	cin >> n;
	oNiz.fCita(x,n);
	cout << "\n1. Originalni niz";
	cout << "\n2. Inverzni niz";
	cout << "\n\nIzbor:";
	do cin >> opcija;
	while (opcija < 1 || opcija>2);
	oNiz.fStampaNiz(oNiz, x, n, opcija);
	cout << endl;
}