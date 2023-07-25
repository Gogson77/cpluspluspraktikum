#include <iostream>
using namespace std;

void fPovecaj(int& a) { a++; };

void main()
{ 
	//primjer 1
	int x = 1;
	fPovecaj(x);
	cout << x << endl;

	//primjer 2
	typedef double& pDouble;
	double a, b;
	pDouble ua = a, ub = b;
	ua = ub = 5;
	cout << ua << endl << ub << endl;

	//primjer 3
	int* pok = new int;
	if (pok != NULL)
		int& ref = *pok;

	//primjer 4

}