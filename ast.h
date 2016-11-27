#include "nave.h"


class AST{
    private:
        int x;
        int y;
    public:
        AST(int _x=10,int _y=4){
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
        void pintar();
        void mover();
        void choque(class NAVE &elemento);

};

void AST::pintar(){
    gotoxy(x,y);printf("%c",205);


}

void AST::mover(){
    gotoxy(x,y);printf(" ");
    y++;
    if(y>32){
        x = rand()%71+4;
        y = 4;

    }
    pintar();

}

void AST::choque(class NAVE &elemento){
        if(x>=elemento.getx() && x<(elemento.getx()+5) && y>=elemento.gety() && y<=(elemento.gety()+2)){
            elemento.alterar();
            elemento.limpiar();
            elemento.crear();
            elemento.PintarCorazones();
            x = rand()%71+4;
            y = 4;
        }

}
