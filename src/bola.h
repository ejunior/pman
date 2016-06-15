
#ifndef BOLA_H
#define BOLA_H

#include "constantes.h"
#include "Personagem.h"
#include "myAllegro.h"

class Bola : public Personagem {
private:

public:

    Bola(ALLEGRO_FONT* fnt, ALLEGRO_BITMAP *bmp[]):Personagem(fnt, bmp){
        cor = ALCOLOR_RED;
        fator_escala = 1;        
        // evita que a figura apareça na tela pela metade
        x = rand() % ((int) TELA_WIDTH - (int) round(spriteWidth()));
        y = rand() % ((int) TELA_HEIGHT - (int) round(spriteHeight()));        
    }

    virtual ~Bola(){}
};

#endif // BOLA_H

