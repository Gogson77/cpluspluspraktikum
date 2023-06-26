#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double xmin, xmax, dx, x, y;
	int i, n;

	cout << "Unesi donju i gornju granicu: " << endl;
	cin >> xmin >> xmax;
	cout << " Unesi korak: " << endl;
	cin >> dx;
	cout << " Unesi n: " << endl;
	cin >> n;

	for (x = xmin; x >= xmin && x <= xmax; x += dx)
	{ 
		y = 0;
		for (i = 0; i < n; i++) 
			y += pow(x, i);
			cout << " x = " << x << ", y = " << y << endl;
	}
	return 0;
}
