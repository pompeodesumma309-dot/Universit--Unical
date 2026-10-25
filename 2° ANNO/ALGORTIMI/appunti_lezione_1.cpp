#include <iostream>

using namespace std;

int main() {
    std::cout<< "Inserisci due numeri: " << endl;
    int v1 = 0, v2 = 0;
    
    cin >> v1 >> v2; // Aggiunto il punto e virgola
    
    // Corretta la sintassi di cout, gli operatori << e le stringhe
    std::cout<< "La somma di " << v1 << " e " << v2 << " è " << v1 + v2 << endl;
    
    return 0;
}


    \\commenta una sola riga
    /*....*/commneto in un itero spazio di codice 


    int i1; // case sensitive
    int I1; // questa è un altra variabile 
    bool b=false; // oppure true
    int a={0} //list initialization 
    int a{0}; //list initialization
    int a(0) // object initialization

    long double ld=3.3432
    int d=ld // d asssume il valore 3
    bool b=42;  // b assume il valore TRUE; 0 è falso tutti gli altri True
    
    // VISIBILITà DELLE VARIABILI SCOPE:
// variabili globali
int reused =42;
int main(){
    int z;
}
int f(){
    // qui z non è visibile
    // qui vedo reused
}

// ==========================

#include <iostream>
using namespace std;

int reused=42;
int main(){
    int unique=0;
    cout<<reused<<" "<<unique<<endl; //42 0
    reused=0;
    cout<<reused<<" "<<unique<<endl; //0 0
    reused=42;  //riporta la var globale a 42
    int reused=0;
    cout<<::reused<<" "<<reused<<endl; // 42 0
}

// VARIABILI CONST
const int j=42;
// Caratteri speciali 
\n //(nuova linea)

cout<<"Ciao \n"; //equivalnete a: 
cout<<"Ciao "<<endl;

//IL TIPO SPECIALE AUTO 
auto i=0; 
auto item=val1+val2;

//OPERATORI E TIPO DI DATO
//Esempi: + - / *, ma anche ++ e --
int i=0, j=1;
i=j+1; i=i+1;
++i; i++;

int a;
a=++i; // prima elabora e poi assegna
a=i++; // prima valuta e poi incrementa; a vale 6 ma i vale 7
cout<<i<<endl; //stampo il valore attuali di i e poi incremento 

//OPERATORI BOOLEANI
// Confronto ==
if (a==b)...

if(a=b)... // NO: è un assegnamento

AND: & oppure &&
if(b1==0 & b2<b3 & c>0)... // valuta tutta l'espressione
if(b1==0 && b2<b3 && c>0)... //

//OR: | oppure ||

// NOT: !
//DIVERSO: !=

//TIPI COMPOSTI
// - Riferimentiù
// - Puntatori
//RIFERIMENTI:
int ival=1024;
int &refval=ival;
int &refval2; //errore
refval=2;
cout<<ival<<endl; //stampa 2
int ii=refval;// ii assume il valore 2

//PUNTATORI:
int *ip1, *ip2;

int ival=42;
ip1= &ival;
cout<<ival<<" "<<*ip1









