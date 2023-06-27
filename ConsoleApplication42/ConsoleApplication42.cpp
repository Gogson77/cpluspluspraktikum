#include <iostream>
using namespace std;

int main()
{
	int n, i, niz, brojac;
	float srednja;
	cout << " Unesi duzinu niza: " << endl;
	cin >> n;
	while (n > 0)
	{
		srednja = 0;
		brojac = 0;
		for (i = 1; i <= n; i++)
		{
			cout << " Unesi " << i << ". element niza: " << endl;
			cin >> niz;
			if (niz % 3 == 0 && niz % 5 != 0)
			{
				srednja += niz;
				brojac++;
			}
		}
		srednja /= brojac;
		cout << " Srednja vrednost je " << srednja << endl;
		cout << " Unesi duzinu niza: " << endl;
		cin >> n;
	}
	return 0;
}
