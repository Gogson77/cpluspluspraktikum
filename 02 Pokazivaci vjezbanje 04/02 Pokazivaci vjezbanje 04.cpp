#include <iostream>

using namespace std;

void main()
{
	int i, x = 10, y = 20, z[4] = { 10, 20, 30, 40 };
	int* ptr;
	ptr = &x;

	y = *ptr;		// y sadrži broj na koji pokazuje pokazivač ptr, a to je  x  tj. 10
	*ptr = 0;		// postavljanje pokazivača  ptr  na  null  vrednost
	ptr = z;			// ptr sadrži adresu prvog elementa niza  z, tj. na  z[0]
	*ptr = 1;		// elemenat na koji pokazuje  ptr postaje 1, tj.  z[0] = 1
	*(ptr + 1) = 2;		// elemenat na koji pokazuje  (ptr+1)  postaje 2, tj.  z[1] = 2
	*(ptr + 2) = 3;		// elemenat na koji pokazuje  (ptr+2)  postaje 3, tj.  z[2] = 3
	*(ptr + 3) = 4;		// elemenat na koji pokazuje  (ptr+3)  postaje 4, tj.  

	cout << "x = " << x << endl;
	cout << "y = " << y << endl << endl;

	for (i = 0; i < 4; i++)
		cout << "z [" << i << "] = " << *(z + i) << endl;

	cout << endl << endl;


}