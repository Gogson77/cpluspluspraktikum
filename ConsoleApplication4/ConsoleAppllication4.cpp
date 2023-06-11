#include <iostream>
#include <string.h>
using namespace std;

class kPrimer
{
    public:
    int pBroj;
    kPrimer(){
        pBroj = 0;
    };
    ~kPrimer(){
        cout << "Ja sam destruktor."<<endl;
    };
};

int main ()
{
    kPrimer oMoj;
    cout << oMoj.pBroj << endl;
    return 0;
}