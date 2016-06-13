
#include "constantes.h"

class Bola : public Personagem {
private:
    _TIPO_TELA ponto, dura;
    ALLEGRO_BITMAP *img;

public:

    Bola() : Personagem() {
        img = al_load_bitmap("bola.png");
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

    void mostrar() {
        al_draw_bitmap(img, x, y, 0);
    }

    _TIPO_TELA getCentroX() {
        return x + al_get_bitmap_width(img);
    }

    _TIPO_TELA getCentroY() {
        return y + al_get_bitmap_height(img);
    }

    _TIPO_TELA getLargura() {
        return al_get_bitmap_width(img);
    }
};
