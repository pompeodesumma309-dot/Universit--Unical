#include <iostream>
#include <vector>
using namespace std;

int main(){
    string colonne = "ABCDEFG";
    int righe=10;

    for(int i=0; i<20; i++){
        if(i%2!=0){
            continue;
        }
        cout<<i<<endl;
    }


    return 0;
}