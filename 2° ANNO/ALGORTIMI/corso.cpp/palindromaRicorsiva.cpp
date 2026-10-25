#include <iostream>
using namespace std;

bool palindroma(char * parola, int inizio, int fine){
    if (inizio>=fine) return true;

    return parola[inizio]==parola[fine] && palindroma(parola, inizio+1,fine-1);

    //else return palindroma(parola, inizio+1,fine-1);
}

int main(){
    char * frase = new char[100];
    cout<<"inserisci una parola lunga al massimo 100 caratteri: "<<endl;
    cin>>frase;
    cout<<frase;

    bool risultato = palindroma(frase, 0 , strlen(frase)-1);


}