// main.cpp
#include "kVreme.h"
#include <iostream>

using namespace std;

int main()
{
	kVreme t1 = fVreme(0, 0, 0); // Initialize t1 with a default value
	kVreme t2 = fVreme(0, 0, 0); // Initialize t2 with a default value
	int k = 0;
	long s1, s2;

	cin >> k;
	cin >> t1.t;
	cin >> t2.t;
	s1 = fVremeUSek(t1);
	s2 = fVremeUSek(t2);
	cout << "k              = " << k << endl;
	cout << "t1, t2        = " << t1 << ", " << t2 << endl;
	cout << "s1             = " << s1 << " (" << fVreme(s1) << ")" << endl;
	cout << "s2             = " << s2 << " (" << fVreme(s2) << ")" << endl;
	cout << "- t1           = " << -t1 << endl;
	cout << "++ t1        = " << ++t1 << endl;
	cout << "t2 --          = " << t2-- << endl;
	cout << "t1              = " << t1 << " (" << fVremeUSek(t1) << ")" << endl;
	cout << "t2              = " << t2 << " (" << fVremeUSek(t2) << ")" << endl;
	cout << "t1 + t2       = " << t1 + t2 << endl;
	cout << "t1 - t2        = " << t1 - t2 << endl;
	cout << "t1 == t2    = " << (t1 == t2) << endl;
	cout << "t1 > t2        = " << (t1 > t2) << endl;
	cout << "t1 * k         = " << t1 * k << endl;
	cout << "t1 / k         = " << t1 / k << endl;
	cout << "s1 + t2 * k    = ";
	cout << fVreme(s1) + t2 * k << " (" << s1 + fVremeUSek(t2 * k) << ")" << endl;
	cout << endl;

	return 0; // Indicate successful execution
}
