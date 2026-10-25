#include <iostream>
#include <string>

using namespace std;

int main(){

    string celle[2][4] = {
        {"A1", "B1", "C1","D1"},
        {"A2", "B2", "C2","D2"}
    };

    for(int i=0; i<2;i++){
        for(int j=0; j<4; j++){
            cout<<celle[i][j]<<endl;
        }
    }

    return 0;
}