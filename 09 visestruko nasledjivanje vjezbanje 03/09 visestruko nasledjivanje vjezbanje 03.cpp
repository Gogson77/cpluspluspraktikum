#include <iostream>

using namespace std;

class A { int a; };
class B : A { int b; };
class C : A { int c;  };
class D : B, C { int d; };
D x;

void main()
{

}