#ifndef TROFEU_H
#define TROFEU_H


#include "Personagem.h"
#include "constantes.h"

//#include <iostream>
#include <stdio.h>

#include <cstdlib>

class Trofeu : public Personagem {
private:
    ALLEGRO_FONT *fonte;

public:

    Trofeu() {
        img = nullptr; //IMG_TROFEU;
        fator_escala = 0.3;

        velocidadeDeslocamento = VELOCIDADE_TROFEU;


        // y deve variar entre (0) e (resolução Horizontal  - altura da figura)
        // para que a figura sempre apareça na tela inteira;

        y = std::rand() % (TELA_HEIGHT - (int) round(spriteHeight()));
        x = 0;

        fonte = FONTE_DEFAULT;
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

    virtual void mostrar() override {
        // caso se tenha uma customização pode ser colocada aqui
        // antes ou depois da execução do método da classe pai
        Personagem::mostrar();
    }

};

#endif // TROFEU_H

