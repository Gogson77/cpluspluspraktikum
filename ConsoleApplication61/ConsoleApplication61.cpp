#include <iostream>
using namespace std;

void fNeVraca(int x) {
	x = 20;
};

int fNemaArg(void) {
	int x = 30;
	return x;
};

int main()
{
	int a = 10;
	cout << "Sadrzaj promjenljive nakon inicijalizacije: " << a << endl;
	fNeVraca(a);
	cout << "Sadrzaj promjenljive nakon poziva funkcije fNeVraca: " << a << endl;

	a = fNemaArg();
	cout << "Sadrzaj promjenljive nakon poziva funkcije fNemaArg: " << a << endl;
	return 0;
}