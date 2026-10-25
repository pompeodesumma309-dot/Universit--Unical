# LEZIONE 13°
**STL (Standard Template Library)**
cplusplus.com (riferimento)
- pair
- vector
- sting
- algorithm

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> vint(6,0);
    int temp = vint.size();
    for(int j=0; j<temp); ++j){
        //vint.push_back(j);
        v[j]=j;
    }

    for (auto i=vint.begin(); i!=vint.end();++i){
        cout<<*i<<endl;
    }

return 0;
}
``` 

```cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> vector_of_strings;
    string s;

    cout << "Enter the string to be sorted:\n";

    while (getline(cin, s) && s != "end")
        vector_of_strings.push_back(s);

    sort(vector_of_strings.begin(), vector_of_strings.end());

    vector<string>::iterator pos = unique(vector_of_strings.begin(), vector_of_strings.end());

    vector_of_strings.erase(pos, vector_of_strings.end());

    copy(vector_of_strings.begin(),
         vector_of_strings.end(),
         ostream_iterator<string>(cout, "\t"));

    cout << '\n';

    return 0;
}
``` 

**EREDETARIETA'**
``` cpp
class nome_classe_derivata: /*specificatore di accesso*/classe_padre{
    //corpo della classe
}

class Polygon{
    int width, height;
protected:
    void set_values(int a, int b){width=a; height= b;}
}

class Rectangle: public/protected/private Polygon{ // possiamo averla di 3 tipi
public:
    int area(){return width*height;}

}

``` 
>**specificatore di accesso**: specifica il livello massimo di visibilità degli elementi ereditati dal padre  
> **privato**: visibile solo alla classe a cui appartengono.  
**protected**: visibile alla classe a cui appartengono ed alle classe derivanti  
**public**:

```cpp
class Triangle: public Polygon{
public:
    int area(){return width*height/2;}

}

int main(){
    Rectangle r;
    Triangle t;
    Polygon p;
    p.set_values(4,5); //ok, p.area() NO
    r.set_values(4, 5); //posso farlo solo perchè rectangle è derivante
    //pubblica di Polygon, altrimenti diventa inaccessibile
    
    t.set_values(4,5);
    cout<<r.area()<<endl;
}
```

__Cosa viene ereditato dalla classe base__:  
Tutto eccetto:
1. i suoi costruttori e distruttori
2. i suoi membri dell'operatore = 
3. i suoi amici
4. i suoi membri privati

Esempio di derivazione protetta:

definire una classe sorted_vector
(GARANTIRE che gli elementi somo sempre ordinati)
(SEMPLIFICHIAMO SOLO SU INT)

```cpp
class sorted_vector: protected vector<int> {
    vector<int> v; //SBAGLIATA
public:
    void insert(int);
    int operator[] (int) const; // come accedo all' i-esimo elemento
}

``` 

```cpp
class Mother{
    public:
    Mother(){cout<<"Mother: no parameters"<<endl;}
    Mother(int a){cout<<"Mother: 1 parameters"<<endl;}
}

class Daughter: public Mother{
    public:
    Daughter(int a) {cout<<"Daughter: one parameter"<<endl;}
}

class Son: public Mother{
    public:
    Son(int a){cout<<"Son: one parameters"<<endl;}
}

int main(){
    Daughter kelly(0);
    Son bud(0);

return 0;
}