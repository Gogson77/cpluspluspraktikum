#include <iostream>
using namespace std;

int fibonaci(int poz) {
	int elem = 1;
	int n1 = 1, n2 = 1;

	for (int x = 3; x <= poz; ++x) {
		elem = n2 + n1;
		n2 = n1;
		n1 = elem;
	};

	return elem;
};

int stampa(int poz) {
	int pom;
	if (poz <= 0 || poz > 1024) {
		cout << "Neispravna pozicija: " << poz << " -- zahtjev se ne moze obraditi!\n"; return 1;
	}
	cout << "fibonacijev niz do " << poz << ". pozicije: \n";
	for (int x = 1; x <= poz; ++x) {
		pom = fibonaci(x);
		cout << "Element " << x << " je " << pom << endl;
	}
	cout << endl;

	return 0;
};


int main()
{
	int poz;
	cout << "Molim unesite poziciju: ";
	cin >> poz;
	stampa(poz);
	return 0;
}