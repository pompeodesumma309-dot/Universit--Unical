#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona{

public:
    string nome;
    string cognome;
   
    Persona(string nome, string cognome){
        this->nome = nome;
        this->cognome= cognome;
    }

    void saluta(){
        cout<<"ciao sono "<<nome<<endl;
    }  
};

class Studente: public Persona 
{
public:
    string classe;
    Studente(string nome, string cognome, string classe) : Persona(nome, cognome){
        this->classe = classe;
    }
    
};


int main(){
    Persona persona1("mario","rossi");
    Studente studente1("pompeo","desumma","5A");

    studente1.saluta();
    persona1.saluta();

    return 0;
}