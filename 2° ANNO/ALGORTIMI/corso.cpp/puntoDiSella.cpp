#include <iostream>
#include <vector>
using namespace std;


const int N = 5;

bool esistePuntoDiSella(int M[][N], int N){
    bool trovato=false;

    for (int i =0; i<N && !trovato; i++){
        for(int j=0; i<N && !trovato; i++){
            if(puntoDiSella(M,i,j,N)) trovato = true;
        }
    }
    return trovato;
}

bool puntoDiSella(int M[][N], int r, int c, int N){
    int min, max;
    min = M[r][0];
    max = M[0][c];

    for(int i=1; i<N; i++){
        if(M[i][c]<max) max = M[i][c];
    }

    for(int i = 1; i<N; i++){
        if(M[r][i]<min) min = M[r][i];
    }

    return M[r][c] == min;
}


int main(){



    return 0;
}