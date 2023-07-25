#include <iostream>

using namespace std;

int fSuma(int [], int*);

// I način - Korišćenjem indeksa niza
//int fSuma(int x[], int* a) {
//	int s = 0;
//	for (int i = 0; i < 5; i++) {
//		cout << i + 1 << ". broj je " << x[i] << endl;
//		s = s + x[i];
//		*a = i;
//	}
//	return s;
//};

// II način - Korišćenjem pokazivača
int fSuma(int x[], int* a) {
	int s = 0;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". broj je " << *x << endl;
		s = s + *x++;
		*a = i;
	}
	return s;
};

int main()
{
	int niz[5] = { 3,-5,10,4,-2 };
	int sum;
	int n;

	cout << "Niz ulaznih brojeva: " << endl << endl;
	sum = fSuma(niz, &n);
	cout << "\nSuma niza brojeva je: " << sum << endl;
	cout << "\nProsjek je: " << sum / n << endl << endl;



	/*int niz[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* ptr, i;
	ptr = niz;

	cout << ptr << endl;
	cout << &niz[0] << endl;

	for (i = 0; i < 10; i++)
	{
		cout << "\n" << ptr++;
	}

	cout << endl << endl;*/

    return 0;
}
