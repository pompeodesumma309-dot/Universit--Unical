# LEZIONE 17°

### USO DELLE TABELLA HASH COME INDICE SU STRUTTURE DATI
```cpp
Studente 
    matricola
    cf
    nome
```

Tabella hash di studenti  
    <matricola, studente>  
    <cf, studente>

Tab.hash <matricola, indice>  
         <     cf  , indice>

Associo la posizione dello studente con la matricola/cf. Due modalità di ricerca.

```cpp
#include <iostream>
#include <vector>
#include <stirng>
#include <unordered_map>
#include <map>
using namespace std;

class Studente{ // facciamo un semplice esempio, queste cose dovrebbero andare nel private 
    public:
        int matricola;
        string CF;
        string nome;
}


int main(){
    vector<Studente> archivio;

    cout<<"Inserisci 3 studenti: "<<endl;

    for (int i = 0; i<3; ++i){

        cin>>m>>cf>>nome;
        Studente s; s.matricola = m; s.CF=cf; s.nome= nome;

        archivio.push_back(s);
    }

    for(int i=0; i<3; ++i){
        cout<<archivio[pos].matricola<<" "<<archivio[i].cf<<" "<< archivio[i].nome<<endl;
    }

    // costruiamo gli indici da zero
    map<int, int> indice_matricola;
    unordered_map<string, int> indice_cf;
    
    //scorro tutti gli elementi di archivio e aggiorno tutti gl indici
    for(int i=0; i<archivio.size(); ++i){

        indice_matricola[archivio[i].matricola] = i;
        indice_cf[archivio[i].cf] = i;
    }

    for (auto it = indice_matricola.begin(); it != indice_maricola.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    cout<<"Inserisci una matricola da cercare:"<<endl;
    cin>>m;

    if(indice_matricola.find(m) !=indice_matricola.end()){

        int pos = indice_matricola[m];

        cout<<"la posizione restituita e': "<<pos<<endl;

        cout<<"Lo studente cercato e': "<<archivio[pos].matricola<<" ";
        cout<<archivio[pos].cf<<" "<<archivio[pos].nome<<endl;


    }
    else cout<<"lo studente non esiste."<<endl;

    

return 0;   
}
```

### PER INDICIZZARE VECTOR TRAMITE QUALUNQUE TIPO:

elenco di città (nome -> stringa)  
conservare il numero di abitanti per ogni città.

con unordered_map<strinf ,int> m;  
m[nomecitta] è il numero di abitanti  
supponiamo di voler memorizzare le distanze (in km tra coppie di città)  

### **PASSO 1**
come rappresento le amtrici (in generale anche senza hash map) ?  
vector<vector<int>> mat

mat è un vector di vector  
mat[i] è un vector  
mat[i][j] è un int   

**come creo una matrice in cui gli indici diventano (ad esempio) stringhe?**  

voglio ad esempio stampare cout<<distanze["cosenza"]["roma"]

### **USO DI TABELLA HASH PER IMPLEMENTARE MATRICI SPARSE**
n. di valori significativi molto minore rispetto alle celle totali della matrice

>Soluzione 1:

vector<list<pair<int, Tipoval>>>

>Soluzione 2:  
con Tabella Hash

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <assert.h>
using namespace std;

struct PairHash{
    int operator()(const pair<int, int> &p) {
        return p.first + 31 * p.second;
    }
};



template <class T>
class SparseMatrix{
    unordered_map<pair<int,int>> T, PairHash> m;
    int rows, cols;
public:
    SparseMatrix(int _rows, int _cols) : rows(_rows), cols(_cols){
        assert(_rows>0 & _cols>0);
    }

    int getRows(){return rows;}
    int getCols(){return cols;}

    T operator() (int r, int c){ // SOLO LETTURA
        // pair<int,int> p; p.first = r; p.second = c;
        // return m[r,c];

        //c'è un altro modo per scrivere queste cosa sopra
        assert(r>=0 && r<rows && c>=0 && c<cols);
        return m[{r,c}];
    }

    void set(int r, int c, const T& val){
        assert(r>=0 && r<rows && c>=0 && c<cols);
        if(val==T(0)) m.erase({r,c});
        else m[{r,c}] = val;
    }
};

int main(){
    SparseMatrix<int> mat(3,4);
    mat.set(0,1, 25);
    mat.set(1,1, 32);

    for(int i=0; i<mat.getRows(); ++i){
        for(int j=0; i<mat.getCols(); ++j){
            cout<<mat(i, j)<<"\t";
        cout<<endl;
        }
    }

return 0;
}

```







