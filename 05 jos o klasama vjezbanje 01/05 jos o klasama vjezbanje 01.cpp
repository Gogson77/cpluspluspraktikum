#include <iostream>
#include <string.h>
using namespace std;

// definicije prototipovi funkcija

void fKvadrat(int&, int&);
void fKub(int&, int&);
void fZamena(int&, int&);
void fUzmi(int&, int&);
void fPisi(int, int);

int main()
{
	void (*pokF)(int&, int&);
	bool fKraj = false;
	int prva = 1, druga = 2;
	int izbor;
	while (fKraj == false) {
		cout << "(0)Kraj (1)Promeni vrednosti (2)Kvadrat (3)Kub (4)Zamena: ";
		cout << endl;
		cin >> izbor;
		switch (izbor) {
		case 1: pokF = fUzmi; pokF(prva, druga); break;
		case 2: pokF = fKvadrat; pokF(prva, druga); break;
		case 3: pokF = fKub; pokF(prva, druga); break;
		case 4: pokF = fZamena; pokF(prva, druga); break;
		default: fKraj = true;  break;
		}
		if (fKraj) break;
	//	fPisi(prva, druga);
	//	pokF(prva, druga);
		fPisi(prva, druga);
	}
	return 0;
}

void fPisi(int x, int y) {
	cout << "x: " << x << " y: " << y << endl;
}

void fKvadrat(int& refX, int& refY) {
	refX *= refX;
	refY *= refY;
}

void fKub(int& refX, int& refY) {
	int tmp;

	tmp = refX;
	refX *= refX;
	refX = refX * tmp;

	tmp = refY;
	refY *= refY;
	refY = refY * tmp;
}

void fZamena(int& refX, int& refY) {
	int temp;
	temp = refX;
	refX = refY;
	refY = temp;
}

void fUzmi(int& refPrva, int& refDruga) {
	cout << "Nova vrednost za prvu promenljivu: ";
	cin >> refPrva;
	cout << "Nova vrednost za drugu promenljivu: ";
	cin >> refDruga;
}