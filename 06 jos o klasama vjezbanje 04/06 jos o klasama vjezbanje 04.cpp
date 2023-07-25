#include <iostream>

using namespace std;

//class X {
//	static int i;
//	int j;
//public:
//	static int k;
//};
//
//int X::i = 5;
//int X::k = -3;

class X {
	static int x;
	int y;
public:
	static int f(X, X&);
	int g();
};

int X::x = 5;

int X::f(X x1, X&x2)
{
	int i = x;
	//int j = y; // greska
	int k = x1.y;
	return x2.x;
}

int X::g() {
	int i = x;
	int j = y;
	return j;
}

void main()
{
	X ox;
	int p = X::f(ox, ox);
	//int q = X::g();
	ox.g();
	p = ox.f(ox, ox);
}