#include <iostream>
using namespace std;

int main()
{
	int n;
start: cout << " Unesite ceo broj od 0 do 10: " << endl;
	cin >> n;
	if (n < 0 || n > 10) goto start;
	else if (n == 0) goto loc0;
	else goto loc1;
loc0: cout << " Izabrali ste broj 0 " << endl;
	goto end;
loc1: cout << "Izabrali ste broj od 1 do 10. " << endl;
end: return 0;
}