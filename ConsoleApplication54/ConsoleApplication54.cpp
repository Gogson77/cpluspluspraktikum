#include <iostream>
using namespace std;

class kPice {
public:
	char pMarka[20];
	float pCijena0330;
	float pCijena1000;
	float pCijena2000;
	kPice() {
		strcpy_s(pMarka, "Nema");
		pCijena0330 = 0;
		pCijena1000 = 0;
		pCijena2000 = 0;
	};
	int fUpisCijena() {
		cout << "Unesi marku pica: "; 
		cin >> pMarka;
		cout << "Unesi cijenu pica za 0.33 litra: "; 
		cin >> pCijena0330; 
		cout << "Unesi cijenu pica za 1 litar: "; 
		cin >> pCijena1000; 
		cout << "Unesi cijenu pica za 2 litra: "; 
		cin >> pCijena2000; 
		return 0;
	};
	int fProsjecnaCijena() {
		float pProsjekPoLitru;
		pProsjekPoLitru = ((pCijena0330 + pCijena1000 + pCijena2000) / (330+1000+2000)) * 1000;
		cout << "Prosjecna cijena po litru: " << pProsjekPoLitru << endl << endl;
		return 0;
	};
	int fPopijenaKolicina() {
		int i,x,r;
		r = 0;
		cout << "Unesi broj popijenih pica od 0.33 l, 1 litar i 2 litra: " << endl;
		for (i = 0; i < 3; i++) { 
			cin >> x; 
			r += x;
		};
		cout << "Popijena kolicina je: " << r << endl << endl;
		return 0;
	};
	~kPice() { 
		cout << "Pice " << pMarka << " je popijeno." << endl; 
	};
};

class iKoktel : public kPice {
private:
	char pIme[15];
public:
	iKoktel() { 
		strcpy_s(pIme, "Nema");
	};
	int fUpisCijena() {
		cout << "Unesi naziv koktela: ";
		cin >> pIme;
		cout << "Unesi cijenu koktela za 0.33 litra: ";
		cin >> pCijena0330;
		cout << "Unesi cijenu koktela za 1 litar: ";
		cin >> pCijena1000;
		cout << "Unesi cijenu koktela za 2 litra: ";
		cin >> pCijena2000;
		return 0;
	};
	int fMinCijena() {
		float pMinCijenaMl;
		int pMl = 330;
		pMinCijenaMl = pCijena0330 / pMl;
		if (pMinCijenaMl > pCijena1000 / 1000) { pMinCijenaMl = pCijena1000 / 1000; pMl = 1000; };
		if (pMinCijenaMl > pCijena2000 / 2000) { pMinCijenaMl = pCijena2000 / 2000; pMl = 2000; };
		cout << "Najpovoljnije je kupiti koktel " << pIme << " od " << pMl << " ml." << endl;
		cout << "Cijena po mililitru je " << pMinCijenaMl << " dinara." << endl;
		return 0;
	};
	~iKoktel() {
		cout << "Koktel " << pIme << " je popijen." << endl;
	};
};

int main()
{
	kPice oKola;
	oKola.fUpisCijena();
	oKola.fProsjecnaCijena();
	oKola.fPopijenaKolicina();
	 
	iKoktel oPinacolada;
	oPinacolada.fUpisCijena();
	oPinacolada.fProsjecnaCijena();
	oPinacolada.fPopijenaKolicina();
	oPinacolada.fMinCijena();
	return 0;
}
