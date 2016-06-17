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


using namespace std;

class Personagem {
protected:
    float fator_escala;
    int x, y;
    double velocidadeDeslocamento;
    ALLEGRO_BITMAP *img = nullptr;
    ALLEGRO_FONT *fonte = nullptr;
    ALLEGRO_COLOR cor;


public:
    Personagem(){        
        fator_escala = 1;
        x = 0;
        y = 0;
        velocidadeDeslocamento = 0.02;
    }

    Personagem(ALLEGRO_FONT* fnt, ALLEGRO_BITMAP* spr[], auto x, auto y) {        
        Personagem();
        cor = ALCOLOR_WHITE;
        fonte = fnt;        
        img = spr[0];
        this->x = x; 
        this->y = y;
    }

    virtual bool mover() {
        return 1;
    };

    virtual void mostrar() {
        if(img)
        al_draw_scaled_bitmap(img, 0, 0, al_get_bitmap_width(img), al_get_bitmap_height(img), x, y, spriteWidth(), spriteHeight(), 0);
        
        // perímetro de colisão visível
        al_draw_circle(getCentroX(), getCentroY(), spriteRadius(), cor, 1);
        
        //ponto 0 da imagem;
        al_put_pixel(x, y, cor);

        // imprime as coordenadas do objeto na tela
        char s[20];
        snprintf(s, 19, "(%.2f, %.2f)", x, y);
        al_draw_text(fonte, cor, x, y + spriteHeight(), 0, s);
    }

    virtual _TIPO_TELA getCentroX() {
        if (img)
            return x + (al_get_bitmap_width(img) * fator_escala / 2);
        else
            return 0;
    }

    virtual _TIPO_TELA getCentroY() {
        if (img)
            return y + (al_get_bitmap_height(img) * fator_escala / 2);
        else
            return 0;
    }

    virtual _TIPO_TELA spriteHeight() {
        return (img)? al_get_bitmap_height(img) * fator_escala : 0;
    }

    virtual _TIPO_TELA spriteWidth() {
        return (img)? al_get_bitmap_width(img) * fator_escala : 0;
    }

    virtual _TIPO_TELA spriteRadius() {

        //  não usar pq o circulo de colisão fica muito grande o ideal é usar a maior das dimensões MAX(LarguraImagem, AlturaImagem) como diametro.        
        //
        //double diametro = sqrt(spriteHeight()*spriteHeight() + spriteWidth()*spriteWidth());
        //double raio = diametro/2;        

        // maior das dimensões
        double diametro = std::max(spriteWidth(), spriteHeight());
        double raio = diametro / 2;

        return (img) ? raio : 0; // spriteWidth():0;  //
    }

};

#endif // PERSONAGEM_H