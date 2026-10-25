#include <iostream>
using namespace std;

int& comparazione(int &num1, int &num2){
    return (num1 > num2) ? num1 : num2;
}



int main(){

    int x = 5;
    int y = 50;

    int& maggiore = comparazione(x,y);
    cout<<maggiore<<endl;

    maggiore = 100;
    cout<<maggiore<<endl;

    cout<<y<<endl;

}