#include <iostream>

using namespace std;

class X {
public:
	int a;
	int b;
	int c;
};


void main() {
	int X ::* pok = &X::a;	//  pok  ukazuje na  člana  a  klase  X
	X  ox, oy, * pokx = &ox;
	ox.*pok = 2;		//  ox.a = 2
	pok = &X::b;			//  pok  ukazuje sada na  člana  b  klase X
	oy.*pok = 3;			//  oy.b = 3 
	pok = &X::c;			//  pok  ukazuje sada na  člana  c  klase X
	pokx ->* pok = 4;			//  pokx -> c = 4  ili   ox.c = 4
}
