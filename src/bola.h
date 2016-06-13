
#ifndef BOLA_H
#define BOLA_H

#include "constantes.h"
#include "Personagem.h"

class Bola : public Personagem {
private:
    int dura = 10;

public:

    Bola() : Personagem() {
        img = IMG_BOLA;
        cor = ALCOLOR_RED;
        dura = 10;
        velocidadeDeslocamento = VELOCIDADE_BOLA;

        // evita que a figura apareça na tela pela metade

        x = rand() % ((int) TELA_WIDTH - (int) round(spriteWidth()));
        y = rand() % ((int) TELA_HEIGHT - (int) round(spriteHeight()));
    }

    bool mover() override {
        return true;
    }

    void mostrar() override {
        Personagem::mostrar();
    }

};

#endif // BOLA_H

