## LE FUNZIONI 
    una funzione è composta da:
    - un nome
    - un tipo di ritorno 
    - una lista di parametri 
    - un corpo, deve contenere return 

### ESEMPIO:
```cpp
int fact (int val){ // val: parametro formale
    int ret=1;
    while(val>1){
        ret*=val--; // equivalente a ret=ret*val; val=val-1
    }
    return ret;
}

int fact(int);

int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<endl; // n: parametro attuale 
}
```

Tipo di ritorno:
- tipo base
- tipo definitivo dall'utente
- void (in questo caso return)

```cpp
void stampaStelle(int n){
    for(int i=0; i<n; i++){
        cout<<"*";
    cout<<endl;
    return;
    }
}
    
```
## FUNZIONI CON PIU' PARAMETRI 
```cpp
int f1(){...}
int f3(int v1, v2){...}
int f4(int v1, int v2){...} // modo corretto per passare i parametri
```

## OVERLOADING DELLE FUNZIONI 
due funzioni con lo stesso nome, vengono distinte dal numero e/o dal tipo dei parametri:
```cpp
int f4(int v1, int v2, int v3);
int f4(int v1, int v2, int v3){...}
```

## PASSAGGIO DEI PARAMETRI
- per valore
- per riferimento (le modifiche fatta all'interno della funzione si ribaltano sul parametro attuale)
- per riferimento costante

```cpp
int fact (int val){ // passaggio per valore
    int ret=1; 
    while(val>1){
        ret*=val--;
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
}

//passaggio per riferimento 
int fact (int &val){  
    int ret=1;
    while(val>1){
        ret*=val--;
    }
    return ret;
}

//passaggio per riferimento costante

int fact (const int &val){ // non perdere tempo a fare la copia, ma non toccarmi il contenuto
    
    int ret=1;
    while(val>1){
        ret*=val--; // ERRORE!!
    }
    return ret;
}
```

```cpp
struct punto{
    int x;
    int y;
};

double distanza(const punto &, const punto&);

int main(){
    punto a,b;
    double d;
    cin>>a.x>>a.y; cin>>b.x>>b.y;
    
    d=distanza(a,b);

    cout<<"la distanza e'"<<endl;

return 0;
}

double distanza(const punto & p1, const punto & p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))
}
```

```cpp
// passaggio puntatore per valore
int f(int *p){
    *p=0;
    return  *p;
}

int main(){
    int v=5; int *pp=&v;
    cout<<f(pp)<<endl; //stampa 0
}

//ancora sull'overloading
int f(int n);// NO
void f(int n); // NO

int f1(int n); // OK
int f1(float n); // OK

int f2(auto n);
```

## LA RICORSIONE
```cpp
int fact(int val){
    if (val<=1) return 1;
    else return fact(val-1)*val;
}

int main(){
    int n; cin>>n;
    cout<<fact(n)<<endl;
}
```

### Un'altro esempio di ricorsione (fibonacci)
```cpp
int fib(int n){
    if ((n==0) || (n==1)) return n;
    else return fib(n-1)+fib(n-2);
}

```

### ESERCIZIO PER CASA SCRIVERE LA FUNZIONE ITERATIVA DI FIBONACCI
