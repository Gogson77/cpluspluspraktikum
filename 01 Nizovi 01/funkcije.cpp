#include "funkcije.h"

int fMax(int mat[MAX][MAX], int k, int n)
{
    int max = mat[k][0];
    for (int i = 1; i < n; i++)
    {
        if (max < mat[k][i])
        {
            max = mat[k][i];
        }
    }
    return max;
}

int fMin(int mat[MAX][MAX], int k, int n)
{
    int min = mat[k][0];
    for (int i = 1; i < n; i++)
    {
        if (min > mat[k][i])
        {
            min = mat[k][i];
        }
    }
    return min;
}
