#include <iostream>
#include <stdlib.h>
#define MAX_BROJ 2
#define MAX_IME 30

using namespace std;

struct sAdresa {
    char pIme[MAX_IME + 1];
    char pUlica[MAX_IME + 1];
    int pBroj;
    char pGrad[MAX_IME + 1];
};

void fPrikazAdresa(struct sAdresa pAdr[], int n);
void fGreska(void);

int main()
{
    sAdresa* pAdr;
    pAdr = new sAdresa[MAX_BROJ];

    if (pAdr == NULL)
        fGreska();

    cout << "~~~~~~~~~~~~~~~~ UNOS ADRESA ~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < MAX_BROJ; i++) 
    {
        cout << "\nIme: ";
        cin.get(pAdr[i].pIme, MAX_IME + 1);

        cout << "\nUlica i broj: ";
        cin >> pAdr[i].pUlica >> pAdr[i].pBroj;

        cout << "\nGrad: ";
        cin >> pAdr[i].pGrad;

        cin.ignore();
    }

    cout << endl;
    fPrikazAdresa(pAdr, MAX_BROJ);

    pAdr = 0;
    delete(pAdr);
}

void fPrikazAdresa(struct sAdresa pAdr[], int n) {
    cout << "~~~~~~~~~~~~~~~~ ADRESE ~~~~~~~~~~~~~~~~" << endl;
    for (int i=0; i<MAX_BROJ; i++) {
        cout << "\nIme:\t\t" << pAdr[i].pIme << endl;
        cout << "\nUlica i broj\t" << pAdr[i].pUlica << pAdr[i].pBroj << endl;
        cout << "\nGrad:\t\t" << pAdr[i].pGrad << endl << endl;
    }
}

void fGreska(void) {
    cout << "Nije uspjela dodjela memorije." << endl;
    exit(1);
}