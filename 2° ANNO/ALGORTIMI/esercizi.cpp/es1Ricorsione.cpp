#include <iostream>
using namespace std;

int potenza(int n1, int n2){

    if (n2==1){
        return n1;
    }
    else if (n2==0){
        return 0;
    }

    return n1*potenza(n1, n2-1);

}


int main(){
    int num1=3;
    int num2=2;
    cout<<potenza(num1,num2)<<endl;

    return 0;
}