#include <iostream>
using namespace std;

class Studente{
    unsigned matricola;
    unsigned int* voti;
    unsigned int* cfu;

    public:
        Studente(unsigned _matricola, unsigned int* _cfu) : matricola(_matricola){
            cfu = new unsigned int[15];
            voti = new unsigned int [15];

            for (int i=0; i<15; ++i){

                cfu[i] = _cfu[i];
                voti[i]=0;
            }   
        }

    unsigned get_matricola () const{
        return matricola;
    }

    bool inserisciEsame(unsigned i, unsigned voto);
    bool laureato() const;
    int cfu_conseguiti() const;

    float get_media_voti() const;

    friend ostream& operator<< (ostream& os, const Studente& s);
    bool operator== (const Studente& s)const;
    Studente& operator= (const Studente& s) ;
    
    Studente(const Studente& s);
    ~Studente();


};

bool Studente::inserisciEsame(unsigned i, unsigned voto) {
    if(voto>=18 && voto<=30 && i<15){
        voti[i] = voto;        
        return true;
    }

    else if(voto==33 && i<15){
        voti[i] = voto;
        return true;
    }

    else{return false;}

}

bool Studente::laureato() const{
    for(int i=0; i<15; ++i){
        if(voti[i]<18){
            return false;
        }
    }
    return true;
}

int Studente::cfu_conseguiti() const{
    int cfu_accumolati=0;
    for (int i=0; i<15; i++){
        if(voti[i] >= 18){
            cfu_accumolati+=cfu[i];
        }
        
    }
    return cfu_accumolati;
}

float Studente::get_media_voti() const{
    float somma=0;
    float tot_cfu = cfu_conseguiti();

    if(tot_cfu ==0) return 0;

    for(int i=0; i<15; i++){
        if(voti[i] >=18){

            somma += voti[i]*cfu[i];

        }
    }
    float media_ponderata = somma / tot_cfu;
    return media_ponderata;
}

ostream& operator<<(ostream& os, const Studente& s){
    os <<s.matricola<<" "<< s.cfu_conseguiti()<< " "<<s.get_media_voti();
    return os;
}

bool Studente::operator== (const Studente& s) const{
    if(matricola == s.matricola){
        return true;
    }
    else{return false;}
}

Studente& Studente::operator=(const Studente& s){

    matricola = s.matricola;

    voti = new unsigned int [15];
    cfu = new unsigned int [15];

    for(int i=0; i<15; i++){
        voti[i] = s.voti[i];
        cfu[i] =s.cfu[i];
    }

    return *this;

}

Studente::Studente(const Studente& s){

    voti = new unsigned int [15];
    cfu = new unsigned int[15];

    matricola = s.matricola;

    for (int i=0; i<15; i++){
        voti[i] = s.voti[i];
        cfu[i] = s.cfu[i];
    }
}

Studente::~Studente(){
    delete [] voti;
    delete [] cfu;
}

int main(){

    unsigned int cfu_piano[15] = {6, 6, 9, 9, 12, 6, 6, 6, 9, 6, 9, 12, 6, 6, 6};
    Studente s1(1001, cfu_piano);

    cout << "Studente appena creato (s1): " << s1 << endl;

    s1.inserisciEsame(0, 28);
    s1.inserisciEsame(1, 30);

    cout << "Dopo gli esami: " << s1 << endl;
    cout<< "CFU effettivi: "<< s1.cfu_conseguiti()<<endl;
    cout<<"Media ponderata: "<< s1.get_media_voti()<<endl;

    cout<<"E' laureato ? "<< s1.laureato()<<endl;

    Studente s2(2000, cfu_piano);
    Studente s3(2001, cfu_piano);

    cout<<"Hanno la stessa matricola? "<<s2.operator==(s3)<<endl;

    Studente s4(5000, cfu_piano);
    for(int i=0; i<15; i++){
        s4.inserisciEsame(i, 28);
    }

    cout<<"E' laureato? "<<s4.laureato()<<endl;

    cout<<"Hanno diversa matricola? "<<!(s3 == s2);

    
    return 0;
}
