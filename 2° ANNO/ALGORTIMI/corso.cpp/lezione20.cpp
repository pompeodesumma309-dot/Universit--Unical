### ESERCIZIO: TRACCIA 27/05/2021

```cpp
int esercizio1(const Grafo& G){
    int nodomax = -1, latenzamax = -1;

    for(int i=0; i<G.n(); ++i){
        float latenza=0;
        int cont=0;

        for(int j=0; j<G.n(); ++j){
            if(i!=j && G(i,j)){

                latenza+=G.lat(j);
                cont++;
            }
        }
        if(cont!=0){

            latenza = latenza / cont; // calcolo la latenza media degli adiacenti

            if (G.lat(i) < latenza && G.lat(i) > latenzamax) { //stato di i 1
                nodomax = i;
                latenzamax = G.lat(i);
            }
        }
    }
    return nodomax;
}

```

### ESERCIZIO: SCRIVERE UNA FUNZIONE CHE PRESI IN INPUT UNA STRINGA S E UN ALBERO BINARIO DI CHAR RESTITUISCA TRUE SE E SOLO SE ESISTE UNA FOGLIA
### DELL'ALBERO TALE CHE CONCANTENANDO TUTTI I CARATTERI LUNGO IL PERCORSO RADICE-FOGLIA SI OTTENGA ESATTAMENTE S.

```cpp
bool check1 (string s, const AlberoB<char>& t, string c){
    if (t.nullo()) return false;
    c.push_back(t.radice());

    if(t.foglia()) return s==c;
    if(c.lenght() >= s.lenght()) return false;
    return (check1(s, t.figlio(SIN), c)) || check1(s, t.figlio(DES), c);
}

bool check2 (string s, const AlberoB<char>& t, int i){
    if(t.nullo()) return false;

    if(t.foglia()) return ((i==s.size()-1) && (s[i]==t.radice()));

    if(s[i] != t.radice()) return false;

    return (check2(s, t.figlio(SIN), i+1) || check2(s, t.figlio(DES), i+1));
}


bool esercizio3(const string& s, const AlberoB<char>& t){
    // Versione 1
    string c="";
    return check1(s,t,c);

    // Versione 2
    return check2(s,t,0);
}

int main(){
    AlberoB<char> A('a');

    AlberoB<char> As('b');
    A.insFiglio(SIN, As);

    AlberoB<char> Ad('c');
    A.insFiglio(DES, Ad);

    AlberoB<char> Ass('d');
    As.insFiglio(SIN,Ass);

    AlberoB<char> Asd('e');
    As.insFiglio(DES, Asd);

    AlberoB<char> Ads('f');
    Ad.insFiglio(SIN, Ads);

    AlberoB<char> Add('g');
    Ad.insFiglio(DES, add);

    string tofind;
    cin>>tofind;

    if(esercizio3 (tofind, A)) cout<<"trovata!"<<endl;
    else cout<<"non trovata"<<endl;

    return 0;
}
```

