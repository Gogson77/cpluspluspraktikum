#include <iostream>
# include <math.h>

using namespace std;

class kNiz {
public:
	kNiz() {}
	virtual void fIzracunaj(int x) = 0;
	~kNiz() {}
};
class iFibonaci :public kNiz {
public:
	iFibonaci() { }
	void fIzracunaj(int x) {
		int i, niz[50];
		niz[0] = niz[1] = 1;
		for (i = 2; i < x; i++)
			niz[i] = niz[i - 1] + niz[i - 2];
		for (i = 0; i < x; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	~iFibonaci() { }
};
class iKvadrat :public kNiz{
public:
	iKvadrat() { }
	void fIzracunaj(int x) {
		int i, niz[50];
		for (i = 0; i < x; i++)
			niz[i] = pow(i + 1, 2);
		for (i = 0; i < x; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	~iKvadrat() { }
};
class iPel :public kNiz{
public:
	iPel() { }
	void fIzracunaj(int x) {
		int i, niz[50];
		niz[0] = 1;
		niz[1] = 2;
		for (i = 2; i < x; i++)
			niz[i] = niz[i - 2] + 2 * niz[i - 1];
		for (i = 0; i < x; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	~iPel() { }
};
class iLukas :public kNiz {
public:
	iLukas() { }
	void fIzracunaj(int x){
		int i, niz[50];
		niz[0] = 1;
		niz[1] = 3;
		for (i = 2; i < x; i++)
			niz[i] = niz[i - 1] + niz[i - 2];
		for (i = 0; i < x; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	~iLukas() { }
};
class iTrougao :public kNiz{
public:
	iTrougao() { }
	void fIzracunaj(int x){
		int i, niz[50];
		niz[0] = 1;
		for (i = 1; i < x; i++)
			niz[i] = niz[i - 1] + i + 1;
		for (i = 0; i < x; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	~iTrougao() { }
};
class iPentagonal :public kNiz{
public:
	iPentagonal() { }
	void fIzracunaj(int x){
		int i, niz[50];
		for (i = 0; i < x; i++)
			niz[i] = (i + 1) * (3 * i + 2) / 2;
		for (i = 0; i < x; i++)
			cout << niz[i] << " ";
		cout << endl;
	}
	~iPentagonal() { }
};
void main()
{
	kNiz* pok = 0;
	int izbor = 1, a;
	while (izbor != 0)
	{
		cout << "\n1-Fibonaci\t2-Kvadratni\t3-Pelov\t4-Lukasov\t5 - Trougaoni\t6 - Pentagonalni\t0 - Kraj\n";
			cout << "Unesi svoj izbor: ";
		cin >> izbor;
		switch (izbor)
		{
		case 1: pok = new iFibonaci; break;
		case 2: pok = new iKvadrat; break;
		case 3: pok = new iPel; break;
		case 4: pok = new iLukas; break;
		case 5: pok = new iTrougao; break;
		case 6: pok = new iPentagonal; break;
		case 0: default: exit(1);
		}

		cout << "Unesi broj elemenata niza: ";
		cin >> a;
		pok->fIzracunaj(a);
	}
	delete pok;
}
