#include <iostream>

using namespace std;

void main()
{
	int k = 1;
	int& u = k;				
	int x = u;				// x = 1
	u = 2;					// k = 2
	u++;					// k = 3
	cout << x << endl;
	cout << k << endl;
}