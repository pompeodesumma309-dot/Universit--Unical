#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class PratoFiorito{
    vector<pair<unsigned int, unsigned int>> v;
    unsigned int dimensione;
    unsigned int* mat;

    public:
    PratoFiorito(vector<unsigned int> _v, unsigned int _dimensione) : v(_v), dimensione(_dimensione){

        mat = new unsigned int [dimensione * dimensione];

        unsigned int coordinate;

        for(int i=0; i<v.size(); ++i){
            int coordinate = v[i];  
        }

        for (int r = 0; r<dimensione; ++r){
            for (int c = 0; c<dimensione; ++c){
                mat[r][c] = coordinate;


            }
        }



    }



};