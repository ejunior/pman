#ifndef PERSONAGEM_H
#define PERSONAGEM_H

/*
 * Por convenção todos os arquios que contém classes devem ter o nome da classe principal contida nele
 * Personagem.hh e Personagem.cc devem conter a classe Personagem; 
 */

#include "constantes.h"
#include <string> //strlen()
#include <allegro5/allegro_primitives.h> //drawing circles
#include <algorithm> // max()
#include <allegro5/allegro_font.h>

class Personagem {
protected:
    float fator_escala;
    _TIPO_TELA x, y;
    double velocidadeDeslocamento;
    ALLEGRO_BITMAP *img;
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_COLOR cor;


public:

    Personagem() {
        cor = ALCOLOR_WHITE;
        fonte = FONTE_DEFAULT;
        fator_escala = 1.0;

        x = 0;
        y = 0;

        velocidadeDeslocamento = 0.02;
        img = NULL;

    }

    virtual bool mover() {
        return 1;
    };

    virtual void mostrar() {
        //al_draw_bitmap(img, x, y, 0);

        // perímetro de colisão visível
        al_draw_circle(getCentroX(), getCentroY(), spriteRadius(), cor, 1);

        //al_draw_scaled_bitmap(img, 0, 0, al_get_bitmap_width(img), al_get_bitmap_height(img), x, y, spriteWidth(), spriteHeight(), 0);

        //ponto 0 da imagem;
        al_put_pixel(x, y, cor);

        // imprime as coordenadas do objeto na tela
        char s[20];
        snprintf(s, 19, "(%.2f, %.2f)", x, y);
        al_draw_text(fonte, cor, x, y + spriteHeight(), 0, s);
    }

    virtual _TIPO_TELA getCentroX() {
        return x + (al_get_bitmap_width(img) * fator_escala / 2);
    }

    virtual _TIPO_TELA getCentroY() {
        return y + (al_get_bitmap_height(img) * fator_escala / 2);
    }

    virtual _TIPO_TELA spriteHeight() {
        //if (img == nullptr) std::cerr << "imagem está nula" << std::endl;
        return (img != nullptr) ? al_get_bitmap_height(img) * fator_escala : 0;
    }

    virtual _TIPO_TELA spriteWidth() {
        //if (img == nullptr) std::cerr << "imagem está nula" << std::endl;

        return (img != nullptr) ? al_get_bitmap_width(img) * fator_escala : 0;
    }

    virtual _TIPO_TELA spriteRadius() {

        //  não usar pq o circulo de colisão fica muito grande o ideal é usar a maior das dimensões MAX(LarguraImagem, AlturaImagem) como diametro.        
        //
        //double diametro = sqrt(spriteHeight()*spriteHeight() + spriteWidth()*spriteWidth());
        //double raio = diametro/2;        

        // maior das dimensões
        double diametro = std::max(spriteWidth(), spriteHeight());
        double raio = diametro / 2;

        return (img != nullptr) ? raio : 0; // spriteWidth():0;  //
    }

};

#endif // PERSONAGEM_H