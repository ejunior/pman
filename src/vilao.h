// evite isso, variáveis em escopo global, quase nunca é necessário, eu, por exemplo, nunca vi ser necessário.
//bool achou = false;

#ifndef VILAO_H
#define VILAO_H

#include "Personagem.h"
#include "constantes.h"

class Vilao : public Personagem {
private:
    ALLEGRO_BITMAP *img;
    int validade, dano, num;

public:

    Vilao() : Personagem() {
        num = 1 + std::rand() % 4;
        switch (num) {
            case 1:
                img = IMG_INIMIGO_1;
                break;

            case 2:
                img = IMG_INIMIGO_2;
                break;

            case 3:
                img = IMG_INIMIGO_3;
                break;

            case 4:
                img = IMG_INIMIGO_4;
                break;
        }
        x = rand() % (TELA_WIDTH - (int) round(spriteWidth()));
        y = rand() % (TELA_HEIGHT - (int) round(spriteHeight()));
        validade = 25;
        dano = -1;
        velocidadeDeslocamento = 0.01;
    }

    bool mover() {
        mostar();
        return false;
    }

    void mostar() {
        al_draw_bitmap(img, x, y, 0);
    }

    double getCentroX() {
        return x + al_get_bitmap_width(img) / 2;
    }

    double getCentroY() {
        return y + al_get_bitmap_height(img) / 2;
    }

    bool seguir(Parmerinha *parm) {
        if (achou) {
            if (parm->getPX() > x)
                x += 1.0;
            if (parm->getPX() < x)
                x -= 1.0;
            if (parm->getPX() == x)
                achou = false;
        } else {
            if (parm->getPY() > y)
                y += 1.0;
            if (parm->getPY() < y)
                y -= 1.0;
            if (parm->getPY() == y)
                achou = true;
        }

    }
};

#endif