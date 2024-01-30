#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funció per inicialitzar la baralla amb valors de 1 a 52
void inicialitzarBaralla(int baralla[], int numCartes) {
    for (int i = 0; i < numCartes; ++i) {
        baralla[i] = i + 1;
    }
}

// Funció per intercanviar dues cartes a la baralla
void intercanviarCartes(int& carta1, int& carta2) {
    int temp = carta1;
    carta1 = carta2;
    carta2 = temp;
}

// Funció per barrejar la baralla
void barrejarBaralla(int baralla[], int numCartes) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < numCartes; ++i) {
        int indexAleatori = rand() % numCartes;
        intercanviarCartes(baralla[i], baralla[indexAleatori]);
    }
}

// Funció per mostrar les cartes d'una mà
void mostrarMa(int ma[], int numCartes) {
    for (int i = 0; i < numCartes; ++i) {
        int valorCarta = (ma[i] - 1) % 13 + 1;
        char simbolCarta;

        if (valorCarta == 1) {
            simbolCarta = 'A';
        }
        else if (valorCarta >= 2 && valorCarta <= 10) {
            simbolCarta = static_cast<char>('0' + valorCarta);
        }
        else {
            simbolCarta = "TJQK"[valorCarta - 11];
        }

        cout << simbolCarta << " ";
    }
    cout << endl;
}

// Funció principal per repartir cartes
void repartirCartes(int baralla[], int numCartes) {
    int ma[5]; // Una mà de pòquer té 5 cartes

    // Barrejar la baralla abans de repartir
    barrejarBaralla(baralla, numCartes);

    // Repartir 5 cartes
    for (int i = 0; i < 5; ++i) {
        ma[i] = baralla[i];
    }

    // Mostrar la mà repartida
    cout << "Cartes repartides: ";
    mostrarMa(ma, 5);
}

int main() {
    const int NUM_CARTES = 52;
    int baralla[NUM_CARTES];

    // Inicialitzar la baralla
    inicialitzarBaralla(baralla, NUM_CARTES);

    // Repartir cartes i mostrar-les
    repartirCartes(baralla, NUM_CARTES);

    return 0;
}
