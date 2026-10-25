#include <iostream>
using namespace std;

int main(){
    int numero;
    cout<<"Inserisci una sequenza di numeri tra 0 a 9."<<endl;
    cout<<"inserisci un numero:"<<endl;
    cin>>numero;
    
    int zero_due=0;
    int tre_sei=0;
    int maggiore_sei=0;

    while(numero>=0 && numero<=9){
        
        if(numero<3){
            zero_due+=1;
        }

        else if(numero>=3 && numero<=6){
            tre_sei+=1;
        }

        else if(numero>6){
            maggiore_sei+=1;
        }

        cout << "0-2: " << zero_due << ", 3-6: " << tre_sei << ", 7-9: " << maggiore_sei << "." << endl;

        cout<<"Inserisci numero:"<<endl;
        cin>>numero; 
    }
cout<<"il numero non rispetta il range tra 0 e 9"<<endl;
return 0;
}
