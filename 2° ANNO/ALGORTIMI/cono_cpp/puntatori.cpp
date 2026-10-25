#include <iostream>
using namespace std; 

void funzione(int *ptr_parametro){
    *ptr_parametro = 50; 
}

int main(){

    int prova = 20;
    int *ptr_prova = nullptr;
    ptr_prova = &prova;

    cout<<prova<<endl;
    cout<<ptr_prova<<endl;
    cout<<*ptr_prova<<endl;

    *ptr_prova = 200;

    cout<<prova<<endl;
    cout<<*ptr_prova<<endl;

    funzione(&prova);
    cout<<prova<<endl;

    return 0;
}