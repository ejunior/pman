#ifndef TROFEU_H
#define TROFEU_H


#include "Personagem.h"
#include "constantes.h"

//#include <iostream>
#include <stdio.h>

#include <cstdlib>

class Trofeu : public Personagem {
private:

public:

    Trofeu(ALLEGRO_FONT* fnt, ALLEGRO_BITMAP **bmp):Personagem(fnt, bmp){
        fator_escala = 0.3;
        velocidadeDeslocamento = VELOCIDADE_TROFEU;
        // y deve variar entre (0) e (resolução Horizontal  - altura da figura)
        // para que a figura sempre apareça na tela inteira;
        y = std::rand() % (TELA_HEIGHT - (int) round(spriteHeight()));
        x = 0;
       
    }

    virtual ~Trofeu() {
    };

    bool mover() override {
        x += velocidadeDeslocamento;
        if (x >= TELA_WIDTH - spriteWidth() || y >= TELA_HEIGHT) {
            return false;
        }
        return true;
    }
};

#endif // TROFEU_H

