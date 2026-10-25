#include <iostream>
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
} // Niente punto e virgola qui

// DI PIU' SU STRUCT E PUNTATORI
int main(){
    punto p1;
    p1.x=3, p1.y=4;
    punto *pp1=&p1;

    cout<<(*pp1).x<<(*pp1).y<<endl;
    cout<<pp1->x<<pp1->y<<endl;
    
}

//ISTRUZIONI DI CONTROLLO DEL FLUSSO
while (condizione){ blocco_while};

do {blocco} while (condizione);

for (int i; ckeck; update) {blocco};

//Esempi:
// while:
int main(){
    int sum=0, val=1;
    while (val<=10){
        sum+=val;
        val = val + 1; //equivalente ++val
        
    }
    cout<<sum;
    return 0;
}

//Esempio di do while

int sum=0, val=1;
do{
    sum+=val;
    ++val:

} while(val<=10);

//Esempio con il for:
for(int val=1; val<=10; ++val){
    sum+=val;
}

//ESEMPIO:
int main(){
    int sum=0, value;
    while (cin>>value){ //ctrl + z in windows
        sum+=value;
    }
    cout<<"La somma e': "<<sum<<endl;
}

// ISTUZIONI CONDIZIONALI: 
if (condizione){
    //blocco if

} else{
    //blocco else
}
// il blocco else è opzionale

//ESEMPIO: determianre il massimo in una sequenza letta da input
int main(){
    int maxVal, currVal;
    if(cin>>currVal){
        maxVal=currVal
        while (cin>>currVal){
            if (currVal>maxVal){
                maxVal=currVal;
            }
        }
        cout<<"Il massimo e': "<<maxVal<<endl;
    }
    else {cout<<"Nessun dato"<<endl;}
return 0;
}

/*ESERCIZIO PER CASA:
   scrivere un programma che stampi tutta la tabellina del 10 in modo BEN FORMATTATO:
   cioè 1 2 3 4 ...
    1   1 2 3 4
    2   2 4 6 8
    3   3 6
    4
    .
*/

//ESERCIZIO: trovare il massimo ed il submasssimo tra 10 numeri positivi letti da intput

//ESERCIZIO: scrivere un programma che determini se un numero è primo.
// operatore % (modulo): x%y restituisce il resto della divisione tra x e y.

#include <iostream>
#include <cmath>*__
using namespace std;

int main(){
    int numero;
    cout<<"Inserisi un numero:"<<endl;
    cin>>numero;
    
    bool isPrime=true;

    if (numero<=1){
        return false;
    }
    for(int i; i<=sqrt(numero); i++){
        if(numero%i){
            isPrime=false;
        }
    }
    if (isPrime==true){
        cout<<"Il numero e' primo."<<endl;
    } else {cout<<"il numero non e' primo:"<<endl;}


}
