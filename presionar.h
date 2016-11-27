#include<list>
#include "ast.h"
#include<vector>


using namespace std;

void presionar(){
    bool game_over=false;



    vector<int> v;

    AST asteroide(10,4),asteroide1(16,15),asteroide2(20,20);
    NAVE elemento(30,30);
    BALA bala(elemento.getx()+2,elemento.gety()-1);
    elemento.crear();
    elemento.pintar();
    int a=1;
    list<BALA*>B;
    list<BALA*>::iterator it;
    list<AST*>ast;
    list<AST*>::iterator AIT;
    for(int i=0;i<5;i++){
        ast.push_back(new AST(rand()%71+4,rand()%5 + 5));

    }
    while(!game_over){
        if(kbhit()){
            char a = getch();
            if(a=='v'){
                B.push_back(new BALA(elemento.getx()+2,elemento.gety()-1));
            }
        }
        for(it=B.begin();it!=B.end();it++){
            (*it)->mover();
            if((*it)->fuera()){
                delete (*it);
                it = B.erase(it);
            }
        }
        if(elemento.getvidas()==0){
            if(kbhit()){
                                                gotoxy(100,100);

                printf("Desea continuar?");
                char c ;
                scanf("%c",&c);
                printf("                   ");
                if(c != 'r'){
                    elemento.alterarvidas(3);
                    elemento.alterarcorazones(3);
                    gotoxy(30,30);
                    printf("           ");
                    v.push_back(elemento.puntuacion1());
                    elemento.modificar();

                }
                else{
                    int n = v.size();
                    for(int i = 0 ; i < n ; i++){
                        cout<<"Partida "<<i+1<<" tiene puntuacion: "<<v[i]<<endl;

                    }
                                printf("GAME OVER!");
                                gotoxy(30,30);

                    game_over = true;

                }
            }
        }
        elemento.mover();
        elemento.resetear();
        for(AIT = ast.begin();AIT!=ast.end();AIT++){
            (*AIT)->mover();
            (*AIT)->choque(elemento);
        }
        for(AIT = ast.begin();AIT!=ast.end();AIT++){
            for(it = B.begin(); it != B.end(); it++){
                if((*AIT)->getx()==(*it)->getx() && ((*AIT)->gety()==(*it)->gety() || (*it)->gety()-1 == (*AIT)->gety())){
                    gotoxy((*AIT)->getx(),(*AIT)->gety());
                    printf(" ");
                    gotoxy((*it)->getx(),(*it)->gety());
                    printf(" ");
                    delete(*it);
                    it = B.erase(it);
                    (*AIT)->X(rand()% 71 +4) ;
                    (*AIT)->Y(4);
                    elemento.insertpuntuacion(a);
                    a*=2;
                }
            }

        }
        Sleep(30);
    }
}
