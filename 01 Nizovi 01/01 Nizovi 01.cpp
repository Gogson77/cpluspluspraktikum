#include <iostream>
#include "funkcije.h"

using namespace std;

int main()
{
    int i, j, k, n, mat[MAX][MAX];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        cout << "\nMax = " << k + 1 << "-te vrste je " << fMax(mat, k, n) << endl;
        cout << "Min = " << k + 1 << "-te vrste je " << fMin(mat, k, n) << endl << endl;
    }
    return 0;
}
