#include <iostream>
#include <string>

using namespace std;

int main(){
    int  voti_storia[2] = {10,20};

    for(int i=0; i<sizeof(voti_storia) / sizeof(int) ; ++i){
        cout<<voti_storia[i]<<" ";
    }
    cout<<endl;
    cout<<sizeof(voti_storia)<<endl;






    /*for (int i=0; i<5; ++i){
        cout<<"inserisci il voto: "<<endl;
        cin>>voti_storia[i];

    }

    for(int i=0; i<5; ++i){
        cout<<voti_storia[i]<<" ";
    }
    */


    return 0; 
}