#include "kTacka.h"
#include <iostream>
#include <math.h>

using namespace std;

double kTacka::fPocetak() const
{
	return sqrt(x * x + y * y);
}

double kTacka::fRastojanje(kTacka a) const 
{
	return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}

kTacka kTacka::fNajbliza(kTacka* a, int n) const 
{
	kTacka t = a[0];
	double r, m = fRastojanje(t);
	for (int i = 1; i < n; i++)
		if ((r = fRastojanje(a[i])) < m)
		{
			m = r;  t = a[i];
		}
	return t;
}

void kTacka::fCitaj() 
{
	cin >> x >> y;
}

void kTacka::fPisi() const 
{
	cout << "(" << x << ", " << y << ")";
}