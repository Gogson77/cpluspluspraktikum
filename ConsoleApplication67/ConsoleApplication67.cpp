#include <iostream>
using namespace std;

int fMax(int i, int j) { return (i>j)?i:j; };
double fMax(double i, double j) { return (i>j)?i:j; };
char fMax(char i, char j) { return (i>j)?i:j; };

int main()
{
	int a = fMax(1, 2);
	cout << a << endl;

	double b = fMax(1.0, 2.0);
	cout << b << endl;

	char c = fMax('a', '3');
	cout << c << endl;

//	double d = fMax(1, 2.0); // GREŠKA

	double e = 1;
	cout << e << endl; // e = 1.0

	double f = fMax(e, 2.0); // poziva se fMax (double, double)
	cout << f << endl; // f = 2.0

//	int g = fMax(1, '3'); // GREŠKA

	int h = '3';
	cout << h << endl; // h = 51

	int l = fMax(1, h); // poziva se fMax (int, int)
	cout << l << endl; // l = 51

	return 0;
}