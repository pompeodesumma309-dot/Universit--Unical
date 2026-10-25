// Il tipo di ritorno diventa 'int' al posto di 'bool'
int cercaPosizione(int v[], int dim, int x) {
    
    int posizione = -1; 

    for (int i = 0; i < dim && posizione == -1; ++i) { 
        
        if (v[i] == x) {
            posizione = i; 
        }
    }
    
    return posizione;
}

#include <iostream>
using namespace std;

const int dim = 10; 

int cercaPosizione(int v[], int dim, int x); // Prototipo aggiornato

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
