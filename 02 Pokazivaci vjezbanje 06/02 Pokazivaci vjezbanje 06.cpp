#include <iostream>

using namespace std;

void fZamena(int&, int&);

void  main()
{
	int i = 10;
	int j = 20;
	cout << "\nPre zamene: i = " << i << ", j = " << j << endl;
	fZamena(i, j);
	cout << "\nPosle zamene: i = " << i << ", j = " << j << endl << endl;
}

void fZamena(int&x , int&y) {
	int pom;
	pom = x;
	x = y;
	y = pom;
};
