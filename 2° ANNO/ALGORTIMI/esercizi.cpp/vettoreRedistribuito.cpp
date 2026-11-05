#include <iostream>
#include <vector>
#include <string>
using namespace std;

class vettoreRestribuito : public vector<unsigned> {
    private:
        int acc;

    public:

    vettoreRestribuito() : vector<unsigned>(), acc(32){}

    void inserisci(unsigned num);
};

void vettoreRestribuito::inserisci(unsigned num){
    if(num % 2 == 0 && num > 0){
        while(num % 2 == 0){
            unsigned temp;

            num/=2;
            temp = num;
            acc+=num;
        }
    }

    else if (num % 2 !=0 && acc>=2) {
        acc-=2;
        vector<unsigned>::push_back(num + 2);
    }

    else{

    }
}






//def del prof
class vettoreRedistribuito : protected vector<unsigned> {
    private:
        unsigned acc;

        unsigned dividi_progressivamente(unsigned x){
            unsigned x_iniziale = x;
            while (x%2==0){
                x/=2;
            }
            return x;
        }

    public:

        vettoreRedistribuito() : acc(32) {}

        void push_back(unsigned x){
            if (x>0 && x%2==0){

                unsigned y = dividi_progressivamente(x);
                vector<unsigned>::push_back(y);
                acc+=(x-y);
            }

            else if (x>0 && x%2 != 0){
                if(acc>=2){
                    acc-=2;
                    x+=2;
                    vector<unsigned>::push_back(x);
                }
            }

            else{
                vector<unsigned>::push_back(acc);
                acc = 0;
            }
        }

        unsigned ritrova(unsigned i){
            if (i < vector<unsigned>::size()){

                unsigned tmp = vector<unsigned>::at(i);
                vector<unsigned>::at(i) = tmp;
                acc = tmp;
            }

            return acc;
        }

        unsigned size() const{
            return vector<unsigned>::size();
        }

        unsigned get_acc() const{
            return acc;
        }
};


//ESERCIZIO 2
#IFNDEF PERSONA_H_
#DEFINE PERSONA_H_

#include <iostream>
#include <string>
using namespace std;

class Persona {

    protected:
        string cf;

    public:

        Persona(const string& _cf) {
            cf = _cf;
        }

        string get_cf() const {
            return cf;
        }

        bool operator==(const Persona& altra) const{
            return this->cf == altra.cf;
        }

        virtual float quantopagoamensa() const{
            return 7.0;
        }

        friend ostream& operator<<(ostream& out, const Persona& p){
            out<<p.cf<<" ";
            return  out;
        }
};

#ENDIF

class studente : public Persona{
    protected:
        unsigned fascia_red;
        unsigned anno_iscrizione;

    public:
        studente(const string& _cf, int _fascia_red, int _anno_iscrizione)
            : Persona(_cf), fascia_red(_fascia_red), anno_iscrizione(_anno_iscrizione){}


        int get_fascia_red() const {
            return fascia_red;
        }

        int get_anno_iscrizione() const{
            return anno_iscrizione;
        }

        bool is_fuori_corso() const {
            return anno_iscrizione == 4;
        }

        float quantopagoamensa () const{
            if (anno_iscrizione ==4 ) return 6.0;
            return 1.5 * fascia_red;
        }

        
};

class docente : public Persona{
    protected:
        string settore;
        unsigned anni_servizio;

    public:
        docente(const string& _cf, const string& _settore, int _anni_servizio)
            : Persona(_cf), settore(_settore), anni_servizio(_anni_servizio){}

    string get_settore() const{
        return settore;
    }

    int get_anni_servizio() const{
        return anni_servizio;
    }

    float quantopagoamensa () const override{
        if (anni_servizio < 10) return 6.0;
        if (anni_servizio <20 ) return 5.0;
        if(anni_servizio < 30) return 4.0;
        return 1.5;
        }

};

class CassaDellaMensa{
    private:
        double incasso;

    public:
        float get_incasso() const{
            return incasso;
        }
        
        void paga(Persona* p){
            float paga = p->quantopagoamensa();
            cout<< *(p) <<" paga "<<paga<<" per mangiare a mensa."<<endl;
            incasso += p-> quantopagoamensa();
        }
};


