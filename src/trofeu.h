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

    Trofeu(auto* fnt, auto **bmp, auto scr_h):Personagem(fnt, bmp, 0, y){
        fator_escala = 0.3;
        x = 0;
        y = std::rand() % (scr_h - (int) round(spriteHeight()));
        
        velocidadeDeslocamento = VELOCIDADE_TROFEU;
        // y deve variar entre (0) e (resolução Horizontal  - altura da figura)
        
        // para que a figura sempre apareça na tela inteira;
        //y = std::rand() % (TELA_HEIGHT - (int) round(spriteHeight()));
       
    }

    virtual ~Trofeu() {
    };

    bool mover(auto screen_width, auto screen_height) override {
        x += velocidadeDeslocamento;
        
        if (x >= screen_width - spriteWidth() || y >= screen_height) {
            return false;
        }
        return true;
    }
};

#endif // TROFEU_H

