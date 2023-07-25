#pragma once
#include <math.h>

const double PI = 3.14159265359;

class Sfera
{
	// koordinate centra i poluprečnika
	double x, y, z, r;

public:
	// sastavljanje sfere
	void sastavi(double xx, double yy, double zz, double rr)
	{
		x = xx; y = yy; z = zz; r = rr;
	}

	// dohvatanje atributa
	double dohvati_x() const { return x; }
	double dohvati_y() const { return y; }
	double dohvati_z() const { return z; }
	double dohvati_r() const { return r; }

	// čitanje
	void citaj();

	// pisanje
	void pisi() const;

	// površina 
	double povrsina() const { return 4 * r * r * PI; }

	// zapremina
	double zapremina() const { return 4 / 3 * pow(r, 3) * PI; }

	// premeštanje centra sfere u novu tačku
	void c_tacka(double xx, double yy, double zz);

	// premeštanje centra sfere za neki pomak
	void c_pomak(double dx, double dy, double dz);

	// udaljenost centra od koordinatnog početka
	double udaljenost() const;

	// rastojanje između periferija dve sfere
	double rastojanje(const Sfera&) const;
};