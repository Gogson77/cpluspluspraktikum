#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int z, a, b;
    a = b = 5;
    z = a++;
    cout << "z=" << z << ",a=" << a << endl;
    z = ++b;
    cout << "z=" << z << ",b=" << b << endl;

    a = b = 5;
    z = a--;
    cout << "z=" << z << ",a=" << a << endl;
    z = --b;
    cout << "z=" << z << ",b=" << b << endl;

    return 0;
}