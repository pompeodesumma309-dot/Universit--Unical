#include <iostream>
#include <vector>
using namespace std;

class CVector{
public:
    int x,y;

    CVector(){}; // costruttore di default
    CVector(int a, int b): x(a), y(b){}; // costruttore

    int get_x();
    CVector operator+ (const CVector & param);
};

CVector CVector::operator+ (const CVector & param){
    CVector temp;
    temp.x = x + param.x;
    temp.y = y +param.y;
    return temp;

}

int main(){
    CVector v1(4, 4), v2(6,6), v3;
    //v1.get_x();
    v3 = v1+v2; // v1.+(v2)

    cout<<"la somma di v1 e v2 e' ["<<v3.x<<","<<v3.y<<"];"<<endl;
    cout<<"v1 adesso e' ["<<v1.x<<","<<v1.y<<"];"<<endl;

    return 0;
}