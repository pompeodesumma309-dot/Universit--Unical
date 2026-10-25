# LEZIONE 8°
## ALGORITMI DI ORDINAMENTO
### BUBBLE SORT: algoritmo di ordinamento il loco
### C.P. O(N^2) C.M. O(N)  (C.P. SE ORDINATO AL CONTRARIO)
```cpp
void bubblesort(int a[], int N){
    bool scambi;
    int x=N, lastswap;
    do{
        scambi=false;
        for (int i=0; i<x-1; ++i){ // con il for cosi mi evito l'ultimo elemento

            if(a[i]>a[i+1]){

                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;

                lastswap=i+1;
                scambi = true;
            }
        }
        x=lastswap; // versione non ottimizzata x=x-1;
    }while(scambi);
}
```

### SELECTION SORT: C.P. O (N^2) C.M. O(N^2) 
```cpp
void selectionSort(int a[], int N){
    for(int i=1; i<N-1;++i){
        int min = i;
        for (int j=i+1; j<N; ++j){
            if(a[j]<a[min]) min=j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;

    }
}
```
### INSERTION SORT: C.P O( N^2) C.M. O(N)  (C.P. SE ORDINATO AL CONTRARIO, C.M. SE ARRAY GIA' ORDINATO)
```cpp
void insertionSort(int a[], int N){

    for (int i=0; i<N;++i){
        int temp = a[i];
        int j = i-1;

        while((j>=0) && (a[j]>temp)){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = temp;

    }
}
```
### COUNTING SORT: ordinato non il loco
### C.P. O(N+K) - LINEARE SOLO SE N DELLO STESSO ORDINE DI K    
### ATTENZIONE: può essere molto peggio di O(N^2) se K>>N
- Prerequisiti: valore dell'array usabili come indice di un altro array (solo array di interi)

Ordinare un array di interi, sapendo che v[i] in (0...K)
```cpp
void countingSort(int arr[], int sz){
    int i,j, k;
    int idx = 0;
    int min, max;

    min = max =arr[0];
    for (int i=0; i<sz; ++i){

        if (arr[i]<min) min=arr[i];
        if (arr[i]>max) max=arr[i];
    }

    k = max - min+1; // dimensione di B
    int *B = new int[k];

    for (int i=0; i<k; ++i) B[i]=0;

    //FASE 1
    for(int i=0; i<sz; ++i) B[arr[i]-min]++;

    //FASE 2
    for(i = min; i<=max; ++i)
        for(j=0; j<B[i-min]; ++j) arr[idx++] =i; 
    
    delete [] B;
}

```
# LEZIONE 9°
### ORDINAMENTO CON TECNICA DIVIDE ET IMPERA
- **DIVISIONE**: dividi il problema in n sotto-problemi
- **SOLUZIONE PARZIALE**: risolvi (ricorsivamente) gli n sotto-problemi
- **RICOMPOSIZIONE**: ricomponi le sotto-soluzioni per la soluzione complessiva  

### MARGE SORT

- **FUNZIONAMENTO**: ordiniamo l'array e lo dividiamo a metà. Utilizziamo due indici, uno per ogni metà.
```cpp 
void merge(int v[], int in, int fin, int medio){
    int a[fin-in+1]; // ci serve dello spazio aggiuntivo
    int i1=in, int i2=medio+1;
    int i3 = 0; // mi serve per scorrere a

    while((i1<=medio) && (i2<=fin)){
        if (v[i1]<v[i2]){ a[i3]=v[i1]; ++i1;}
        else {a[i3] = v[i2]; ++i2;}
        ++i3;
    }

    //Copia i residui
    while(i1<=medio) a[i3++] = v[i1++]; // a[i3] = v[i1]; i3++; i1++;
    while(i2<=fin) a[i3++] = v[i2++];

    //Trasferisci da a a v
    for (i3=0, i1=in; i1<=fin; ++i3; ++i1) v[i1] = a[i3];

}

```
**ORA LO FACCIAMO RICORSIVAMENTE (CONTINUAZIONE DEL SECONDO BLOCCO)**
```cpp
void mergeSort(int v[], int in, int fin, int medio){
    if ((fin-in) < 20){ // caso base
        insertionSort(v,in ,fin);
    }
    else{
        int medio = (in + fin)/2; // dividi
        margeSort(v, in, medio); // ordina parte sinistra
        margeSort(v, medio + 1, fin); // ordina parte destra
        marge(v, in , fin , medio); // ricomponi
    }
}
```

### QUICK SORT
C.P. O(N<sup>2</sup>) C.S. N LOG_N ; C.M. N LOG_N

- **FUNZIONAMENTO**: tutti gli elementi che sono a destra di x sono piu grandi, tutti gli elementi che sono a sinistra di x sono piu piccoli
```cpp
int partizione(int v[], int in, int fin){
    int i = in, j = fin + 1;
    while(i<j){
        do j--; while(v[j]>=v[in]);
        do i++; while(v[in]>=v[i] && i<j);
        if(i<j) scambia(v[i], v[j]);
    }
    scambia(v[in], v[j]);
    return j;
}

void quickSort(int v[], int in, int fin){
    if ((fin-in)<20) insertionSort(v, in, fin);
    else{
        int m = partizione(v, in, fin); //divisione
        quickSort(v, in, m-1); // risoluzione dei sottoproblemi 
        quickSort(v, m+1, fin);
    }   
}
```