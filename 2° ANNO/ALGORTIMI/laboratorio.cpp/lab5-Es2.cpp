#include <iostream>
#include <vector>
using namespace std;

class Programmatore{
    unsigned int id;
    unsigned int eta;
    unsigned int stipendio;
    unsigned int anni_esperienza;
    bool senior;

    public:
    Programmatore(){}
    Programmatore(unsigned int _id, unsigned int _eta, unsigned int _stipendio, unsigned int _anni_esperienza, bool _senior) : id(_id), eta(_eta), stipendio(_stipendio), anni_esperienza(_anni_esperienza), senior(_senior){};

    unsigned int get_id() const{
        return id;
    }

    unsigned int get_eta() const{
        return eta;
    }
    
    unsigned int get_stipendio() const{
        return stipendio;
    }

    unsigned int get_anni_esperienza() const{
        return anni_esperienza;
    }

    bool get_senior() const{
        return senior;
    }

    void set_id(unsigned int _id){
        id=_id;
    }

    void set_eta(unsigned int _eta){
        eta = _eta;
    }

    void set_stipendio(unsigned int _stipendio){
        stipendio = _stipendio;
    }

    void set_anni_esperienza(unsigned int _anni_esperienza){
        anni_esperienza = _anni_esperienza;
    }

    void set_senior(bool _senior){
        senior = _senior;
    }

    friend ostream& operator<<(ostream& is, const Programmatore& param);
    friend istream& operator>>(istream& out, Programmatore& param);
    bool operator==(const Programmatore& altro) const ;
    bool operator!= (const Programmatore& altro) const ;
};

ostream& operator<<(ostream& is, const Programmatore& param){
    is <<"Id dell'utente e': "<<param.id<<endl;
    is <<"L'eta' dell'utente e' di: "<<param.eta<<endl;
    is <<"Lo stipendio dell'utente e' di: "<<param.stipendio<<endl;
    is <<"L'utente e' senior: "<< (param.senior == true ? "SI" : "NO");

    return is;
}

istream& operator>>(istream& out, Programmatore& param){
    out>>param.id >> param.eta >> param.stipendio >> param.anni_esperienza >> param.senior;
    return out;
}

bool Programmatore::operator== (const Programmatore& altro) const{
    return id == altro.get_id();
}

bool Programmatore::operator!=(const Programmatore& altro) const {
    return id != altro.get_id();
}

class GestoreProgrammatori{
    vector<Programmatore> lista_programmatori;

    public:
    GestoreProgrammatori(){}
    GestoreProgrammatori( vector<Programmatore> _lista_programmatori) : lista_programmatori(_lista_programmatori){}

    void assumi_programmatore(const Programmatore& param);
    void licenzia_programmatore(const Programmatore& param);
    unsigned int max_stip_cat (bool is_senior);
    Programmatore senior_meno_esperto();
    void promuovi_a_senior();


};

void GestoreProgrammatori::assumi_programmatore(const Programmatore& param){
    bool duplicato = false;
    for(int i=0; i<lista_programmatori.size(); ++i){
        if(param == lista_programmatori[i]){
            duplicato = true;
            break;
        }
    }

    if(duplicato == false){
        lista_programmatori.push_back(param);
    }else{cout<<"Programmatore già esistente."<<endl;}
    
}

void GestoreProgrammatori::licenzia_programmatore(const Programmatore& param){
    for(int i=0; i<lista_programmatori.size(); ++i){
        if (param == lista_programmatori[i]){
            lista_programmatori.erase(lista_programmatori.begin() + 1);
            i--;
            cout<<"Programmatore licenziato!"<<endl;

        }
    }
    cout<<"Programmatore non trovato"<<endl;
}

unsigned int GestoreProgrammatori::max_stip_cat (bool is_senior){
    unsigned int max_stipendio = 0;

    for(int i=0; i< lista_programmatori.size(); ++i){
        
        if(lista_programmatori[i].get_senior() == is_senior && max_stipendio < lista_programmatori[i].get_stipendio()){
            max_stipendio = lista_programmatori[i].get_stipendio();
        }
        
    }
    return max_stipendio;   

}

Programmatore GestoreProgrammatori::senior_meno_esperto(){

    Programmatore risulato;
    unsigned int senior_meno_esperto = 10000;

    for(int i=0; i<lista_programmatori.size(); ++i){
        if(lista_programmatori[i].get_senior() == true && senior_meno_esperto > lista_programmatori[i].get_anni_esperienza()){

            senior_meno_esperto = lista_programmatori[i].get_anni_esperienza();
            risulato = lista_programmatori[i];
        }
    }

    if(senior_meno_esperto == 10000){
        cout<<"Non ci sono senior."<<endl;
    }

    return risulato;
}


void GestoreProgrammatori::promuovi_a_senior(){
    bool esiste_senior = false;
    for(int j=0; j<lista_programmatori.size(); ++j){
        if(lista_programmatori[j].get_senior() == true){
            esiste_senior = true;
            break;
        }
    }

    if(esiste_senior == false){
        cout<<"Nessun senior presente. Promozione annulata."<<endl;
        return;
    }

    Programmatore utente = senior_meno_esperto();
    unsigned int anni_minimi = utente.get_anni_esperienza();

    for (int i=0; i<lista_programmatori.size(); ++i){
        if(lista_programmatori[i].get_senior() == false && lista_programmatori[i].get_anni_esperienza() > anni_minimi){
            lista_programmatori[i].set_senior(true);
        }
    }


}

