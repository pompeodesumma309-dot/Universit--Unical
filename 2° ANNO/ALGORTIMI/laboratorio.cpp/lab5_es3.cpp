#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class PratoFiorito{
    vector<pair< int,  int>> v;
    int dimensione;
    vector<vector< int>> mat;

    public:
    PratoFiorito(vector<pair< int,  int>> _v,  int _dimensione) : v(_v), dimensione(_dimensione), mat(_dimensione, vector<int>(_dimensione, 0)){
        
        int valore_bomba = 9;

        for( int i=0; i<v.size(); ++i){

            if( v[i].first > v.size() || v[i].second > v.size()){
                cout<<"Coordinate sbagliate!!"<<endl;
                break;
            }
            else{mat[v[i].first][v[i].second] = valore_bomba;}

        }

        for ( int r = 0; r<dimensione; ++r){
            for ( int c = 0; c<dimensione; ++c){
                if (mat[r][c] == valore_bomba){
                    continue;
                }
                else{
                    mat[r][c] = visitiamoAdiacenti(r,c);                    
                }


            }
        }
    }

    int visitiamoAdiacenti( int r,  int c);
    void gioca();



};

int PratoFiorito::visitiamoAdiacenti( int r,  int c){
    int bombe=0;
    for(int dr = -1; dr <= 1; ++dr){
        for(int dc = -1; dc <= 1; ++dc){

            int nr = r + dr;
            int nc = c + dc;

            if (dr == 0 && dc == 0) continue;

            if(nr >= 0 && nc>=0 && nr <= dimensione-1 && nc<=dimensione-1){
                if(mat[nr][nc] == 9){
                    bombe++;
                }
            }

        }
        
    }
    return bombe;

}

void PratoFiorito::gioca(){
    // 1. Inizializziamo la matrice delle celle scoperte (tutte false all'inizio)
    vector<vector<bool>> scoperto(dimensione, vector<bool>(dimensione, false));
        
    bool partita_in_corso = true;
    int celle_scoperte = 0;
    // Calcoliamo quante celle sicure ci sono in totale
    int celle_sicure_totali = (dimensione * dimensione) - v.size(); 

    cout << "Benvenuto a Prato Fiorito! (" << dimensione << "x" << dimensione << ")" << endl;
    cout << "Ci sono " << v.size() << " bombe nascoste." << endl;

    while(partita_in_corso){
            
        // --- FASE 1: STAMPA DEL TABELLONE ---
        cout << "\n   ";
        for(int i=0; i<dimensione; ++i) cout << i << " "; // Stampa indici colonne per aiutare il giocatore
        cout << "\n";

        for (int r=0; r<dimensione; ++r ){
            cout << r << "  "; // Stampa indice riga
            for(int c=0; c<dimensione; ++c){
                if (scoperto[r][c] == false){
                    cout << "# ";
                } else {
                    cout << mat[r][c] << " ";
                    }
                }
                cout << endl;
        }

        // --- FASE 2: INPUT DEL GIOCATORE ---
        int riga_scelta, colonna_scelta;
        cout << "\nInserisci riga e colonna (es. 1 2): ";
        cin >> riga_scelta >> colonna_scelta;

        // Controllo di sicurezza: le coordinate sono dentro la matrice?
        if (riga_scelta < 0 || riga_scelta >= dimensione || colonna_scelta < 0 || colonna_scelta >= dimensione) {
            cout << "Coordinate fuori dal tabellone! Riprova.\n";
            continue; // Salta il resto del turno e ricomincia il while
        }

            // --- FASE 3: LOGICA DELLA MOSSA ---
            if (scoperto[riga_scelta][colonna_scelta] == true) {
                cout << "Hai gia' scoperto questa cella! Scegline un'altra.\n";
                continue;
            }

            if (mat[riga_scelta][colonna_scelta] == 9) {
                // BOOM! Hai preso una bomba
                scoperto[riga_scelta][colonna_scelta] = true; // Riveliamo la bomba
                cout << "\nBOOM! Hai pestato una bomba. Hai perso!\n";
                
                // Mostriamo tutto il tabellone svelato
                for(int r=0; r<dimensione; ++r) {
                    for(int c=0; c<dimensione; ++c) {
                        if(mat[r][c] == 9) cout << "9 ";
                        else cout << mat[r][c] << " ";
                    }
                    cout << endl;
                }
                partita_in_corso = false;
                
            } else {
                // Cella sicura
                scoperto[riga_scelta][colonna_scelta] = true;
                celle_scoperte++;
                cout << "Cella sicura! Ci sono " << mat[riga_scelta][colonna_scelta] << " bombe adiacenti.\n";

                // Controllo di vittoria
                if (celle_scoperte == celle_sicure_totali) {
                    cout << "\nCOMPLIMENTI! Hai scoperto tutte le celle sicure. HAI VINTO!\n";
                    partita_in_corso = false;
                }
            }
        }
    }

int main() {
    // Creiamo un tabellone 5x5 con 3 bombe sparse
    vector<pair<int, int>> bombe;
    bombe.push_back({0, 0});
    bombe.push_back({2, 3});
    bombe.push_back({4, 4});

    // Istanziamo il gioco passando le bombe e la dimensione
    PratoFiorito gioco(bombe, 5);

    // Avviamo la partita!
    gioco.gioca();

    return 0;