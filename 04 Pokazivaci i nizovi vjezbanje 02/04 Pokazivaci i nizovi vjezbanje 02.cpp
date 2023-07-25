#include <iostream>
#include <stdlib.h>
#define MAX 50

using namespace std;

int main()
{
	int i, n, max, *pNiz;
	do{
		cout << "\nBroj elemenata niza: " << endl;
		cin >> n;
	} while (n<1 || n>MAX);
	pNiz = new int[n];
	if (pNiz == NULL){
		cout << "Nije uspjela dodjela memorije." << endl;
		exit(1);
	}
	cout << "\nUnesite vrijednosti elemanta niza:" << endl;
	for(i=0; i<n; i++)
		cin >> pNiz[i];
	max = pNiz[0];
	for (i=0; i<n; i++) 
		if (pNiz[i]>max) 
			max = pNiz[i];
	cout << "Najveca vrijednost zadatog niza je " << max << endl;
	pNiz = 0;
	delete(pNiz);

}