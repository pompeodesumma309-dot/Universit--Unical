# LEZIONE 9
### LA CLASSI
PAROLE CHIAVI
- astrazione
- information hiding
- encapsulation 
- gerarchia

```cpp
class class_name{
    access_specifier1: members1;
    access_specifier2: members2;

};
```
**Specificatori di accesso:**  
public (visibili dall'esterno della class)    
protected( visibili dalla classse e dalle sue classi derivate)  
private (default) (visibili solo all'interno della classe)    

Membri: proprietà (dati) e metodi (funzioni)

```cpp
class Rectangle{
    int width, height; // sono privati poichè non c'è scritto nulla sopra

    public:
        Rectangle (); // costruttore di default
        Rectangle(int _width, int _height); 

        void set_width(int);   //setters (scrivere)
        void set_height(int); // serve per SCRIVERE/modificare height

        int get_width();    // getters (leggere)
        int get_height(); // serve per leggere height

        int area(){return width*height;} //inline function
};

Rectangle::Rectangle(){
    width = 1; height = 1;
}

Rectangle::Rectangle(int _width, int _height){ // COSTRUTTORE
    width = _width;
    height = _height;
}

void Rectangle::set_width(int _width){
    width = _width; // width a sinistra è quella iniziale della classe Rectangle  
}int Rectangle::get_width(){return width};



void Rectangle::set_height(int _height){
    height = _height;
}int Rectangle::get_height (){return height};


int main(){
    Rectangle r1, r2; 

    r1.set_width(5);
    r1.set_height(4);
    r2.set_width(10);

    cout<<" dati di r1 "<<r1.get_height()<<" "<<r1.get_width()<<endl;

    cout<<"L'area di r1 e': "<<r1.area()<<endl;
    cout<<"L'area di r2 e': "<<r2.area()<<endl; // indefinito, probabilemnte 0

    r1.height = 15;
}
```

**Costruttore:** metodo "speciale" richiamato in automatico durante la costruzione dell'oggetto (e mai altrove). 
**Ha come nome il nome della classe**.

```cpp
int main(){
    Rectangle r3(3, 4);
    Rectangle r4(5,6);
    Rectangle r5; // sbagliato (al momento)
                  // corretto se costruisco costruttore di default

    Rectangle r6 = (6,7); // sbagliato
}
```
**OVERLOADING DEI COSTRUTTORI**:
Più costruttori, con parametri diversi che si comportano in modo diverso

**passi di generazione di un oggetto**:  
**1.** Generazione dello spazio e PREINIZIALIZZAZIONE  
**2.** chiamata del costruttore adatto  
**3.** esecuzione del corpo del costruttore

```cpp
Rectangle(int _width, int _height): width(_width), height(_height)  // stiamo dicendo con i ":" che vogliamo avere il controllo della preinizializzazione

{ // rimane vuoto in questo caso
}
```

### PROGETTIAMO IL TIPO CILINDRO

```cpp
class Circle{
    double radius; // privato di default

public: 
    Circle(double r):radius(r){} // costruttore più veloce ed elegante; e essendo che non ha il costrutto vuoto il cerchio non può nascere se non diciamo subito quanto vale il suo raggio
    double area(){return radius*radius*3.14;}
};

class Cylinder{ // funzione privata
    Circle base; // è un oggetto di tipo Circle
    double height;
public:
    Cylinder(double r, double h): base(r), height(h) // o qui, inizializzazione in fase di creazione
    {
        height = h; // oppure qui, semplice assegnamento dopo la creazione
    }

    double volume (){return base.area()*height;}
};

int main(){
    Cylinder foo(10,20); // crea uno spazio in memoria
    cout<<"il volume di foo e' "<<foo.volume()<<endl;

}
```

### PUNTATORI E CLASSI
```cpp
class Rectangle{
    int width, height;

public:
    Rectangle(int x, int y):width(x), height(y){ }
    int area() {return width*height;}
};

int main(){
    Rectangle obj(3,4);
    Rectangle * foo, * bar, * baz;

    foo = &obj;

    bar = new Rectangle(5,6);
    baz = new Rectangle[2] {{2,5}, {3,6}};

    cout<<"Area di obj "<< obj.area()<<endl;

    cout<<"area di foo "<<(*foo).area()<<endl;
    cout<<"area di foo "<<foo->area()<<endl;

    cout<<"Area di bar "<< (*bar).area()<<endl;

    cout<<"Area di baz[0] "<< baz[0].area()<<endl;
    cout<<"Area di baz[1] "<< baz[1].area()<<endl;

    delete bar;
    delete [] baz;
    return 0;
}


```