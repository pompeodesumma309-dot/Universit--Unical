### I GRAFI 
Sono composti da: 
- Nodi e Archi

### GRAFI NON ORIENATATI E ORIENTATI 
>NON ORIENTATO 

L'arco non ha direzione se A è collegato a B, allora anche B è collegato ad A.

>ORIENTATO  

L'arco ha una direzione: se A può essere collegato a B senza che valga il contrario

Proprietà:
- numero di nodi (fissato): n nodi
- numero di archi: O(n<sup>2</sup>)

Grafo orientato -> n<sup>2</sup>    
Grafo non orientato -> (n * (n - 1)) / 2


**GRAFI DENSI** -> m ~ O(n<sup>2</Sup>)  
**GRAFI SPARSI** -> m ~ O(n)

### GRADO DI UN NODO
Per il grafo non orientato è il numero di nodi adiacenti.


Per il grado orientato il **grado di entrata** e il **grado di uscita**, dove naturalmente, il grado di entrata è il numero di gradi entrati e l'uscita è dato dal numero di archi uscenti.

### CAMMINO
è una senquenza di archi ordinati che mi permette di raggiungere un nodi j da un nodi i attraversando una sequenza di nodi.

Il numero di cammini possibili è esponenziale. 

>Nel grafo orientato i cammmini possibili di riducono di molto.

Si distingue dal cammino semplice al cammino ciclico:
- **Semplice**: non ripasso sullo stesso nodo
- **Ciclico**: passo più volte dallo stesso nodo

Ciclico -> se finiamo almeno in un cicli  
Aciclico -> se non c'è la possibilità di finire almeno su un ciclo

### AUTOARCHI
è possibile definirli in caso abbiamo almeno un ciclo. Arco uscente ed entrata sullo stesso nodo.


### GRAFO CONNESSO
se per ogni coppie di nodi di j, j è raggiungibili da i. Se esiste almeno un cammino tra ogni coppia di nodi.
Se per ogni coppia di nodi j è raggiungibile.

Un grado orientato può essere:
- **fortemente connesso** 
- **Debolmente connesso** -> se la sua versione non orientata è connesso

### CHIUSURA TRANSITIVA DI UN GRAFO G
è ottenuto se, G primo ha un arco tra i e j se, j è raggiungibile da i in G.


### RAPPR. GRAFI
**1.** Matrice di adiacenza -> la più semplice  
Informazione sui nodi: andiamo a metterli sul vector dei nodi  
p(i,j) -> contiene il "peso" dell'arco i,j.

Sono buone per archi densi.

**2.** Per i grafi sparsi: **LISTE DI ADIACENZA**  
Possiamo usare: vector<list<int.>> 
Guadagno in spazio O(m) e tempo di enumrazione adiacenti O(n), perdo nell'accesso al singolo arco g(i,j) -> O(n)


### IMPLEMENTAZIONE

```cpp
class Grafo{
protected:
    vector<vector<bool>> archi;
    int nv, mv;

public:
    Grafo(int _n);

    int n() const;
    int m() const;    

    void operator() (int i, int j, bool b); // b crea/cancella l'arco
    bool operator() (int i, int j) const; // restituisce true se l'arco esiste
    
    Grafo& operator=(const Grafo& g);
};
```

### ESERCIZIO: dato un grafo restituire per ogni nodo il numero di adiacenti

```cpp
vector<int> numAdiacenti (const Grafo& g){
    vector<int> grado(g.n());
    for(int i=0; i<g.n(); ++i){ // enumero tutti i nodi di g
        grado[i] = 0;

        for(int j=0; i<g.n(); ++j){
            if(i!=j && g(i,j)) grado[i]++;
        }
    }
    return grado;
}
```
### Dato un grafo orientato, restituisci un grado non orientato G1 ottenuto da G eliminando l'orientamento dei nodi.
```cpp
Grafo disorienta(const Grafo& G){
    Grafo G1(G.n());
    for (int i=0, i<G.n(); ++i){
        for(int j=0; j<G.n(); ++j){
            if (i!=j && G(i,j)) {
                G1(i,j,true);
                G1(j,i, true);
            }
        }
    }
    return G1;
}
```

### VISITE SUI GRAFI
- **DFS** (in profondità) -> i più lontani
- **BFS** (in ampiezza, gli adiacenti prima)

Esempio: valutazione - stampa  
DFS partendo da 1 : 1 2 3 4 5 6 -> devo quindi ricordarmi di aver visitato gia il 4 per non entrare in un loop infinito.

DFS partendo da 5 : 5 6 4 

BFS partendo da 1 : 1 2 6 7 3 4 5

### VISITA DFS
Deve ricevere un punto di partenza
```cpp
void dfs(int s, const Grafo& g, vector<bool> & visitati){
    visitati[s] = true;
    valuta(s);.......
    for(int j=0; j<g.n(); ++j){
        if(!s=j && g(s,j) && !visitati[j]){
            dfs(j, g, visitati);
        }
    }
}

```

### Visita in ampiezza -> O(n<sup>2</sup>)
```cpp
vector<bool> bfs(const Grafo& g, int s){
    vector<bool> visitati(g.n(), false);

    queue<int> q;
    q.push(s);
    visitati[s] = true;

    while(!q.empty()){

        int u = q.top();
        q.pop();
        valuta(u);

        for(int v=0; v<g.n(); ++v){
            if (u!=v && g(u,v) && !visitati[v]){

                q.push(v);
                visitati[v] = true;
            }
        }
    }
    return visitati;
}
```

### ESERCIZIO: CALCOLARE LA CHIUSURA TRANSITIVA DI UN GRAFO
G1 è la chiusura transitiva di G se per ogni coppia di nodi (u,v), se v è raggiungibile da u in G, esiste un arco (u,v) in G1

```cpp
Grafo chiusuraTransitiva(const Grafo& G){
    Grafo G1(G.n());

    for(int u=0; u<G.n(); ++u){
        vector<bool> raggiungibili=bfs(G, u);

        for(int v=0; v<G.n(); ++v){
            if(u!=v && raggiungibili[v]){

                G1(u,v,true);
            }
        }
    }
    return G1;
}
```

### DATO UN GRAFO E DUE NODI (u, v) CALCOLARE UN CAMMINO, SE ESISTE, TRA s E t

```cpp
vector<int> bfs(const Grafo& g, int s){

    vector<bool> visitati(g.n(), false);
    vector<int> p(g.n(), -1);
    queue<int> q;

    q.push(s);
    visitati[s] = true;
    p[s] = s;
    
    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int v=0; v<g.n(); ++v){
            if(u!=v && g(u,v) && !visitati[v]){
                q.push(v);
                p[v] = u;
                visitati[v] = true;
            }
        }
    }
    return p;
}
```

```cpp
void trovaCammino(int s, int t, const vector<int> & p, queue<int> & cammino){

    if(s==t) cammino.push(s);
    else if (t==-1) return;
    else{
        trovaCammino(s, p[t], p, cammino);
        cammino.push(t);
    }
}
```

```cpp
queue<int> ricostruisciCammino(int s, int t, const Grafo& g){
    vector<int> precedessori=bfs(g, s);
    queue<int> c;

    if(precedessori[t] == -1) return c;
    trovaCammino(s, t, predecessori, c);
    return c;

}
```

```cpp
bool trovaCammino(const Grafo& g, int s, int t, vector<bool> & visitati, list<int> & cammino){
    if (s==t){

        visitati[s] = true;
        return true;
    }
    else{

        visitati[s] = true;
        bool trovato = false;

        for(int j=0; j<g.n() && !trovato; ++j){
            if(s!=j && g(s,j) && !visitati[j]){

                cammino.push(j);
                trovato = trovaCammino(g, j, t, visitati, cammino);
                if(!trovato) cammino.pop_back();
            }
        }

        return trovato;
    }
}

```

### SOLUZIONE ESERCIZIO: SCRIVERE UNA FUNZIONE ESERCIZIO 1 CHE RESTITUSICA UNA STRINGA

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string esercizio1 (const Grafo& G){
    bool verifica = true;
    for (int i=0; i<G.n() && verifica; ++i){
        int somma=0;

        for(int j=0; j<G.n(); ++j){
            if(i!=j && G(j,i) != 0) somma+=G(j,i);
        }

        if(somma>= G.dep(i)) verifica = false;
    }
    if(!verifica) return "NO";

    for(int i=0; i<G.n() && verifica; ++i){
        for (int j=0; j<G.n(); ++j){

            if(i!=j && G(j,i) !=0 && G.dep(j) < G.dep(i)) verifica = true;
        }
    }
}

```
