# LEZIONE 5°

## PUNTATORI E ARRAY E L'ARITMETICA DEI PUNTATORI
```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia è l'indirizzo della prima cella
auto ia2=ia; // ia2 ha tipo int *
int *p=ia; // equivalente alla precedente. (NON COPIO L'ARRAY)
ia2 = 42; // ERRORE

cout<<ia2; // stampa l'indirizzo
cout<<*ia2; // stampa ia[0]
ia2++;
cout<<*ia2; //stampta ia[1]
cout<<ia2[1]; // stampa ia[2]

begin(ia) // restituisce il puntatore al primo elemento 
end(ia) //restituisce il puntatore alla prima cella dopo la fine

auto n = end(ia) - begin(ia); // n è la dimensione di ia

int * beg = begin(ia);
int * end = end(ia);

while(beg!=end){    
    cout<<*beg<<" ";
    ++beg;  // questo pezzettino di codice stampa l'array
}

```

## PUNTATORI E MEMORIA DINAMICA
Allocare o deallocare spazio di memoria al bisogno usato anche se non conosco il tipo preciso di un oggetto a design time.

OPERATORI DI BASE: 
- new e delete
```cpp
int *pi = new int;
int *pi2 = new int(1024);

delete pi;
delete *pi; //errore

//ESEMPI:
int i , *pil=&i, *pi=nullptr;
double *pd = new double(33), *pd2=pd;
delete i; //NO, i non è un puntatore
delete pi1; //undefined
delete pd;
delete pd2;
delete pi2; //è un puntatore nullo, se cancelliamo è ok perchè posso sempre chiedere di cancellare un'area di memoria nulla, non farà nulla
```

## ALLOCAZIONE DINAMICA ARRAY
```cpp
const int capacity = 10;
int* elenco = new int[capacity]; //sto dichiarando un array dove manca il nome, posso usarlo sia come puntatore che come array
cin>>elenco[0];

delete elenco; //starei chiedendo di cancellare l'intero puntato da elenco
delete [] elenco; // elimina n celle dell'array, cancella tutto, interpreta l'elenco come array

```

ESEMPIO: caricare un numero indefinito di elementi in un array
```cpp
#include <iostream>
using namespace std;

const int dim_base=10;

int main(){
    int *elenco = new[dim_base];
    int size = 0, elem, capacity=dim_base;
    while(cin>>elem){
        if (size<capacity){
            elenco[size++]=elem; // invece di inserire poi ++size;
            
        }
        else{
            resize(elenco, capacity, dim_base);
            elenco[size++]=elem;
        }
    }

return O;
}

void resize(int * & v, int & capacity, int &increment){
    int *temp = new int[capacity+increment];
    for (int i=0; i<capacity; ++i){
        temp[i]=v[i];
    }

    delete [] v;
    v = temp;
    capacity+=increment;
}

```
## STRINGHE (C-STYLE)
```cpp
char * str = new chat[10];
cin>>str; // solo con CHAR*

#include <iostream>
strlen(s) // restituisce la lunghezza della stringa 
strcmp(s1,s2) // string compare restituisce 0 se s1==s2
                // un valore positivo se s1>s2
                // un valore negativo se s1<s2
stract(s1,s2) // concatena s2 ad s1, restituisce s1 modificato
stropy(s1,s2) // copia s2 in s1, restituisce s1 modificato

```