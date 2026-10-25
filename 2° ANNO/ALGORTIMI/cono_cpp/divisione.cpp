#include <iostream>
using namespace std;

int divisione(int num){
    int resto=0;
    while(num!=0){
        if(num%2!=0){
            resto+=1;
        }
        num=num/2;
    }
    return resto;
}

int main(){
    int numero;
    cout<<"inserisci un numero: "<<endl;
    cin>>numero;

    cout<<"la dvivsione ha dato come resto:"<<divisione(numero)<<endl;

return 0;
}

//CASO RICORSIVO
unsigned div(unsigned numero){
    if(numero==0) return 0;

    unsigned resto = numero%2;
    numero/=2;
    return resto + div(numero);
}


