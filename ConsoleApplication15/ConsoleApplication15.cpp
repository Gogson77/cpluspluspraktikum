#include <iostream>
using namespace std;

int main() {
	int cijeliBroj = 5;
	const double pi = 3.14;
	float floatBroj = 5.4;
	double doubleBroj = 5.567;
	char slovo = 'a';

	cout << "pi = " << pi << endl;
	cout << "cijeliBroj = " << cijeliBroj << endl;
	cijeliBroj = pi; cout << "cijeliBroj = pi -> cijeliBroj = " << cijeliBroj << endl << endl;

	return 0;
}