#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int x, y;
	cout << "Unesi vrednost za promenljivu x : " << endl;
	cin >> x;
	if (x < 0) { y = -5; }
	else if (x >= 0 && x <= 3) { y = x * x - 5; }
	else if (x > 3 && x < 10) { y = -3 * x + 10; }
	else if (x >= 10){ y = -17; }
	cout << "Za x = " << x << ", y = " << y << endl;

	return 0;
}
