#include <iostream>
#include "funkcije.h"

using namespace std;

int main()
{
    int i, j, k, n, mat[MAX][MAX];
    cout << "Odredi velicinu kvadratne matrice: ";
    cin >> n;
    cout << "Unesite elemente matrice: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        cout << "\nNajveci clan " << k + 1 << ". vrste je " << fMax(mat, k, n) << endl;
        cout << "Najmanji clan " << k + 1 << ". vrste je " << fMin(mat, k, n) << endl;
    }

    int niz[MAX];
    int brojElemenata;
    cout << "\nUnesite broj elemenata niza: ";
    cin >> brojElemenata;
    cout << "Unesite elemente niza: " << endl;
    for (i = 0; i < brojElemenata; i++)
    {
        cin >> niz[i];
    }

    int prvaPozicijaMin = prvaPozicijaNajmanjeg(niz, brojElemenata);
    int poslednjaPozicijaMax = poslednjaPozicijaNajveceg(niz, brojElemenata);

    cout << "Prva pozicija (index) najmanjeg elementa: " << prvaPozicijaMin << endl;
    cout << "Posljednja pozicija (index) najveceg elementa: " << poslednjaPozicijaMax << endl;

    int vrsta1, vrsta2;
    cout << "\nUnesite redne brojeve vrsti koje zelite zamijeniti: " << endl;
    cin >> vrsta1 >> vrsta2;

    zamijeniVrste(mat, vrsta1 - 1, vrsta2 - 1, n);

    cout << "Matrica nakon zamjene vrsti:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int najveci, najmanji, redNajveceg, kolonaNajveceg, redNajmanjeg, kolonaNajmanjeg;
    pronadjiNajveciINajmanjiElement(mat, n, najveci, najmanji, redNajveceg, kolonaNajveceg, redNajmanjeg, kolonaNajmanjeg);

    cout << "Najveci element: " << najveci << endl;
    cout << "Najmanji element: " << najmanji << endl;
    cout << "Pozicija najveceg elementa: (" << redNajveceg << ", " << kolonaNajveceg << ")" << endl;
    cout << "Pozicija najmanjeg elementa: (" << redNajmanjeg << ", " << kolonaNajmanjeg << ")" << endl;

    return 0;
}
