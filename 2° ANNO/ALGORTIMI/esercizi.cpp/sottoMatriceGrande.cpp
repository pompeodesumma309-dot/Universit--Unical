#include <iostream>
using namespace std;

/*
struct DimVal{
    int dim;
    int val;

};
*/

// 1. capire se della cella i,j può "partire " un quadrata di dimensione k
bool parte_quadrato(int n, int i, int j, int k){
    return i + k <= n && j+k <= n;
}
// 2. dato un quadrato di dimensione k che parte da i,j, controllo che tutti i numeri siano uguali
bool tutti_uguali(int** m, int n, int i, int j, int k){
    int primo= m[i][j];
    for (unsigned r = i; r< i+k; r++){
        for(unsigned c= j; c<j+k; c++){
            if (m[r][c] != primo) return false;
        }
    }
    return true;
}
// 3. la funzione ricorsiva che mi cerca quadrati sempre piu piccoli
int cerca_quadrato(int** m, int n, int k){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(parte_quadrato(n, i, j, k)){
                if (tutti_uguali(m, n, i, j, k)){
                    return k;
                }
            }
        }
    }


    return cerca_quadrato(m, n, k-1);    
}
// 4. lettura dell'input
void lettura(int** m){
    int n;
    cout<<"quante righe/colonne vuoi per questa matrice quadrata? "<<endl;
    cin>>n;

    m = new int* [n];

    for (unsigned i=0; i<n; i++){
        m[i] = new int [n];
    }

    for (unsigned i=0; i<n; i++) {
        for (unsigned j=0; j<n; ++j) {
            cout<<"inserisci l'elemento (i,j)";
            cin>>m[i][j];
        }
    }

}
// 5. liberare memoria
void libera(int** m, int n) {
    for (unsigned i=0; i<n;i++) {
        delete [] m[i];
    }
    delete [] m;
}

int main(){

    cerca_quadrato(m, n, k);






    
    return 0;
}