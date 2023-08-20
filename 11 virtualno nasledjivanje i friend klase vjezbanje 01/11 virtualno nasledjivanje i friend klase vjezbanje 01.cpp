#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << endl << 1; }
};

class B :virtual public A
{
public:
	B() { cout << 2; }
};

class C :virtual public A
{
public:
	C() { cout << 3; }
};

class D :virtual public A
{
public:
	D() { cout << 4; }
};

class E :public B, public C, public D
{
public:
	E() { cout << endl << 5; }
};

void main()
{
	A a;
	B b;
	C c;
	D d;
	cout << endl;
	E e;
	cout << endl;
}


//class A
//{
//public:
//	A() { cout << endl << 1; }
//};
//
//class B : public A
//{
//public:
//	B() { cout << 2; }
//};
//
//class C : public A
//{
//public:
//	C() { cout << 3; }
//};
//
//class D : public A
//{
//public:
//	D() { cout << 4; }
//};
//
//class E :public B, public C, public D
//{
//public:
//	E() { cout << endl << 5; }
//};
//
//void main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	cout << endl;
//	E e;
//	cout << endl;
//}
