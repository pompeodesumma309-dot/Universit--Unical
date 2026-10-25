# LEZIONE 6°

```cpp
int a=5; //scrive il valore 5 all'indirizzo 
cout<<a<<endl; //stampa 5
cout<<&a<<endl; //stampa l'indirizzo di a

int b[5]= {1,2,3,4,5}; //scrive i valori 
cout<<b<<endl; //stampa l'indirizzo
cout<<&b<<endl; //stampa l'indirizzo 
for (int i=0; i<5;i++)
    cout b[i]<<endl; //stampa i numeri da 1 a 5 
for (int i=0; i<5; i++)
    cout<<&b[i]<<endl; //stampa dal primo indirizzo (dove ho il numero 1 n ell'array in memoria) dino all'ultimo (dove ho l'ultimo indirizzo in memoria del valore 5)


int *b= new int[5]; //alloca 5 posizioni in memoria
for (int i=0; i<5;i++) 
    b[i]=i+1;
cout<<b<<endl; //stampa il primo indirizzo in memoria
cout<<&b<<; // stampa l'ultimo indirizzo in memoria 
for (int=0;i<5;i++)
    cout<<b[i]<< endl; //stampa i numeri da 1 a 5
for (int i=0; i<5; i++)
    cout<<&b[i]<<endl; //stampa dal proimo all'ultimo indirizzo in memoria
delete [] b;

```

```cpp
int* a = new int(1);
int *b = new int(2);

int* tmp=a;
a=b;
b = temp;

delete a;
delete b;
```

## ESERCIZIO SULLA RICORSIONE
```cpp
#include <iostream>
using namespace std; 

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n==1){
        cout<<"Move disk 1 from rod" <<from_rod<<" to rod "<<to_rod<<endl;
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to rod "<<ro_rod<<endl;
    towerOfHanoi(n-1, aux_rod, to_rod,fromo_rod);

}

int main(){
    int n;
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
```
- PROVARE A FARE QUESTO ESERCIZIO IN MANIERA ITERATIVA

ESERCIZIO: SCRIVERE UNA FUNZIONE RICORSIVA CHE RICEVA IN INPUT UNA STRINGA E DETERMINI SE E' PALINDROMA --> FATTO IN AULA


ESERCIZIO: PUNTO DI SELLA --> FATTO IN CLASSE

- ESERCIZIO DA FARE CARICATO SU TEAMS --> PER CASA

```cpp


```
