#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int numero;
    cout<<"Inserisi un numero:"<<endl;
    cin>>numero;
    
    bool isPrime=true;

    if (numero<=1){
        return false;
    }
    for(int i; i<=sqrt(numero); i++){
        if(numero%i){
            isPrime=false;
        }
    }
    if (isPrime==true){
        cout<<"Il numero e' primo."<<endl;
    } else {cout<<"il numero non e' primo:"<<endl;}


}
