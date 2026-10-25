#include <iostream>
using namespace std;

//ESERCIZIO: trovare il massimo ed il submasssimo tra 10 numeri positivi letti da intput
int main(){
    float numero;
    float num_massimo = -1;
    float secondo_max = -1;
    cout<<"Inserisci 10 numeri:"<<endl;
    for(int i=0; i<10;i++){
        cin>>numero;

        if(numero>num_massimo){
            secondo_max=num_massimo;
            num_massimo=numero;
            
        }  
            
        else if(numero>secondo_max){
            secondo_max=numero;        

        }
        
    }

    cout<<"il numero massimo e': "<<num_massimo<<endl;

    if (secondo_max!=-1){
        cout<<"il secondo numero massimo e': "<<secondo_max<<endl;
    }else {cout<<"il secondo massimo non e' disponibile"<<endl;
    
    }
     
    
    
return 0;
}
