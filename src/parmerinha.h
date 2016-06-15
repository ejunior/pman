#ifndef PARMERINHA
#define PARMERINHA

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "constantes.h"
#include "Personagem.h"



#define DIR_UP 0
#define DIR_RIGHT 1
#define DIR_DOWN 2
#define DIR_LEFT 3

using namespace std;

class Parmerinha : public Personagem {
private:
    int dir;
    ALLEGRO_BITMAP *sprite_parado, *sprite_right, *sprite_left, *sprite_up, *sprite_down;
    double velocidade;

public:

    Parmerinha(ALLEGRO_FONT* fnt, ALLEGRO_BITMAP* spr[]) : Personagem(fnt, spr) {
        velocidade = 0;
        fator_escala = 0.7;
        x = TELA_WIDTH / 2;
        y = TELA_HEIGHT / 2;
        dir = -1;
        velocidadeDeslocamento = VELOCIDADE_ATOR;
        
        img          = spr[0];
        sprite_up    = spr[1];
        sprite_down  = spr[2];
        sprite_right = spr[3];
        sprite_left  = spr[4];
        
        // cor do personagem 
        cor = ALCOLOR_GREEN;
    }

    void trocaDirecao(int d) {
        if (d >= 0 && d < 4)
            dir = d;
    }

    bool mover() override {
        switch (dir) {
            case DIR_UP: if (y > 0) {
                    y -= velocidadeDeslocamento;
                    img = sprite_up;
                }
                break;
            case DIR_RIGHT: if (x < TELA_WIDTH - spriteWidth()) {
                    x += velocidadeDeslocamento;
                    img = sprite_right;
                }
                break;
            case DIR_DOWN: if (y < TELA_HEIGHT - spriteHeight()) {
                    y += velocidadeDeslocamento;
                    img = sprite_down;
                }
                break;
            case DIR_LEFT: if (x > 0) {
                    x -= velocidadeDeslocamento;
                    img = sprite_left;
                }
                break;
        }
        return 1;
        //mostrar(); movido para a fase de de desenho da tela
    }

    bool colisao(Personagem *pers) {
        //cout << pers << "( "<<pers->getCentroX() << ", " << pers->getCentroY() <<")" <<endl;

        _TIPO_TELA distx = getCentroX() - pers->getCentroX();
        _TIPO_TELA disty = getCentroY() - pers->getCentroY();
        _TIPO_TELA dist = sqrt((distx * distx) + (disty * disty));

        if (dist <= (spriteRadius() + pers->spriteRadius())) {
            //cout << dist << ", " << (spriteRadius() + pers->spriteRadius()) << endl;
            return true; // colidiu       
        }
        return false;
    }

//    _TIPO_TELA getX() {
//        return x;
//    }
//
//    _TIPO_TELA getY() {
//        return y;
//    }

};

#endif // PARMERINHA
