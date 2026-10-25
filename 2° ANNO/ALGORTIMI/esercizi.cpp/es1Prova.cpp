#include <iostream>
using namespace std;

int* bellissima_funzione(){
    int* p = new int[6];
    return p;
}

int main(){
    int *r = bellissima_funzione();
    return 0;
}
// TROVA L'ERRORE: è sbagliato perche manca l'indirizzo in memoria --> MEMORY LEAK

int main(){
    int* data_di_nascita = new int[8]{3,1,1,2,1,9,9,9};
    cout<<*(data_di_nascita + 3) + 1 <<endl; // vado al numero 2 e sommo 1 (3)
    cout<<data_di_nascita[2]<<endl; // stampa il secondo 1
    cout<<data_di_nascita<<endl; // stampa l'indirizzo di memoria della prima cella
    cout<<*(data_di_nascita + 2)<<*(data_di_nascita + 3)<<endl;
    // Che cosa manca?

    delete[] data_di_nascita;
    // new e delete devono essere sempre bilanciati
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int v[]= {2,7,5,4,2,8};
    int *p1, *p2, a, b;
    a = v[0]; b = v[1];
    p1= &a; p2 = &b;
    p1 = p2;
    *p2= v[2];
    a = v[3];

    //CHE COSA STAMPA LA SEGUENTE ISTRUZIONE?
    cout<<*p1<< *p2<< a << b<<endl; //5,5,4,5
}


//2. DALA LA SEGUENTE ISTRUZIONE, indicare qual è il modo corretto (A, B, C o D) di ge
#include <iostream>
using namespace std;

int* q1 = new int(20);
//2A:
delete q1[0];
//2B: non c'è biso gno di alcuna delete
//2C:
for(int i=0; i<20; ++i) {delete [] q1[i]}
delete q1;
//2D:
delete q1;



//esercizio
int *ptr = &v[0];
int *qtr = &v[3];

//3. cosa stampa la seguente istruzione
cout<<qtr - ptr<<endl; // stampa i valori da ptr a qtr

// 4. cosa stampa la seguente istruzione?
int &f = v[2];
f = 7;
for(int i=0; i<5; ++i){
    cout<<*(v+1);

}
cout<<endl;
