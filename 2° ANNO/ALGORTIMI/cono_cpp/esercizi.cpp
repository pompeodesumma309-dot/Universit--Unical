#include <iostream>
using namespace std;

int main(){
    int array[5] = {1,2,50,3,5};
    
    int lunghezza= sizeof(array) / sizeof(int);
    double somma=0;
    for (int i=0; i<lunghezza; i++){
        somma+=array[i];
    
    }

    double media = somma / lunghezza;
    cout<<"la media dei valori dentro questo array e': "<<media<<endl;
       
}