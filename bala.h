#include "gotoxy.h"
#include<stdio.h>




class BALA{
    private:
            int x;
            int y;
    public:
        BALA(int _x,int _y){
            this->x=_x;
            this->y=_y;
        }
        int getx(){
            return x;
        }
        int gety(){
            return y;
        }
        void X(int _x){
            this->x=_x;
        }
        void Y(int _y){
            this->y = _y;
        }
        void mover();
        bool fuera();

};

void BALA::mover(){
    gotoxy(x,y);
    printf(" ");
    if(y>4){


    this->y--;
    gotoxy(x,y);
    printf("*");

    }
}

bool BALA::fuera(){
    if(y==4){
        gotoxy(x,y);
        printf(" ");
        return true;
    }
    return false;

}
