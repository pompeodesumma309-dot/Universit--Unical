#include <iostream>
#include <string>
#include <vector>
using namespace std;



void prova(vector<int> vettore){
    for(int i=0; i<vettore.size(); i++){
        cout<<vettore[i]<<" ";
    }
}

int main(){

    vector<int> numeri = {10,20,30,40};
    prova(numeri);

    return 0;
}