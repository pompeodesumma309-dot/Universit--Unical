# LEZIONE 10°

### Overloading delle operaioni
```cpp
struct Punto{
    int x;
    int y;

};

int main(){
    Punto p1,p2;

    p1 = p1 + p2; //ERRORE: non possiamo farla cosi
}
```

tipo operator simboloOperatore (parametri) //corpo della funzione
```cpp
class CVector{
public:
    int x,y;

    CVector(){}; // costruttore di default
    CVector(int a, int b): x(a), y(b){}; // costruttore

    int get_x();
    CVector operator+ (const CVector & param);
};

CVector CVector::operator+ (const CVector & param){
    CVector temp;
    temp.x = x + param.x;
    temp.y = y +param.y;
    return temp;

};

int main(){
    CVector v1(3, 4), v2(5,6), v3;
    v1.get_x();
    v3 = v1+v2; // v1.+(v2)

    cout<<"la somma di v1 e v2 e' ["<<v3.x<<","<<v3.y<<"];"<<endl;
    cout<<"v1 adesso e' ["<<v1.x<<","<<v1.y<<"];"<<endl;

```

### Versione alternativa di CVector con operatore NON funzione membro
```cpp
class CVector{
public:
    int x,y;
    CVector(){};
    CVector(int a, int b): x(a), y(b){};

    friend ostream& operator<<(ostream &, const CVector &);
    friend istream& operator>>(istream &, CVector &);

};

CVector operator+ (const CVector &lhs, const CVector &rhs){
    CVector temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;

};

//adesso il main sarà diverso rispetto a prima
int main(){
    CVector v1(3, 4), v2(5,6), v3;
    v3 = operator+ (v1,v2);
}
```

### Overloading di << e >>
```cpp
ostream& operator<<(ostream &os, const CVector &v){
    os<<"["<<v.x<<","<<v.y<<"]";
    return os;
}

istream& operator>>(istream & is, CVector & v){
    //errore:
    cout<<"Inserisci due caratteri: "<<endl;
    //errore:
    cin>>v.x>>v.y;

    is>>v.x>>v.y;
    return is;
}

int main(){
    CVector v1(3,4), v2(5,6), v3;
    v3 = v2 + v1;

    cout<<v1<<v2;
}
```

### operatore this
```cpp
class Dummy{
public:
    bool isItMe (Dummy & param);
}

bool Dummy::isItMe(Dummy & param){
    if(&param == this) return true;
    else return false;
}

int main(){
    Dummy a;
    Dummy *b = &a;
    if (a->isItMe(a)) cout<<"si"<<endl;
    else cout<<"no"<<endl;

    if (a.isItMe(*b))

}

CVector& CVector::operator= (const CVector & param){
    x = param.x;
    y = param.y;
    return *this;
}
```

### FUNZIONI MEMBRO COSTANTI
```cpp
class MyClass{
    public:
        int x;
        MyClass(int val):x(val) {};
        int get() const {return x;} //get è una funzione membro costante
        int get() {return x;}
        vois set(int a) {x=a;}
}

int main(){
    const MyClass foo(10);
    //cout<<foo.x<<endl;
    cout<<foo.get()<<endl;
    foo.set(10); //errore
    bar(8); // ok


return 0;
}

```