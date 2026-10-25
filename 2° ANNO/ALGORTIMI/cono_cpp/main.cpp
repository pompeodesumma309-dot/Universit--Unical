#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int num, max, min;
    cout<<"Inserisci un numero:"<<endl;
    cin>>num;

    max=num;
    min=num;
    while(num!=0){
        cout<<"inserisci un numero:"<<endl;
        cin>>num;
        if(num==0){
            break;
        }
        if(num>max){
            max=num;
        }
        if(num<min){
            min=num;
        }
    }
    cout<<"la differenza tra max e min e': "<<(max-min)<<endl;

return 0;

}
 