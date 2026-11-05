#include <iostream>
using namespace std;


int massimiAdiacenti(int** m, int n, int i , int j){

    bool trovato = false;
    int maxAdiacente = 0;

    for(int r=i-1; r<=i+1; ++r){
        for(int c=j-1; c<= j+1; ++c){
            if (r>=0 && r<n && c>=0 && c<n && (r!= i || c!=j)){

                if( !trovato || m[r][c] > maxAdiacente){
                    maxAdiacente = m[r][c];
                    trovato = true;
                }

            
            }
        }
    
    }
    
    return maxAdiacente;
}

void popolaMatrice(int** m, int** Q, int n){
    for(int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            Q[i][j] = massimiAdiacenti(m, n, i, j);
        }
    }


}

int** creaMatrice(int n){
    int** mat = new int*[n];
    for (int i=0; i<n; ++i){
        mat[i] = new int[n];
    }
    return mat;
}

void distruggiMatrice(int** mat, int n){
    for(int i=0;i<n;++i){
        delete [] mat[i];
    }
    delete [] mat;
}

void stampaMatrice(int **mat, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int dimensione;

    cout<<"Dimmi di quanto vuoi che sia la grandezza della matrice: "<<endl;
    cin>>dimensione;

    int** m = creaMatrice(dimensione);
    int** Q = creaMatrice(dimensione);

    cout<<"Inserisci i numeri all'interno della matrice: "<<endl;

    for(int i=0; i<dimensione; ++i){
        for(int j=0; j<dimensione; ++j){
            cin>>m[i][j];
        }
    }

    popolaMatrice(m, Q, dimensione);

    cout<<"Matrice di Partenza: "<<endl;
    stampaMatrice(m, dimensione);

    cout<<"Matrice finale: "<<endl;
    stampaMatrice(Q, dimensione);

    distruggiMatrice(m, dimensione);
    distruggiMatrice(Q, dimensione);

    return 0;
}
