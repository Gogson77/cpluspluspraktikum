#include "Sfera.h"
#include <iostream>

using namespace std;

void Sfera::citaj()
{
	cin >> x >> y >> z >> r;
}

void Sfera::pisi() const
{
	cout << "C (" << x << ", " << y << ", " << z << ")" << endl;
	cout << "r = " << r << endl;
	cout << "P = " << povrsina() << "     V = " << zapremina() << endl;
	cout << "d = " << udaljenost() << endl;
}

void Sfera::c_tacka(double xx, double yy, double zz)
{
	x = xx; y = yy; z = zz;
}

void Sfera::c_pomak(double dx, double dy, double dz)
{
	x += dx; y += dy; z += dz;
}

double Sfera::udaljenost() const
{
	return sqrt(x * x + y * y + z * z);
}

double Sfera::rastojanje(const Sfera& a) const
{
	return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2) + pow(z - a.z, 2) - r - a.r);
}
