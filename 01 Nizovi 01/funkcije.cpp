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

int prvaPozicijaNajmanjeg(int niz[MAX], int n)
{
    int min = niz[0];
    int pozicija = 0;
    for (int i = 1; i < n; i++)
    {
        if (niz[i] < min)
        {
            min = niz[i];
            pozicija = i;
        }
    }
    return pozicija;
}

int poslednjaPozicijaNajveceg(int niz[MAX], int n)
{
    int max = niz[0];
    int pozicija = 0;
    for (int i = 1; i < n; i++)
    {
        if (niz[i] >= max)
        {
            max = niz[i];
            pozicija = i;
        }
    }
    return pozicija;
}

void zamijeniVrste(int mat[MAX][MAX], int vrsta1, int vrsta2, int n)
{
    for (int j = 0; j < n; j++)
    {
        int temp = mat[vrsta1][j];
        mat[vrsta1][j] = mat[vrsta2][j];
        mat[vrsta2][j] = temp;
    }
}

void pronadjiNajveciINajmanjiElement(int mat[MAX][MAX], int n, int& najveci, int& najmanji, int& redNajveceg, int& kolonaNajveceg, int& redNajmanjeg, int& kolonaNajmanjeg)
{
    najveci = mat[0][0];
    najmanji = mat[0][0];
    redNajveceg = 0;
    kolonaNajveceg = 0;
    redNajmanjeg = 0;
    kolonaNajmanjeg = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > najveci)
            {
                najveci = mat[i][j];
                redNajveceg = i;
                kolonaNajveceg = j;
            }

            if (mat[i][j] < najmanji)
            {
                najmanji = mat[i][j];
                redNajmanjeg = i;
                kolonaNajmanjeg = j;
            }
        }
    }
}