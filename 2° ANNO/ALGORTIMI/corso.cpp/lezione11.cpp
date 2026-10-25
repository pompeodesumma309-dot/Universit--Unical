# Lezione 11° 


```cpp
class MyClass{
    public:
        int x;
        MyClass(int val):x(val) {};
        int get() const {return x;} //get è una funzione membro costante

        int& get() {return x;}
};

void f(const MyClass & c){
    cout<<c.get();

}

int main(){
    MyClass foo(10);
    foo.get () = 15;
    f(foo);

    cout<<foo.get()<<endl;

return 0;
}
```

**Versioni possibili della get**
```cpp
int get() const {return x;} //funzione membro costante 

const int & get() {return x;} //funzione membro che ritorna un const &

const int & get() const {return x;} //funzione membro costante che ritorna un const &

int & get() {return x;} //funzione membro che ritorna un riferimento 
```

**Membro speciali**
- Costruttore di default
- Asssegnamento per copia (operatore =)
- Distruttore 
- Costruttore per copia

Esempio:
```cpp
class Example{
    int * ptr;
    int dim;
public:
    Example(int n){
        ptr = new int [n];
        dim = n;
    }

    Example (const Example & x){
        dim = x.dim;
        ptr = new int [dim];
        for (int i=0; i<dim; ++i){ // copia profonda
            ptr[i] = x.ptr[i];
        }
    }

    Example& operator= (const Example & x){
        dim = x.dim;
        ptr = new int [dim];

        for (int i =0; i<dim; ++i){
            ptr[i] = x.ptr[i];
        }
        return *this;
    }

    ~Example(){ //distruttore
        delete [] ptr;
        delete dim; // non necessario (e sbagliata)
    }
}

void f(){
    Example foo(10);
    Example bar = foo; //differenza con Example bar(?);

}
```

IL DITRUTTORE VIENE CHIAMATO QUANDO LA VARIABILE CESSA IL SUO CICLO DI VITA.
ESEMPI:
- Variabile locale di una funzione al termine della funzione in seguito ad una delete
- Variabile locale 