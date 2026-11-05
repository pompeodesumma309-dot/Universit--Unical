#include <iostream>
#include <string>
using namespace std;

class CartaDaGioco{
    char seme;
    char simbolo;

    public:

        CartaDaGioco(char _seme, char _simbolo) : seme(_seme), simbolo(_simbolo){}

        int valoreSeme () const;  
        int valoreSimbolo () const;

        char get_Seme()const{
            return seme;
        }

        char get_Simbolo () const{
            return simbolo;
        }

        bool operator<(const CartaDaGioco& parametro) const;

        friend ostream& operator<<(ostream& os, const CartaDaGioco& carta);
        friend istream& operator>>(istream& is, CartaDaGioco& carta);

};

int CartaDaGioco::valoreSeme () const {
    switch (seme)
    {
        case 'C': return 20;
        case 'F': return 19;
        case 'P': return 18;
        case 'Q': return 17;
                            
        default:
            return 0;
    }
}

int CartaDaGioco::valoreSimbolo () const{
    switch (simbolo)
    {
        case 'A': return 16;
        case 'K': return 15;
        case 'Q': return 14;
        case 'J': return 13;
        case '1': return 10;
    
        default:
            return simbolo - '0';
    }
}

bool CartaDaGioco::operator<(const CartaDaGioco& parametro) const{
    if( valoreSimbolo() == parametro.valoreSimbolo()){
        return valoreSeme() < parametro.valoreSeme();
    }
    else{return valoreSimbolo() < parametro.valoreSimbolo();}
}

ostream& operator<<(ostream& os, const CartaDaGioco& carta){
    return os << carta.simbolo<<" "<< carta.seme;
}

istream& operator>>(istream& is, CartaDaGioco& carta){

    return is>>carta.simbolo>>carta.seme;
}






