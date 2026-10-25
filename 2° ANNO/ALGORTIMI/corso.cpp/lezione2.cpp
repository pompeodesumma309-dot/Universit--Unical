/*#include <iostream>
using namespace std;

int main(){
    int i = 2024, *p=&i, &r=i;
    *p=0; // equivale a i=0
    r=42;
    cout<<*p<<endl; // stamperei 42
}

// TIPI DEFINITI DALL'UTENTE
/*Strutture di dati:
    - insieme di dati
    - operatori sui dati
    */


#include <iostream>
#include <cmath>

using namespace std;

struct punto {
    int x;
    int y;    
}; // Qui il punto e virgola serve

int main() {
    punto p1, p2;
    float distanza;

    cout << "Inserisci x e y del primo punto (es. 0 0): ";
    cin >> p1.x >> p1.y;

    cout << "Inserisci x e y del secondo punto (es. 3 4): ";
    cin >> p2.x >> p2.y;

    distanza = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

    cout << "Punto 1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "La distanza e' di: " << distanza << endl;

    return 0;
}
/* DI PIU' SU STRUCT E PUNTATORI
int main(){
    punto p1;
    p1.x=3, p1.x=4;
    punto *pp1=&p1;
}*/