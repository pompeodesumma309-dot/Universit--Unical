#include <iostream>
#include <string.h>
using namespace std;

class Esercizio{
    int id;
    char * desc;
    int diff;
public:
    Esercizio() {desc=nullptr;}
    Esercizio (int _id, char * _desc, int _diff); 
    int get_id() const {return id;}
    char * get_desc () const {return desc;} //non mi piace
    int get_diff () const {return diff;}
};

Esercizio::Esercizio(int _id, char * _desc, int _diff){
    id = _id;
    desc = new char[strlen(_desc)+1];
    strcpy(desc, _desc);
    diff = _diff;

}

class BancaDatiEsercizi{
    Esercizio elenco[1000];
    int size;
public:
    BancaDatiEsercizi(): size(0) {}
};



int main(){
    char * str = new char[100];
    cin>>str;

    Esercizio e1;
    Esercizio e2(1, str , 10);

    cout<<"L'esercizio inserito e': "<<endl;
    cout<<"Id: "<<e2.get_id()<<endl;
    cout<<"descrizione: "<<e2.get_desc()<<endl;
    cout<<"difficolta': "<<e2.get_diff()<<endl;

    BancaDatiEsercizi bd;


return 0;
}