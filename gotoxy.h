#include<windows.h>
#include<iostream>
#include<conio.h>




#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80






void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X=x;
    dwpos.Y=y;
    SetConsoleCursorPosition(hcon,dwpos);

}

void OcultarCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize= 1;
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(hcon,&cci);


}
