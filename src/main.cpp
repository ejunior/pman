#ifndef ALLEGRO_STATICLINK
#define ALLEGRO_STATICLINK
#endif

/*
 * FAZER
 *  - Implementar as funçoes de aparecimento dos elementos em função do tempo e não usando um valor aleatório por ciclo
 *    aprender a usar os eventos do ALLEGRO
 *  - colocar todos os elementos em uma única lista (atores)
 */

#include <iostream>
#include <list>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//randomizador c++
#include <ctime> 
//#include <cstdlib>

#include <allegro5/allegro.h>

// não utilizadas
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_image.h>
//#include <allegro5/mouse.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>

#include "myAllegro.h"
#include "Personagem.h"
#include "trofeu.h"
#include "bola.h"
#include "parmerinha.h"
//#include "vilao.h"   //nao usada

//#include "myconio.h" //nao usada

using namespace std;

void draw(bool &d, std::list<Personagem*> atores);

void colisaoTrofeis(list<Personagem *> &atores, Parmerinha *ator, Trofeu **tro);
void deletaTrofeisNoFimdaTela(list<Personagem *> &atores, Trofeu **tro);
void criaNovosTrofeis(list<Personagem *> &atores, Trofeu **tro);

void criaNovasBolas(list<Personagem *> &atores, Bola **bol);

void colisaoBolas(list<Personagem *> &atores, Parmerinha *player, Bola **bol);

int main(int argc, char **argv) {

    bool tick;

    // lista de elementos gráficos em cena
    std::list<Personagem *> atores;

    //srand(time(NULL));
    std::srand(std::time(0));

    if (!inicializaTudo()) return -1;

    // carrega uma imagem
    imagem_botao = BTN_LOGOUT;

    // nao precisa use o exit(0);
    //bool sair = false;

    // int tecla = 0, mx = 0, my = 0; variáveis não usadas
    ALLEGRO_EVENT evento;

    bool redraw = true;

    Parmerinha *player = new Parmerinha();
    atores.push_back(player);

    Trofeu **tro = new Trofeu *[QUANTIDADE_TROFEUS];

    for (int i = 0; i < QUANTIDADE_TROFEUS; i++) //isso é necessário?
    {
        tro[i] = new Trofeu();
        atores.push_back(tro[i]);
    }

    Bola **bol = new Bola *[QUANTIDADE_TROFEUS];
    for (int i = 0; i < QUANTIDADE_TROFEUS; i++)
        bol[i] = NULL;

    /*Vilao **vi = new Vilao*[1];
    vi[1] = new Vilao();*/

    while (true) {

        while (tick) {
            tick = false;
            colisaoTrofeis(atores, player, tro);
            deletaTrofeisNoFimdaTela(atores, tro);
            criaNovosTrofeis(atores, tro);
            criaNovasBolas(atores, bol);
            colisaoBolas(atores, player, bol);
            player->mover();
        }

        while (!al_is_event_queue_empty(fila_eventos)) {
            al_clear_to_color(al_map_rgb(0, 0, 0)); // Colorindo a janela de preto
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN) // uma tecla foi pressionada
            {
                switch (evento.keyboard.keycode) {
                    case ALLEGRO_KEY_UP: player->trocaDirecao(0);
                        break;
                    case ALLEGRO_KEY_DOWN: player->trocaDirecao(2);
                        break;
                    case ALLEGRO_KEY_LEFT: player->trocaDirecao(3);
                        break;
                    case ALLEGRO_KEY_RIGHT: player->trocaDirecao(1);
                        break;
                    case ALLEGRO_KEY_Q:
                    case ALLEGRO_KEY_ESCAPE:
                        exit(0);
                }
            } else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) // click no mouse
            {
                if (evento.mouse.x > 0 && evento.mouse.x < 20 &&
                        evento.mouse.y > 0 && evento.mouse.y < 20) // cordenadas do botao
                    exit(0);
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
                al_acknowledge_resize(display);
                redraw = true;
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // click no mouse
                exit(0);
            } else if (evento.type == ALLEGRO_EVENT_TIMER)
                if (evento.timer.source == timer)
                    redraw = true;
                else if (evento.timer.source == timer2)
                    tick = true;


        }
        draw(redraw, atores);

    }

    al_destroy_display(display); // Finaliza a janela
    return 0;
}

void colisaoBolas(list<Personagem *> &atores, Parmerinha *player, Bola **bol) {
    for (int i = 0; i < QUANTIDADE_TROFEUS; i++) {
        if (bol[i] != NULL) if (player->colisao(bol[i])) {
                atores.remove(bol[i]);
                delete bol[i];
                bol[i] = NULL;
            }
    }
}

void criaNovasBolas(list<Personagem *> &atores, Bola **bol) {
    if (rand() % 100 == 1) {
        for (int i = 0; i < QUANTIDADE_TROFEUS; i++) {
            if (bol[i] == NULL) {
                bol[i] = new Bola();
                atores.push_back(bol[i]);
            }
        }
    }
}

void criaNovosTrofeis(list<Personagem *> &atores, Trofeu **tro) {
    if (rand() % 10 == 1) //criando trof�us novos
        for (int i = 0; i < QUANTIDADE_TROFEUS; i++)
            if (tro[i] == NULL) {
                tro[i] = new Trofeu();
                atores.push_back(tro[i]);
            }
}

void deletaTrofeisNoFimdaTela(list<Personagem *> &atores, Trofeu **tro) {
    for (int i = 0; i < QUANTIDADE_TROFEUS; i++) //deletando os trofeus no fim da tela
        if (tro[i] != NULL)
            if (!tro[i]->mover()) {
                cout << "ator" << tro[i] << " destruido" << endl;
                atores.remove(tro[i]);
                delete tro[i];
                tro[i] = NULL;
            }
}

void colisaoTrofeis(list<Personagem *> &atores, Parmerinha *ator, Trofeu **tro) {
    for (int i = 0; i < QUANTIDADE_TROFEUS; i++)
        if (tro[i] != NULL)
            tro[i]->mover();

    for (int i = 0; i < QUANTIDADE_TROFEUS; i++) //ver colisão com os objetos(trofeus)
        if (tro[i] != NULL)
            if (ator->colisao(tro[i])) {
                cout << "colisao" << endl;
                delete tro[i];
                atores.remove(tro[i]);
                tro[i] = NULL;
            }
}

/*
 * implemeta o método para facilitar a fase de dezenho da cena
 * FAZER: fazer a faze de desenho acontecer em funcão do tempo e não todo loop!!!
 * */
void draw(bool &redraw, std::list<Personagem*> atores) {
    if (redraw) {
        redraw = false;
        double t = al_get_time();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        for (auto p : atores) {
            p->mostrar();
        }

        al_draw_bitmap(imagem_botao, 0, 0, 0); // mostra o botao para fechamento

        if (fonte) {
            al_draw_filled_rounded_rectangle(4, 4, 100, 30, 8, 8, al_map_rgba(0, 0, 0, 20));
            al_draw_textf(fonte, al_map_rgb(255, 255, 255), 54, 8, ALLEGRO_ALIGN_CENTRE, "FPS: %d", fps);
        }

        fps_accum++;
        if (t - fps_time >= 1) {
            fps = fps_accum;
            fps_accum = 0;
            fps_time = t;

        }
        al_flip_display(); // Atualiza a tela
        redraw = false;
    }

}