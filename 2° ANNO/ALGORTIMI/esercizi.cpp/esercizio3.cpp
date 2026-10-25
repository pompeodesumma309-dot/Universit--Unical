#include <iostream>
#include <vector>
using namespace std;


/*int main(){
    int n;
    char c;
    string frase_finale="";

    cout<<"inserisci il numero di caratteri che vuoi avere: "<<endl;
    cin>>n;

    cout<<"inserisci un carattere di controllo: "<<endl;
    cin>>c;

    vector<char> carattere(n);

    for(int i=0; i<n; i++){
        cout<<"Inserisci carattere: "<<endl;
        cin>>carattere[i];
    }

    for(int i=0; i<carattere.size(); i++){
        if(c==carattere[i]){
            frase_finale+=c;
        }
    }

    if(frase_finale==""){
        cout<<carattere[0]<<carattere[carattere.size()-1]<<endl;
    }else{cout<<frase_finale<<endl;}

 
    return 0;
}*/

void elaberaSquenza(){
    int n;
    char c;

    cin>>n;
    cin>>c;

    if(n<=0){
        return;
    }

    vector<char> caratteri(n);

    int conteggio=0;
    for(int i=0;i<n;i++){
        cin>>caratteri[i];
        if(caratteri[i]==c){
            conteggio++;
        }
    }

    if(conteggio>0){
        for(int i=0;i<conteggio;i++){
            cout<<c;
        }
    }else{cout<<caratteri[0]<<caratteri[n-1]<<endl;}
    
}

int main(){
    elaberaSquenza();
    return 0;
}