#ifndef MYALLEGRO_H
#define MYALLEGRO_H

#include <vector>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "constantes.h"

// ponteiros globais
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_BITMAP *img_botao_desligar = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_TIMER *timer;
ALLEGRO_TIMER *timer2;

int fps, fps_accum;
double fps_time;

bool inicializaTudo() {

    // Inicializando a biblioteca
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    // Criando a nossa janela
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    al_set_new_display_flags(ALLEGRO_OPENGL);
    
    display = al_create_display(320, 200);
    if (!display) {
        fprintf(stderr, "falha ao criar a tela!\n");
        return -1;
    }
   
    // inicializando uso do teclado
    if (!al_install_keyboard()) {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    // inicializando uso do mouse
    if (!al_install_mouse()) {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        return false;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos) {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(display);
        return false;
    }

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(display));


    timer = al_create_timer(1.0 / REFRESH_RATE);
    al_start_timer(timer);
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    timer2 = al_create_timer(1.0 / 59);
    al_start_timer(timer2);
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer2));

    al_init_primitives_addon(); // inicializando o trabalho com primitivas gr�ficas
    al_init_image_addon();

    // Inicializa��o do add-on para uso de fontes
    al_init_font_addon();
    // Inicializa��o do add-on para uso de fontes True Type
    al_init_ttf_addon();

    // Carregando o arquivo de fonte, o arquivo de fonte deve estar na pasta do projeto
    fonte = al_load_font(".//res//tahoma.TTF", 14, 0);

    return true;
}

#endif // MYALLEGRO_H