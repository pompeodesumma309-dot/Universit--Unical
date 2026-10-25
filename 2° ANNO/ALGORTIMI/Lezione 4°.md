# Lezione 4° 

## I puntatori
Il puntatore può essere usato in uno dei seguenti stati: 
- (1) può puntare a qualcosa;

- (2) può puntare alla locazione di memoria immediatamente successiva alla fine di un oggetto;

- (3)può essere un puntatore nullo, cioè un puntatore che non è associato a nessun oggetto ;

- (4)può essere non valido. nessun valore diverso dai precedenti è un valore valido.

### Inizializzazione dei puntatori a valore nullo:

```cpp

int *p1=nullptr; //equivalente a int*p1=0;
int *p2=0; //directly initializes p2 from the constant 0 
//must #include cstdlib 
int*p3=NULL; //equivalente a int*p3=0;
```

## Esercizio introduttivo su puntatori
Determinare l'output del seguente programma: 

```cpp
void main() {
    int a,b, *p1, *p2; //genera 2 variabili intere e 2 puntatori
    a=3;b=5; //assegno le variabili
    p1=&a; p2=&b //copio in p1 l'indirizzo di a, e in p2 l'indirizzo di b
    cout<<*p1<<*p2<<a<<b<<endl; //stampa 3,5,3,5

    p1=p2; //dentro il puntatore p1 metto il puntatore p2
    *p2=7; //assegno alla cella riferita da p2 il valore 7
    a=10; 
    cout<<*p1<<*p2<<a<<b<<endl; //stampa 7,7,10,7

    a=8; b=12;
    p1=&a; p2=&a;
    *p1=4;
    *p2=24; 
    cout<<*p1<<*p2<<a<<b; //stampa 24,24,24,12
}
```
 

## Gli arrey built-in

Posso accedere direttamente alla memoria con il loro indirizzo.
L'insieme di elementi devono essere dello stesso tipo (tutti float, tutti int...); il numero di elementi da mettere dentro lo possiamo decidere noi.
Un array si definisce identificando il tipo di ogni cella.

```cpp

tipobase nome[dimensione];
int a[10]; //a=indirizzo della prima cella
const int dim=10;
int a [dim]; //dimensione decisa a design time

int dim; cin>>dim;
int a[dim]; //la dimensione è decisa run time

int a2[]={0,1,2}; //inizializzo un array a 3 elementi che hanno i valori 0,1,2
const unsigned sz=3;
int a3[sz]={0,1}; //inizializza solo le prime due celle
//la terza è indefinita


Non è possibile leggere un array direttamente con cin
cin>>a2; //sbagliato

Non è possibile copiare un array direttamente (=)
a2=a3; //errore
```

 ```cpp
#include <iostream>
using namespace std;

const int dim=10;
int main(){
    int a [dim];
    cout<<"Inserisci"<<dim<<"elementi:"<<endl;

    for (int i=0; i<dim;++i) {
        cin>>a[i]; //leggo tutte le celle dell'array
    }
    cout<<"L'array letto e'"<<endl;

    for (int i=0; i<dim; ++i) {
        cout<<a[i]<<" "; //stampo tutti gli elementi separati da uno spazio
    }
    cout<<endl;

    return 0;
}
```
 
 

```cpp
for (auto elem:a) { //può creare problemi nelle funzioni
    cout<<elem<<" ";
}
```


## Array e funzioni:

```cpp
void print(int a[]){} //equivalente
void print (int a[10]) {} //equivalente (il 10 viene ignorato)
void print (int *a){} //quando passo un puntatore gli passo l'indirizzo della prima cella 
```
```cpp
void print(const int a [], int size){ //gli passo la size della dimensione dell'array

    for (int i=0; i<size; ++i) {
        cout<<a[i]<<endl;
    }
}
```

Gli array built-in sono sempre passati per riferimento


### Esercizio
Leggere un array V di 10 interi ed un elemento X e determinare se X è contenuto in V usando una funzione.

```cpp
const int dim=10; //variabile globale

bool cerca(int v[], int dim, int x); //dim è diversa dalla dim variabile globale

int main(){
    int v[dim], x;

    //lettura dell'array
    for (int i=0; i<dim; ++i){cin>>v[i];}
    cout<<"Inserisci la x da cercare";cin>>x;

    if (cerca(v, dim, x)) {cout<<"trovato"<<endl;}
    else {cout<<"non trovato"<<endl;}


    return 0;
}

bool cerca (int v[], int dim, int x) {
    bool trovato=false;

    for (int i=0; i<dim && !trovato; ++i){ //il for si ferma quando viene trovato l'elemento; appena lo trova si blocca e non vede il resto dell'array
         if (v[i]==x){
            trovato=true;}
    }
    return trovato;

}
```

modificare la funzione per far restituire la posizione in cui si trova x se è presente--> DA FARE PER CASA


## Array Multidimensionali

```cpp
int m[3][4]={
{0,1,2,3},
{4,5,6,7},
{8,9,19,11}
};


m[0][2];
const int rowsize=...
const int colsize=...

void print(int m[][colsize]){
    for (int i=0; i<rowsize; ++i) { 
        //qui fisso un indice di riga
        for (int j=0; j<colsize;++j) { //qui fisso l'indice di colonna
            cout<<m[i][j]<<"/t";

        }
        cout<<endl;
    }
}
```

### Esercizio
Scrivere una funzione che, data una matrice, determini se esistono due righe esattamente identiche

 ```cpp
const int rowSize=...;
const int colSice=...;

bool verifica (int m[][colSize], int rowSize, int colSize) {

    bool trovato=false;

    for (int r1=0: r1<rowSize && !trovato;++r1){
        for (int r2=r1+1; r2<rowSize && !trovato;++r2){
            bool identiche=true;

            for (int c=0; c<colSize &&identiche; ++c){
                if (m[r1][c]!=m[r2][c]) {identiche=false;}
            }
            if (identiche) {trovato=true;}
        }
    }
    return trovato;
}
```

Esercizio: scrivere una funzione che, data una matrice, determini se TUTTE le coppie di righe hanno almeno un elemento in comune, anche in colonne diverse.-->PER CASA


Esercizio: Letta una sequenza di numeri terminata da -1 e lunga al più capacity, memorizzarla oppurtunatamente in un array e compattare l'array, cioè eliminare tutti i numeri duplicati ed eliminare i "buchi" così generati spostando a sinistra i valori rimanenti.

 ```cpp
const int capacity=100;
void leggi_array (int v[], int & size, int capacity) {
    int c;
    cin>>c;
    while (c!=-1 && size<capacity){
        v[size]=c;
        ++size;
        cin>>c;
    }
}

void compatta (int v[], int &size){
    int i=0;
    while (i<size) {
        if (trovaato(v[i]), v, 0, i-1){
            cancella (v,i,size);
        }
        else {i++;}
    }
}

void cancella (int v[], int pos, int &size) {
    for (int i=pos; i<size-1; ++i){
        v[i]=v[i+1];
    }
    size--;
}

bool trovato(int x, int v[], int inf, int sup){
    for (int i=inf; i<=sup; ++i) {
        if (v[i]==x) {return true;}
    }
    return false;
}

int main(){
    int v[capacity];
    int size=0;
    leggi_array(v,size,capacity); //alla fine di leggi, size contiene il numero di elementi letti
    compatta (v,size);

    for (int i=0; i<size; ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}```
