#include <iostream>
#include <vector>
using namespace std;


int main(){
    int num;
    vector<int> lista_num;
    int maggiori=0;
    int minori=0;


    cout<<"inserisci quanti numeri vuoi (se inserisci di fila lo stesso numero si interromperà): "<<endl;

    while(cin>>num){
        lista_num.push_back(num);
        if(lista_num.size() >=2){
            int ultimo = lista_num[lista_num.size()-1];
            int penultimo = lista_num[lista_num.size()-2];

            if(ultimo==penultimo){
                break;
            }
            if(ultimo>penultimo){
                maggiori++;
            }
            else if(ultimo<penultimo){
                minori++;
            }
        }
        
    }
    cout<<"maggiori: "<<maggiori<<endl;
    cout<<"minori: "<<minori<<endl;


    return 0;
}