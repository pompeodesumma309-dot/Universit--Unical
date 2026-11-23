#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Insieme{
    vector<T> v;

    public:
    Insieme(){}
    
    void add(const T& param);
    bool is_in(const T& param) const;
    void remove(const T& param);
    bool empty();

    void stampa() const {
        cout << "{ ";
        for (const auto& elem : v) {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }

    Insieme<T> unione(const Insieme<T>& altro) const;
    Insieme<T> intersezione(const Insieme<T>& altro) const;
    Insieme<T> differenza(const Insieme<T>& altro) const;
};

template <class T>
void Insieme<T>::add(const T& param){
    if(!is_in(param)){
        v.push_back(param);
    }
}

template <class T>
bool Insieme<T>::is_in(const T& param) const{
    for(const auto& elem : v){
        if(elem == param){
            return true;
        }
    }
    return false;
}

template <class T>
void Insieme<T>::remove(const T& param){
    for(auto i=v.begin(); i!=v.end(); ++i){
        if(param == *i){
            v.erase(i);
            break;
        }

    }
}

template <class T>
bool Insieme<T>::empty(){
    return v.empty();
}

template <class T>
Insieme<T> Insieme<T>::unione(const Insieme<T>& altro) const{
    Insieme<T> nuovoInsieme;
    for(const auto& elem : v){
        nuovoInsieme.add(elem);
    }

    for(const auto& elem2 : altro.v){
        nuovoInsieme.add(elem2);
    }

    return nuovoInsieme;

}

template <class T>
Insieme<T> Insieme<T>::intersezione(const Insieme<T>& altro)const {
    Insieme<T> nuovoInsieme;
    for(const auto& elem : v){
        if(altro.is_in(elem)){
            nuovoInsieme.add(elem);
        }
    }
    return nuovoInsieme;
}

template <class T>
Insieme<T> Insieme<T>::differenza(const Insieme<T>& altro) const{
    Insieme<T> nuovoInsieme;
    for(const auto& elem : v){
        if(!altro.is_in(elem)){
            nuovoInsieme.add(elem);
        }
    }
    return nuovoInsieme;
}


int main() {
    // Creiamo due insiemi di interi
    Insieme<int> A;
    Insieme<int> B;

    // Popoliamo l'insieme A
    A.add(1); A.add(2); A.add(3); A.add(4);
    A.add(1); // Questo è un duplicato, il tuo add dovrebbe ignorarlo!

    // Popoliamo l'insieme B
    B.add(3); B.add(4); B.add(5); B.add(6);

    // Stampiamo gli insiemi di partenza
    cout << "Insieme A: "; A.stampa();
    cout << "Insieme B: "; B.stampa();
    cout << "------------------------" << endl;

    // 1. TEST INTERSEZIONE
    Insieme<int> C = A.intersezione(B);
    cout << "Intersezione (A ∩ B): "; C.stampa();
    // Risultato atteso: { 3 4 }

    // 2. TEST UNIONE
    Insieme<int> D = A.unione(B);
    cout << "Unione (A U B): "; D.stampa();
    // Risultato atteso: { 1 2 3 4 5 6 }

    // 3. TEST DIFFERENZA (dopo che l'avrai implementata)
    Insieme<int> E = A.differenza(B);
    cout << "Differenza (A - B): "; E.stampa();
    // Risultato atteso: { 1 2 }

    // Verifichiamo che A e B NON siano stati modificati
    cout << "------------------------" << endl;
    cout << "Verifica A dopo i test: "; A.stampa();
    cout << "Verifica B dopo i test: "; B.stampa();

    return 0;
}
