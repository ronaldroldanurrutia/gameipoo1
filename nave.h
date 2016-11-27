#include "bala.h"
#include<stdlib.h>
#include<stdio.h>



class NAVE{
    private:
        int x;
        int y;
        int corazones;
        int vidas;
        int puntuacion;

    public:
        NAVE(int _x=10,int _y=10){
            this->x=_x;
            this->y=_y;
            this->corazones=3;
            this->vidas=3;
            this->puntuacion=0;
        }
        void crear();
        void mover();
        void limpiar();
        void pintar();
        void PintarCorazones();
        void resetear();
        void imprimirpuntuacion();
        int getx(){
            return this->x;
        }
        int gety(){
            return this->y;
        }
        void alterar(){
            this->corazones--;
        }
        int getvidas(){
            return this->vidas;
        }
        void alterarvidas(int n){
            this->vidas=n;
        }
        void alterarcorazones(int n){
            this->corazones=n;
        }
        void insertpuntuacion(int a){
            this->puntuacion+=(30*a);
        }
        int puntuacion1(void){
            return this->puntuacion;

        }
        void modificar(void);
        void mostrarvidas();
};


void NAVE::modificar(){
    this->puntuacion = 0;
    return ;

}


void NAVE::crear(){
    gotoxy(x,y);printf("  %c",30);
    gotoxy(x,y+1);printf(" %c%c%c",40,207,41);
    gotoxy(x,y+2);printf("%c%c %c%c",30,190,190,30);

}

void NAVE::imprimirpuntuacion(){
    gotoxy(1,2);
    printf("PUNTUACION %d",this->puntuacion);

}

void NAVE::PintarCorazones(){
    gotoxy(64,2);printf("SALUD");
    gotoxy(70,2);printf("   ");
    for(int i=0;i<corazones;i++){
        gotoxy(70+i,2);printf("%c",3);
    }

}

void NAVE::mostrarvidas(){
    gotoxy(20,2);printf("VIDAS %d",this->vidas);

}

void NAVE::pintar(){
    for(int i=2;i<78;i++){
        gotoxy(i,3);printf("%c",205);
        gotoxy(i,33);printf("%c",205);

    }
    for(int i=4;i<33;i++){
        gotoxy(2,i);printf("%c",186);
        gotoxy(77,i);printf("%c",186);

    }
    gotoxy(2,3);printf("%c",201);
    gotoxy(2,33);printf("%c",200);
    gotoxy(77,3);printf("%c",187);
    gotoxy(77,33);printf("%c",188);


}

void NAVE::limpiar(){
    gotoxy(x,y);printf("     ");
    gotoxy(x,y+1);printf("     ");
    gotoxy(x,y+2);printf("     ");

}

void NAVE::resetear(){
    if(this->corazones==0){
        limpiar();
        gotoxy(x,y);printf("  *   ");
        gotoxy(x,y+1);printf(" ***  ");
        gotoxy(x,y+2);printf("  ***");
        Sleep(200);
        limpiar();
        this->corazones=3;
        this->vidas--;
        PintarCorazones();
        crear();

    }

}

void NAVE::mover(){
    imprimirpuntuacion();
    mostrarvidas();
    PintarCorazones();
    if(kbhit()){
            char tecla = getch();
            gotoxy(x,y);
            limpiar();
            if(tecla==IZQUIERDA && x>3)x--;
            if(tecla==ARRIBA && y>4)y--;
            if(tecla==DERECHA && x+6<77)x++;
            if(tecla==ABAJO && y+3<33)y++;
            crear();
            PintarCorazones();

    }


}
