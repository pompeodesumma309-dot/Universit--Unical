#include <iostream>
using namespace std;

void inverti(int* array, int size, int i){
    //CASO BASE
    if (i==size/2) return;

    int temp = array[i];
    array[i] = array[size-1-i];
    array[size-1-i] = temp;
    return inverti(array,size,i+1);
}




int main(){
    v[]= new int[8];
}