# LEZIONE 12°

### LE CLASSI TEMPLATE
Ci da l'oppurtunità di far funzionare una classe con qualunque tipo.

```cpp
template <class T> 
class myPair{
    T a, b;
public:
    myPair (){};
    myPair(const T& first,const T& second): a(first), b(second){};
    const T& first(); // const T& evita di fare la copia
    T& first(); // se ci fosse questa cosa, scriviamo ...
    const T& second(); 
}

template <class T>
const T& myPair<T>::first(){return a};

template <class T>
const T& myPair<T>::second(){return b};

template <class T>
T& myPiar<T>::first(){return a};


int main(){
    myPair<int> myObject(3 ,5);
    myPair<char> o2('c', '1');
    cout<<myObject.first()<<" "<<myObject.second()<<endl;

    myObject.first()=5; // scriviamo questo
}
```

### CLASSI TEMPLATE SU PIU TIPI
```cpp
template <class T1, class T2>
class mixedPair {
    T1 a;
    T2 b;
public: 
    mixedPair(const T1& first, const T2& second):a(first), b(second){};
}



int main(){
    int x = 5;
    float y =3,7;
    mixedPair<int, float> p(x,y);
}
```

### DEFINIZIONE DI UNA CLASSE VECTOR
è un contanier di dati
```cpp
#include <assert.h>

template <class R>
class Vector{
    unsigned int sz;
    unsigned int cap;
    R * vec;
public:
// COSTRUTTORI E DISTRUTTORI
    Vector(); // costruttore di default
    Vector(const Vector<R> &); //costruttore di copia
    ~Vector();

// METODO BASE DI SUPPORTO
    unsigned int size () const; //numero di elementi significativi
    unsigned int capacity() const; // numero di celle disponibili

//OPERATORI DI ACCESSO DIRETTO
    R operator[] (unsigned int i) const; //per la lettura e per i vector costanti
    R& operator[] (unsigned int i);

//OPERATORE DI COPIA OER ASSEGNAMENTO
    Vector<R>& operator=(const Vector<R> &);

//METODI PER LA MODIFICA DEL CONTENUTO (E DIMENSIONE)
    void reserve(unsigned int size); //modifica solo la capacity
    void resize(unsigned int size); // modifica capacity e size

    void push_back(const R&); 
    const R& back(); const // solo il contenuto dell'ultimo elemento 
    void pop_back(); //cancella (senza restituire) l'ultimo elemento 

}

template <class R>
Vector<R>::Vector(){
    cap = 1;
    sz = 0;
    vec = new R[cap];
}

template <class R>
Vector<R>::Vector (const Vector<R> & v){
    sz = v.sz;
    cap = v.cap;
    vec = new R[cap];
    for (int i = 0; i<sz; ++i) {vec[i]=v.vec[i];} // copia elemento per elemento 
}

template <class R>
Vector<R>::~Vector(){delete [] vec;}

template <class R>
R& Vector<R>::operator[](unsigned int i) {
    assert((i>=0) && (i<sz));
    return vec[i];
}

template <class R>
vector<R>& Vector<R>::operator=(const Vector<R>& v){
    if (this != &v){
        sz = v.sz;
        cap = v.cap;
        delete [] vec;
        vec = new R[cap];
        for (int i=0; i<sz; i++) {vec[i] = v.vec[i];}
    }

    return *this;
}

template <class R>
void Vector<R>::reserve(unsigned int size){
    if (size<cap){
        cap = size;
        R* tmp = new R[cap];
        for (int i=0; i<sz; ++i) tmp[i] = vec[i];
        delete [] vec;
        vec = tmp;
    }
}

template <class R>
void Vector<R>::resize(unsigned int size){
    reserve(size);
    sz=size;

} // modifica capacity e size

template <class R>
void Vector<R>::push_back(const R& e){
    if(sz == cap) reserve(cap*2);
    vec[size] = e;
    sz++;

}


template <class R>
const R& Vector<R>::back() const{ // solo il contenuto dell'ultimo elemento
    assert(sz>0);
    return vec[sz-1];
}


template <class R>
void Vector<R>::pop_back(){ //cancella (senza restituire) l'ultimo elemento
    if (sz>0) sz--;
}


template <class R>
ostream& operator<<(ostream& os, const Vector<R> & v){
    for(int i=0; i<v.size(); ++i) os<<v[i]<<" ";
}


int main(){
    Vector<int> v;
    v.resize(10); // riepirò 10 celle
    for(int i = 0; i<v.size(); i++) v[i] = i;

    //svuotiamo v
    while (v.size()){
        cout<<v.back()<<" ";
        v.pop_back();
    }

    for(int i=0; i<100; ++i){
        v.push_back(i);
    }

    for (int i=0; i<v.size(); ++i) cout<<v[i]<<" ";
    cout<<v<<endl;

}

```

**SPECIALIZZAZIONE DEI TEMPLATE**
```cpp
template <>
class Vector<char> {

......

}
```