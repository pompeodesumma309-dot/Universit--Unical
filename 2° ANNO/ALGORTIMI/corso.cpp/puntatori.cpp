#include <iostream>
using namespace std;

const int dim = 10;

int cercaPosizione(int v[], int dim, int x); // Prototipo

// Il tipo di ritorno diventa 'int' al posto di 'bool'
int cercaPosizione(int v[], int dim, int x) {
    // Invece di 'bool trovato = false', usiamo una variabile per la posizione
    // Inizializzata a -1 che significa "per ora non l'ho trovato"
    int posizione = -1;

    // Il trucco del prof si adatta: continua il ciclo finché non finisci l'array
    // E finché la posizione è ancora -1
    for (int i = 0; i < dim && posizione == -1; ++i) {
        if (v[i] == x) {
            posizione = i; // Trovato! Mi segno la cella 'i' in cui si trova.
        }
    }

    return posizione; // Alla fine restituirà l'indice (es. 2) oppure -1
}

int main() {
    int v[dim], x;

    // Lettura dell'array
    cout << "Inserisci " << dim << " numeri:" << endl;
    for (int i = 0; i < dim; ++i) {
        cin >> v[i];
    }

    cout << "Inserisci la x da cercare: ";
    cin >> x;

    // Salvo il risultato della funzione in una variabile
    int risultato = cercaPosizione(v, dim, x);

    // Se il risultato è diverso da -1, significa che l'ha trovato
    if (risultato != -1) {
        cout << "Trovato! Il numero si trova nella posizione: " << risultato << endl;
    }
    else {
        cout << "Non trovato." << endl;
    }

    return 0;
}