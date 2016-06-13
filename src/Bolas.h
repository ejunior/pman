
#ifndef BOLAS_H
#define BOLAS_H

#include "constantes.h"

class Bola : public Personagem {
private:
    _TIPO_TELA ponto, dura;    

public:

    Bola() : Personagem() {
        img = NULL; // IMG_BOLA;
        ponto = 1;
        dura = 10;
        velocidadeDeslocamento = 0;
        x = rand() % 795;
        y = rand() % 595;
    }

    bool mover() {
        mostrar();
        return false;
    }

    _TIPO_TELA getCentroX() {
        return (img)? x + al_get_bitmap_width(img):0;
    }

    _TIPO_TELA getCentroY() {
        return (img)?y + al_get_bitmap_height(img):0;
    }

    _TIPO_TELA getLargura() {
        return (img)? al_get_bitmap_width(img):0;
    }
};

#endif	// BOLAS_H

