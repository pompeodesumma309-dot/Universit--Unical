#include <iostream>
#include <string>
using namespace std;

class CartaDaGioco{
    char seme;
    char simbolo;

    public:
        int valoreCarte;
        int valoreSimbolo;
        
        CartaDaGioco(char _seme, char _simbolo) : seme(_seme), simbolo(_simbolo){
            if (seme == 'C') seme = 15;
            else if(seme == 'P') seme = 13;
            else if (seme == 'Q') seme = 12;
            else if (seme == 'F') seme = 14;

            if(simbolo == 'A') simbolo = 22;
            else if(simbolo == 'K') simbolo = 21;
            else if(simbolo =='Q') simbolo = 20;
            else if(simbolo == 'J') simbolo = 19;
        }





};