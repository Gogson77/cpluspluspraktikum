#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void aritmetickaSredina(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        double suma = 0.0;
        for (int j = 0; j < size; j++) {
            suma += matrix[i][j];
        }
        double aritmeticka = suma / size;
        cout << "Aritmeticka sredina reda " << i + 1 << ": " << aritmeticka << endl;
    }

    for (int j = 0; j < size; j++) {
        double suma = 0.0;
        for (int i = 0; i < size; i++) {
            suma += matrix[i][j];
        }
        double aritmeticka = suma / size;
        cout << "Aritmeticka sredina kolone " << j + 1 << ": " << aritmeticka << endl;
    }
}

void geometrijskaSredina(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        double proizvod = 1.0;
        for (int j = 0; j < size; j++) {
            proizvod *= matrix[i][j];
        }
        double geometrijska = pow(proizvod, 1.0 / size);
        cout << "Geometrijska sredina reda " << i + 1 << ": " << geometrijska << endl;
    }

    for (int j = 0; j < size; j++) {
        double proizvod = 1.0;
        for (int i = 0; i < size; i++) {
            proizvod *= matrix[i][j];
        }
        double geometrijska = pow(proizvod, 1.0 / size);
        cout << "Geometrijska sredina kolone " << j + 1 << ": " << geometrijska << endl;
    }
}

void aritmetickaSredinaIspodGlavne(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 1; i < size; i++) {
        double suma = 0.0;
        int brojac = 0;
        for (int j = 0; j < i; j++) {
            suma += matrix[i][j];
            brojac++;
        }
        double aritmeticka = suma / brojac;
        cout << "Aritmeticka sredina elemenata ispod glavne dijagonale u redu " << i + 1 << ": " << aritmeticka << endl;
    }
}

void aritmetickaSredinaIznadGlavne(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size - 1; i++) {
        double suma = 0.0;
        int brojac = 0;
        for (int j = i + 1; j < size; j++) {
            suma += matrix[i][j];
            brojac++;
        }
        double aritmeticka = suma / brojac;
        cout << "Aritmeticka sredina elemenata iznad glavne dijagonale u redu " << i + 1 << ": " << aritmeticka << endl;
    }
}

void aritmetickaSredinaGlavnaDijagonala(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    double suma = 0.0;
    int brojac = 0;
    for (int i = 0; i < size; i++) {
        suma += matrix[i][i];
        brojac++;
    }
    double aritmeticka = suma / brojac;
    cout << "Aritmeticka sredina elemenata na glavnoj dijagonali: " << aritmeticka << endl;
}

void aritmetickaSredinaSporednaDijagonala(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    double suma = 0.0;
    int brojac = 0;
    for (int i = 0; i < size; i++) {
        suma += matrix[i][size - i - 1];
        brojac++;
    }
    double aritmeticka = suma / brojac;
    cout << "Aritmeticka sredina elemenata na sporednoj dijagonali: " << aritmeticka << endl;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> size;

    cout << "Unesite elemente matrice:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Aritmeticka sredina:" << endl;
    aritmetickaSredina(matrix, size);
    cout << endl;

    cout << "Geometrijska sredina:" << endl;
    geometrijskaSredina(matrix, size);
    cout << endl;

    cout << "Aritmeticka sredina elemenata ispod glavne dijagonale:" << endl;
    aritmetickaSredinaIspodGlavne(matrix, size);
    cout << endl;

    cout << "Aritmeticka sredina elemenata iznad glavne dijagonale:" << endl;
    aritmetickaSredinaIznadGlavne(matrix, size);
    cout << endl;

    cout << "Aritmeticka sredina elemenata na glavnoj dijagonali:" << endl;
    aritmetickaSredinaGlavnaDijagonala(matrix, size);
    cout << endl;

    cout << "Aritmeticka sredina elemenata na sporednoj dijagonali:" << endl;
    aritmetickaSredinaSporednaDijagonala(matrix, size);
    cout << endl;

    return 0;
}