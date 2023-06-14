#include <iostream>
using namespace std; 

typedef enum eGodDoba { ljeto = 1, jesen, zima = ljeto + 6, proljece };

int main()
{
	eGodDoba pDoba;
	eGodDoba pDoba2;
	
	pDoba = jesen;		cout << "pDoba = " << pDoba << endl;
	pDoba = zima;		cout << "dDoba = " << pDoba << endl;
	pDoba = proljece;	cout << "dDoba = " << pDoba << endl;

	return 0;
}
