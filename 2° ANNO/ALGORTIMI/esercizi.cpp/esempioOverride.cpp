#include <iostream>
#include <string>
using namespace std;

class X{
    public:
        virtual void funzione() const {
            cout<<"Sono un metodo virutale della classe X."<<endl;
        }
};

class Y : public X {
    public:
        void funzione() const override{
            cout<<"sono un metodo della classe Y."<<endl;
        }
};

int main(){
    X* x = new Y ();
    x->funzione();
    delete x;
    return 0;
}