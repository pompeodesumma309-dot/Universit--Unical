#include <iostream>
using namespace std;

class MyClass{
    public:
        int x;
        MyClass(int val):x(val) {}; // costruttore: inizializza x con il valore 'val'
        
        int get() const {return x;} //get è una funzione membro costante

        int& get() {return x;}
};

void f(const MyClass & c){
    cout<<c.get();

}

int main(){
    MyClass foo(10);
    const MyClass fido(35);

    foo.get () = 15;
    f(foo);
    f(fido);

    cout<<foo.get()<<endl;
    cout<<fido.get()<<endl;

return 0;
}