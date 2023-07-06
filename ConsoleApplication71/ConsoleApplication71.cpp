#include <iostream>
#define MAX 10
using namespace std;

int fTransponovanje(int a[MAX][MAX], int n)
{
	int i, j, b[MAX][MAX];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			b[j][i] = a[i][j];

	for (i=0; i<n; i++)
	{
		for (j = 0; j < n; j++)
			cout << b[i][j] << " ";
		cout << endl;
		return 0;
	}
};

int main()
{
	int a[MAX][MAX], i, j, n;

	cout << "Unesite dimenziju matrice: ";
	cin >> n;

	cout << "Unesite elemente matrice: " << endl;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];

	fTransponovanje(a, n);

	return 0;
}