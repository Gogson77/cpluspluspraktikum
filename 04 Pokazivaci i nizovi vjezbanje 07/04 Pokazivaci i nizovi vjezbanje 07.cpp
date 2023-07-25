#include <iostream>
#include <stdlib.h>
#define MAX_BROJ 100
#define MAX_IME 30

using namespace std;

struct sAdresa {
	char pIme[MAX_IME + 1];
	char pUlica[MAX_IME + 1];
	int pBroj;
	char pGrad[MAX_IME + 1];
};

class kRokovnik {
public:
	sAdresa *pAdr;
	kRokovnik();
	sAdresa* fUpis(int n);
	void fPrikazAdresa(sAdresa pAdr[], int n);
	void fGreska(void);
	~kRokovnik();
};

kRokovnik::kRokovnik() { pAdr = 0; }

sAdresa* kRokovnik::fUpis(int n) {
	pAdr = new sAdresa[n];

	if (pAdr == NULL)
		fGreska();

	cout << "~~~~~~~~~~~~~~~~ UNOS ADRESA ~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\nIme: ";
		cin >> pAdr[i].pIme;

		cout << "\nUlica i broj: ";
		cin >> pAdr[i].pUlica >> pAdr[i].pBroj;

		cout << "\nGrad: ";
		cin >> pAdr[i].pGrad;
	}
	return pAdr;
};

void kRokovnik::fPrikazAdresa(sAdresa pAdr[], int n) {
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~ ADRESE ~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\nIme:\t\t" << pAdr[i].pIme << endl;
		cout << "\nUlica i broj:\t" << pAdr[i].pUlica << " " << pAdr[i].pBroj << endl;
		cout << "\nGrad:\t\t" << pAdr[i].pGrad << endl << endl;
	}
}

void kRokovnik::fGreska(void) {
	cout << "Nije uspjela dodjela memorije." << endl;
	exit(1);
}

kRokovnik::~kRokovnik() {
	pAdr = 0;
	delete(pAdr);
};

int main()
{
	sAdresa* pok;
	kRokovnik oMoj;
	int n;
	cout << "Unesi broj prijatelja koje zelis da upises u rokovnik: ";
	cin >> n;
	pok = oMoj.fUpis(n);
	oMoj.fPrikazAdresa(pok, n);
	pok = 0;
	delete(pok);
}