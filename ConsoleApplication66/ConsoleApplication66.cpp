# include <iostream>
using namespace std;

float pIsta = 10.5;

float fSuma(float pPrvi, float pDrugi)
{
	float pIsta = 20.5;//ova promjenljiva se ne koristi
	return (pPrvi + pDrugi + (::pIsta));//koristi se globalna promjenljiva

	//return (pPrvi + pDrugi + (pIsta));//koristi se lokalna promjenljiva
}

int main()
{
	float a = 10.5, b = 10.5;
	cout << "Suma " << a << " + " << b << " + " << pIsta 
		<< " je: " << fSuma(a, b) << ".";
	cout << endl;
	return 0;
}