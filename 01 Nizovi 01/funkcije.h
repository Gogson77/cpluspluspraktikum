#ifndef FUNKCIJE_H
#define FUNKCIJE_H

const int MAX = 50;

int fMax(int mat[MAX][MAX], int k, int n);
int fMin(int mat[MAX][MAX], int k, int n);
int prvaPozicijaNajmanjeg(int niz[MAX], int n);
int poslednjaPozicijaNajveceg(int niz[MAX], int n);
void zamijeniVrste(int mat[MAX][MAX], int vrsta1, int vrsta2, int n);
void pronadjiNajveciINajmanjiElement(int mat[MAX][MAX], int n, int& najveci, int& najmanji, int& redNajveceg, int& kolonaNajveceg, int& redNajmanjeg, int& kolonaNajmanjeg);

#endif