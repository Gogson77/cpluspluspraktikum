#include <iostream>
using namespace std;
class A{
	int a;
	friend class D;
public:
	A() {}
	~A() {}
protected:
	void napuni() { a = 1; }
	void stampaj() { cout << "klasa A: a=" << a << endl; }
};
class D{
	A oa;
	int d;
public:
	void napuni() { oa.a = 1; d = 3; }
	void stampaj() { cout << "klasa D: d=" << d << " "; oa.stampaj(); }
};
class B {
protected:
	D od;
	int b;
public:
	void napuni() { b = 2; od.napuni(); }
	void stampaj(){ cout << "klasa B: b=" << b << " "; od.stampaj(); }
};
class C : public B{
	int c;
public:
	void napuni() { c = 4; od.napuni(); b = 20; }
	void stampaj() { cout << "klasa C : c=" << c << "  b=" << b << " "; od.stampaj(); }
};
void main() {
	C objc;
	B objb;
	D objd;
	objb.napuni();
	objc.napuni();
	objd.napuni();
	objd.stampaj();	cout << endl;
	objb.stampaj();	cout << endl;
	objc.stampaj();	cout << endl;
}
