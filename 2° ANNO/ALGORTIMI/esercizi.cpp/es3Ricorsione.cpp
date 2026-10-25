#include <iostream>
using namespace std;

int somma_pesata(int* array, int size, int i){
    if (i >= size) return 0;

    return i*array[i] + somma_pesata(array,size,i+1);
}

