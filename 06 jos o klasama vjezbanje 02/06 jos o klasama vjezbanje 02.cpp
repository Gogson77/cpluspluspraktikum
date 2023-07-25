#include <iostream>

using namespace std;

class X {
	enum { a = 100 };
	friend class Y;
};

class Y {
	int b[X::a];

};

void main()
{


}