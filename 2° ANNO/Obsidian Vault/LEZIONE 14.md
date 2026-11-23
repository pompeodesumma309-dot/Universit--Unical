**Idea base del polimorfismo**
```cpp
Polugon* p = new Rectangle(4,5);
cout<< p -> area();
```
Qui p è un **puntatore a Polygon**, ma punta ad un oggetto Rectangle. Se area() è **VIRTUAL**, la chiamata p->area() eseguirà **Rectangle::area()**, non **Polygon::area()**. Questo è il cuore del polimorfismo.

Le condizione perchè funzioni sono:
- c'è ereditarietà: **Rectangle** deriva da **Polygon**;
- la chiami tramite puntatore o riferimento alla classe base.

### TIPO STATICO O DINAMICO
```cpp
Polygon* p = new Rectangle(4,5); 
```
- **Tipo statico** di p: Polygon*. è quello che il compilatore vede guardando la dichiarazione.
- **Tipo dinamico** dell'oggetto puntato: Rectangle. è quello che esiste davvero in memoria a runtime.

Se la funzione è **non virtual**, il compilatore sceglie la funzione in base al tipo di dato statico, quindI chiamerebbe Polygon::area().

Se la funzione **è virtual**, il compilatore genera una chiamata che a runtime guarda il tipo dinamico e chiama Rectangle::area().
