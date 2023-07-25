#include <iostream>

using namespace std;

class kBroj
{
	int i;
public:
	kBroj(int x) { i = x; };
	int fUvecaj();
	int fMax(int, int);
};

inline int kBroj::fUvecaj() { return ++i; }

inline int kBroj::fMax(int a, int b) { return (a >= b) ? a : b; }

int main()
{
	kBroj oMoj(5);
	int rezultat = oMoj.fUvecaj();
	cout << "Rezultat je: " << rezultat << endl;
	int max = oMoj.fMax(5, 3);
	cout << "Max je: " << max << endl;
	return 0;
}