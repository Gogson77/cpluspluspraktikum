#include <iostream>
using namespace std;

int fFakt(int pBroj)
{
	int pom;
	pom = ((pBroj > 0) ? (pBroj * fFakt(pBroj - 1)) : 1);
	cout << "\nPozvana funkcija fFakt" << pBroj-1 << endl;
	return pom; // return ( (pBroj > 0) ? ( pBroj * fFakt (pBroj-1)) : 1 );
}
int main()
{
	int pPrirodan;
	cout << "Unesi jedan prirodan broj : ";
	cin >> pPrirodan;
	cout << "\nFaktorijel broja " << pPrirodan << " je " << fFakt(pPrirodan) << "." << endl;
	return 0;
}