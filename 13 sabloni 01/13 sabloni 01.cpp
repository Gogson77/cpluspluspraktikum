#include <iostream>

using namespace std;

template <class T>
void sort(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(a[i], a[minIndex]);
        }
    }
}

// Klasa za kvadrat
class Kvadrat {
public:
    Kvadrat(int str) : stranica(str) {}
    int povrsina() const {
        return stranica * stranica;
    }
    bool operator<(const Kvadrat& uporedni) const {
        return povrsina() < uporedni.povrsina();
    }

private:
    int stranica;
};

int main() {
    // Niz cijelih brojeva
    int nizCijelihBrojeva[] = { 5, 2, 9, 1, 8, 6 };
    int velicinaNizaCijelihBrojeva = sizeof(nizCijelihBrojeva) / sizeof(int);
    sort(nizCijelihBrojeva, velicinaNizaCijelihBrojeva);

    cout << "Sortirani niz cijelih brojeva: ";
    for (int i = 0; i < velicinaNizaCijelihBrojeva; i++) {
        cout << nizCijelihBrojeva[i] << " ";
    }
    cout << endl;

    // Niz karaktera
    char nizKaraktera[] = { 'd', 'a', 'c', 'b', 'e' };
    int velicinaNizaKaraktera = sizeof(nizKaraktera) / sizeof(char);
    sort(nizKaraktera, velicinaNizaKaraktera);

    cout << "Sortirani niz karaktera: ";
    for (int i = 0; i < velicinaNizaKaraktera; i++) {
        cout << nizKaraktera[i] << " ";
    }
    cout << endl;

    // Niz kvadrata
    Kvadrat nizKvadrata[] = { Kvadrat(3), Kvadrat(1), Kvadrat(4), Kvadrat(2) };
    int velicinaNizaKvadrata = sizeof(nizKvadrata) / sizeof(Kvadrat);
    sort(nizKvadrata, velicinaNizaKvadrata);

    cout << "Sortirani niz kvadrata (po povrsini): ";
    for (int i = 0; i < velicinaNizaKvadrata; i++) {
        cout << nizKvadrata[i].povrsina() << " ";
    }
    cout << endl;

    return 0;
}