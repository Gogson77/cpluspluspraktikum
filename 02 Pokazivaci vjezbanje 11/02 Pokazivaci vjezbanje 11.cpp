#include <iostream>

using namespace std;

void fStampa(int* x, int* y, int* z);

void main()
{
	int a = 0, b = 0, c = 0;
	fStampa(&a, &b, &c);
	cout << "a = " << a << ", b = " << b << ", c = " << c;
	cout << endl << endl;
}

void fStampa(int* x, int* y, int* z)
{
	*x = 2;
	*y = 4;
	*z = 6;
}
