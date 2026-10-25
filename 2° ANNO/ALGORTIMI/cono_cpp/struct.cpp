#include <iostream>
#include <vector>
using namespace std;


struct Persona
{
    string nome;
    string cogonome;
    int eta;
};


int main(){
    Persona persona1 = {"luca", "rossi", 25};

    cout<<persona1.nome<<endl;

}