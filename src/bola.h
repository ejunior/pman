
#ifndef BOLA_H
#define BOLA_H

#include "constantes.h"
#include "Personagem.h"
#include "myAllegro.h"

class Bola : public Personagem {
private:

public:

    Bola(ALLEGRO_FONT* fnt, ALLEGRO_BITMAP *bmp[], auto scr_h, auto scr_w):Personagem(fnt, bmp, x, y){
        cor = ALCOLOR_RED;
        fator_escala = 1;        
        // evita que a figura apareça na tela pela metade
        this->x = x;
        this->y = y;
        x = rand() % ((int) scr_h - (int) round(spriteWidth()));
        y = rand() % ((int) scr_w - (int) round(spriteHeight()));        
    }

    virtual ~Bola(){}
};

#endif // BOLA_H

