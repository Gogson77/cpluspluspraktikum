#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Tacka
{
	double x, y;
public:
	Tacka(double xx = 0, double yy = 0) : x(xx), y(yy) {};
	double dohvati_x() const { return x; }
	double dohvati_y() const { return y; }
	void citaj() { cin >> x >> y; }
	void pisi() const { cout << "[" << x << ", " << y << "]" << endl; }
	friend double rastojanje(const Tacka& a, const Tacka& b) { return (sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2))); };
	~Tacka() {};
};