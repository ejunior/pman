
#ifndef BOLAS_H
#define BOLAS_H

#include "constantes.h"
#include "Personagem.h"

class Bola : public Personagem {
private:
    _TIPO_TELA ponto, dura;    

public:

    Bola() : Personagem() {
        img = nullptr; // IMG_BOLA;
        x =rand() % TELA_WIDTH - spriteWidth();
        y =rand() % TELA_HEIGHT - spriteHeight();
    }
    ~Bola(){}
   
};

#endif	// BOLAS_H

