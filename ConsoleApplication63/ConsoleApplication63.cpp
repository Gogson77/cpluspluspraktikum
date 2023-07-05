#include <iostream>
using namespace std;

int fMax(int x, int y);
int fMax4(int x, int y, int z, int w);

int main()
{
	int a, b, c, d;
	cout << "Unesi cetiri cijela broja: ";
	cin >> a >> b >> c >> d;
	c = fMax(a, b);
	cout << "\nNajveci od cetiri unijeta broja je broj " << fMax4(a, b, c, d) << "." << endl;

	return 0;
}

int fMax(int x, int y) {
	return ( (x > y) ? x : y ); 
}

int fMax4(int x, int y, int z, int w) {
	int pom;
	pom = ( fMax ( fMax(x,y) , fMax(z,w) ) );
	return pom;

};