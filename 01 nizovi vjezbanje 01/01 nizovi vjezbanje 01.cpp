#include <iostream>

using namespace std;

float fProsek(float meseci[]);

int fSort(float meseci[]);

int main()
{
	float meseci[6] = {1,2,3,4,5,6};
	int i = 0;

	while (i < 6)
	{
		cout << "Unesite platu za " << meseci[i] << ". mesec" << endl;
		cin >> meseci[i];
		i++;
	}

	cout << "\n\nSortirani niz plata je:" << endl
		<< endl;
	fSort(meseci);
	cout << "Prosek je:" << fProsek(meseci) << endl << endl;

	return 0;
}

float fProsek(float meseci[])
{
	float prosek = 0, suma = 0;

	for (int i = 0; i < 6; i++)
		suma = suma + meseci[i];

	prosek = suma / 6;
	return prosek;
};

int fSort(float meseci[])
{
	int i, j;
	float pom;
	for (i = 0; i < 6; i++)
		for (j = i + 1; j < 6; j++)
			if (meseci[i] < meseci[j])
			{
				pom = meseci[i];
				meseci[i] = meseci[j];
				meseci[j] = pom;
			}
	for (i = 0; i < 6; i++)
		cout << meseci[i] << endl;
	cout << endl << endl;
	return 0;
};