void alloca_memoria(int **mat, int n){
    mat=new int*[n];
    for (unsigned i=0; i<n;i++){
        mat[i]=new int [n];
    }
}

void leggi_da_input(int**mat,int n){
    for (unsigned i=0; i<n;i++){
        for (unsigned j=0; j<n;++j){
            cin>> mat[i][j];
        }
    }
}

void dealloca_memoria(int**mat,int n) {
    for (int i=0; i<n; i++){
        delete []mat[i];
    }
    delete []mat;
}

bool indice_valido(unsigned riga, unsigned colonna, int n) {
    return riga>=0 && colonna>=0 && riga<n && colonna<n;
}


int massimo_adiacente (p,n,i,j) {
    int max=;
    bool max_init=false;
    for (unsigned r=i-1; r<=i+1;r++){
        for (unsigned c=j-1; c<=j+1;c++) {
            if (indice_valido(r,c,n) && !(r==i && c==j)){
                if (!max_init || p[r][c]>max) {max=p[r][c]; max_init=true;}
            }
        }
    }
}


void calcola_massimi_adiacenti(int**p, int**q, int n){
    for (unsigned i=0; i<n;i++){
        for (unsigned j=0; j<n;++j){
            q[i][j]=massimo_adiacente(p,n,i,j);
        }
    }
}



int main() {
    int n;
    cout<<"inserisci n:";
    cin>>n;

    int **p;
    int **q;
    alloca_memoria(p,n);
    alloca_memoria(q,n);

    leggi_da_input(p,n);
    calcola_massimi_adiacenti(p,q,n);
    dealloca_memoria(p,n);
    dealloca_memoria(q,n);
    
    return 0;
}