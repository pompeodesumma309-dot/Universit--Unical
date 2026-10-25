#include <iostream>
using namespace std;

// VEDERE SE UN NUMERO E' DIVISIBILE PER 3 (PASSAGGIO PER VALORE)
/*bool isMultiploDiTre(int n){
    if(n%3==0){
        return true;
    } else{return false;}
}

int main(){
    int numero;
    cout<<"Inserisci un numero per vedere se e' multiplo di 3: "<<endl;
    cin>>numero;
    if (isMultiploDiTre(numero)){
        cout<<numero<<" e' divisibile per 3."<<endl;
    }else{cout<<numero<<" non e' divisibile per 3"<<endl;}

return 0;
}*/

/*
void scambia(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int main(){
    int x=5;
    int y=10;
    scambia(x,y);

    cout << "x vale: " << x << endl; // Stampa 10
    cout << "y vale: " << y << endl;

return 0;
}*/

/*
struct Astronave{
    int scudi;
    int carburante;
    int missili;
};

bool puoAttacare(const Astronave &nave){
    if(nave.carburante>=10 && nave.missili>=1){
        return true;
    }
    return false;
}

int main(){
    Astronave miaNave;
    miaNave.carburante=100;
    miaNave.scudi=130;
    miaNave.missili=20;

    if(puoAttacare(miaNave)){
        cout<<"Fuoco"<<endl;
    }else{cout<<"risorse insufficienti"<<endl;}

    return 0;
}*/

void raddoppia(int *ptr){
    *ptr= *ptr * 2;

}
 int main(){
    int punti;
    punti=50;

    raddoppia(&punti);
    cout<<punti<<endl;

    return 0;
 }