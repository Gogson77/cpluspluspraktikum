# include <iostream>
# include <math.h>
using namespace std;

int fFakt(int pBroj)
{
    int i, pom = 1;
    for (i = pBroj; i > 0; i--)
        pom = pom * i;
    return pom;
};

float fSuma(int x, float eps)
{
    int a = 1, k = 1;
    float s = 1, stari = 0;
    while (abs(s - stari) >= eps)
    {
        a = -a * x * x;
        s += a / fFakt(2 * k);
        stari = s;
        k++;
    };
    return s;
};

float fProizvod(float eps)
{
    int q = 1, n = 0;
    float a = 1, stari;
    do {
        stari = a;
        n++;
        a = a * (1 + pow(-1, n) / fFakt(++q));
    } while (abs(a - stari) >= eps);
    return a;
};

void main()
{
    int izbor, x, pBroj;
    float eps, rez;
    cout << "Izaberi neku opciju:" << endl;
    cout << "1 - Izracunavanje faktorijela" << endl;
    cout << "2 - Izracunavanje sume" << endl;
    cout << "3 - Izracunavanje proizvoda" << endl;
    cout << "4 - Kraj" << endl;
    cin >> izbor;
    switch (izbor)
    {
    case 1: cout << "\nUnesi broj: ";
        cin >> pBroj;
        rez = fFakt(pBroj);
        cout << "Faktorijel broja " << pBroj << " je " << rez << endl;
        break;
    case 2: cout << "\nUnesi x: ";
        cin >> x;
        cout << "\nUnesi tacnost: ";
        cin >> eps;
        rez = fSuma(x, eps);
        cout << "\nRezultat je " << rez << endl;
        break;
    case 3: cout << "\nUnesi tacnost: ";
        cin >> eps;
        rez = fProizvod(eps);
        cout << "\nRezultat je " << rez << endl;
        break;
    case 4: break;
    default: break;
    };
}