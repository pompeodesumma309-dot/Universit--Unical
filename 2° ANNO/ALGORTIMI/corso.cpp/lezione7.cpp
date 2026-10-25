# LEZIONE 7°

## COMPLESSITA' COMPUTAZIONALE
### - Modello di costo: 
- dimensione dell'input
- costo delle istruzioni elementari
### - Complessità temporale
### - Complessità spaziale 
### - Complessità di I/O

Supponiamo algoritmo A, con input grande n. Ho 3 algoritmi per A e di seguire A su una macchina che impiega 10^-6 sec per istruzione.


| num. di ap. | n = 10 | n = 10.000 |n = 10^6|
|----------|-----------|-----------|----------|
| A      n | 10<sup>-5 sec | 10<sup>-2 sec  |1 sec|
| B      n<sup>2| 0,1 msec.  | 100 sec  |10<sup>6 sec (12 giorni)|
| C     n log<sub>n| 0,000003 sec| 0,13 sec|19 sec|


### - Dimensione dell'input:
- La/le variabili che determinano il numero di operazioni

### - Istruzioni elementari (di costo unitario):
- lettura / scrittura
- assegnamento, operazioni aritmetiche predefinite
- return 
- acceso diretto ad un elemento in memoria centrale
- espressioni booleane (elementari, in combinazioni)

```cpp 
i=1; // 1 assegnamento esterno che esegue una sola volta
while(i<=n){ //  faccio n+1 confronti
    i=i+1; // 1 istruzione elementare che eseguo n volte
}
// il numero totale di istruzioni di questo pezzo di codice è 2 + 2n
```
```cpp
i=1;
while(i*i<=n){
    i=i+1;
}
// il numero totale di istruzioni di questo pezzo di codice è f(n) = 2+2radice(n)
```
```cpp
for (int i=1; i<n; ++i){
    for (int j=1; j<n; ++j){
        cout<<"*";
    cout<<endl;
    }
}
```
```cpp
i=0;
while((i<=13) && A[i]!=8){ i = i+1; } // quante operazioni elementari eseguirò per risolvere? Beh, dipende, le operazioni che faccio dipendono dall'input. Ad esemppio, se il valore 8 non c'è, impiego 14 operazioni. Se il valore 8 è in prima posizioni, impiego 1 operazione. Se l'8 è in mezzo, impiego 7 operazioni.

```
- CASO PEGGIORE &rarr; quando l'8 non c'è
- CASO MIGLIORE &rarr; quando l'8 è in prima posizione
- CASO MEDIO &rarr; quando l'8 è a metà posizione


### ANALISI ASINTOTICA DELLA COMPLESSITA' (NOTAZIONE ASINTOTICA)

Notazione O grande, notazione omega, notazione theta

$$
f(n)\in O (g(n)) se\ \exists c,n\ t.c.\ \forall n> n_0 \ 0<= f(n)<=c*g(n)
$$

*ESEMPIO*
| Notazione | Descrizione / Proprietà |
| :--- | :--- |
| $O(1)$ | Costante |
| $O(n)$ | Lineare |
| $O(n^2)$ | Quadratico |
| $O(\log n)$ | Logaritmico |
| $O(n \log n)$ | |
| $O(2^n)$ | Esponenziale |
 

### Aritmetica degli O
O(1) + O(n) = O(n)  
O(n) * O(n) = O(n<sup>2</sup>)

### Blocco di istruzioni
```cpp
void stampaStelle(int ns){
    for (int i =1; i<=ns; ++i){ //  ns volte -> O(ns)
        cout<<"*";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n; 

    for(int i=1;i<=n; ++i){
        stampaStelle(n);
    }
    return 0;
}
```

### Ricerca lineare: C.P. O(n), C.M: O(1)
>Prerequisiti: Nessuno

### Ricerca binaria:
>Prerequisiti: ARRAY ORDINATO

```cpp
bool ricercaBinaria(int V[], int x, int in, int fin){
    if(in>=fin) return ((in==fin) && (x==V[in]));
    int medio = (in+fin)/2;
    if (V[medio]<x) in = medio + 1;
    else if (x<V[medio]) fin = medio - 1;
    else return (V[medio]==x);

    return ricercaBinaria(V, x, in ,fin);

}
```
### Ricerca uniforme: C.P. O(n) C.M. O(1)
se la stima è "buona" può essere molto più efficiente della ricerca binaria  
Prerequisiti: array ordinato, stima accettabile 

```cpp
bool ricercaUniforme(int v[], int x, int in, int fin){
    if(in>=fin || x<v[in] || v[fin]<x || v[in]==v[fin]) return ((in<=fin) && (x==v[in]));
    
    else{
        int m = in+(fin-in)*(x-v[in]) / (v[fin]-v[in]);
        if(v[m]<x) in = m+1;
        else if (x<v[m]) fin = m-1;
        else return (x==v[m]);
    }
    return ricercaUniforme(v,x,in,fin);
}