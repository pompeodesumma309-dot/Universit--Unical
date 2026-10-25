# LEZIONE 14°

**POLIMORSFIRMO**  
sfrutta la proprietà in cui un puntatore di una classe (base o derivate) può puntare anche in oggetti della classe derivata.

```cpp
class Polygon{
    int width, height;
protected:
    void set_values(int a, int b){width=a; height= b;}
    virtual int area() {return 0;}
}

class Rectangle: public Polygon{ // possiamo averla di 3 tipi
public:
    int area(){return width*height;}
}

class Triangle: public Polygon{
public:
    int area(){return width*height/2;}

}

int main(){
    Rectangle r;
    Triangle t;
    Polygon p;

    Polygon p; 
    Polygon * ppoly3=&p;

    Polygon * ppoly1 = &r; // puntatore1
    Polygon * ppoly2 = &t; // puntatore2

    ppoly1 -> set_values(4,5);
    //ppoly1 ->area(); // NON LA VEDE (senza virtual area)   

    ppoly2 -> set_values(4, 5);
    //ppoly2 -> area(); // NON LA VEDE

    cout<<r.area()<<endl;
    cout<<t.area()<<endl;

    cout<<ppoly1->area()<<endl; // se ho virtual area()

    cout<<ppoly3->area()<<endl; // stampa 0
}
```
>**Versione alternativa 1**

```cpp
class Polygon{
    int width, height;
protected:
    void set_values(int a, int b){width=a; height= b;}
    virtual int area() = 0; //VIRTUALE PURA --> CLASSE ASTRATTA
}

class Rectangle: public Polygon{ // possiamo averla di 3 tipi
public:
    int area(){return width*height;}
}

class Triangle: public Polygon{
public:
    int area(){return width*height/2;}


int main(){
    Polygon p; // non posso più definire oggetti di tipo Polygon, perchyè Polygon è astratta!!

    Polygon * pp1 = new Polygon(); // ERRORE NON POSSIAMO

    Polygon * pp1 = new Rectangle; // questo possiamo farlo

    Rectangle r;
    Polygon * pp2 = &r;

    cout<<ppoly1->area()<<endl; // stampa 20

    delete pp1;
    pp1 = new Triangle(4,5);

    cout<<ppoly1->area()<<endl; // stampa 10
}
```

>**VERSIONE alternativa 2**
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Polygon{

protected: // per farle vedere a Rectangle e Triangle
    void set_values(int a, int b){width=a; height= b;}
    virtual int area() {return this-> area();}
}

class Rectangle: public Polygon{ // possiamo averla di 3 tipi
public:
    int area(){return width*height;}
}

class Triangle: public Polygon{
public:
    int area(){return width*height/2;}


int main(){
    Rectangle r(4,5);
    Triangle t(4,5);

    Polygon * pp1 = &r;
    Polygon * pp2 = &t;

    cout<<pp1->area()<<endl; // stampa 20
    cout<<pp2->area()<<endl; // stampa 10
}
```
>**VERSIONE alternativa 3**
```cpp
class Polygon{

protected: // per farle vedere a Rectangle e Triangle
    void set_values(int a, int b){width=a; height= b;}
    virtual int area()=0;
    void print_area(){return this -> area();}
}


int main(){
    vector<Polygon *> v;

    int a,b;
    char c;

    for(int i=0; i<10; ++i){
        cout<<"inserisci base e altezza:"<<endl;
        cin>>b>>a;
        
        cout<<"vuoi inserire un traingolo ('t') o un rettangolo (r) ?: "<<endl;
        cin>>c;

        if(c=='t') tmp=new Triangle(b,a);

        else if (c=='r') tmp=new Rectangle(b,a);
        v.push_back(tmp);
    }

    for (int i=0; i<v.size(); ++i){
        cout<<v[i]->print_area()<<endl;
    }
}
```

**EREDITARIETA' MULTIPLA**
```cpp
class Output{
    public:
    void print(int i){cout<<i<<endl;};
};

class OutputTab{
    public:
    void print(int i){cout<<i<<"\t";}
}

class Rectangle: public Polygon, public Output{ // eredità la proprietà di entrambe le classi
    public:
    ------- // esattamente come prima
}

class Triangle: public Polygon, public OutputTab{
    ............
} 

int main(){
    Rectangle r(4,5);
    r.print(r.area()); // stampa 20 e va a capo

    Triangle t(4,5);
    t.print(t.area()); // stampa 10 e metto un tab

return 0;
}
```