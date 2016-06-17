/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMgr.cpp
 * Author: ur5f
 * 
 * Created on June 15, 2016, 10:24 AM
 */

#include "GameMgr.hpp"

GameMgr::GameMgr() {
}

GameMgr::~GameMgr() {
}

bool GameMgr::load() {
    // iniciar gerador de números randômicos
    std::srand(std::time(0));

    // loading......
    load_resources();


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
    
    screen_width = al_get_display_width(display); 
    screen_height = al_get_display_height(display);
    

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


    draw_timer = al_create_timer(1.0 / REFRESH_RATE);
    al_start_timer(draw_timer);
    al_register_event_source(fila_eventos, al_get_timer_event_source(draw_timer));

    logic_timer = al_create_timer(1.0 / 59);
    al_start_timer(logic_timer);
    al_register_event_source(fila_eventos, al_get_timer_event_source(logic_timer));

    al_init_primitives_addon(); // inicializando o trabalho com primitivas gr�ficas
    al_init_image_addon();

    // Inicia o add-on para uso de fontes
    al_init_font_addon();
    // Inicia o add-on para uso de fontes True Type
    al_init_ttf_addon();

    // Carregando o arquivo de fonte, o arquivo de fonte deve estar na pasta do projeto
    
    return true;

}

int GameMgr::load_resources() {
    img_parmeira[0] = al_load_bitmap(".//res//pal.png");
    img_parmeira[1] = al_load_bitmap(".//res//palC.png");
    img_parmeira[2] = al_load_bitmap(".//res//palB.png");
    img_parmeira[3] = al_load_bitmap(".//res//palD.png");
    img_parmeira[4] = al_load_bitmap(".//res//palE.png");

    img_trofeu[0] = al_load_bitmap(".//res//trofeu.png");
    img_bola[0] = al_load_bitmap(".//res//bola.png");

    img_botao_desligar = al_load_bitmap(".//res//logout.png");

    fonte = al_load_font(".//res//tahoma.TTF", 14, 0);
    
    return 0;
}

void GameMgr::update(){
    
}

void GameMgr::processInput() {
    ALLEGRO_EVENT evento;
    while (!al_is_event_queue_empty(fila_eventos)) {
        al_clear_to_color(al_map_rgb(0, 0, 0)); // Colorindo a janela de preto
        al_wait_for_event(fila_eventos, &evento);

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) { // uma tecla foi pressionada            
            switch (evento.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    player->trocaDirecao(0);
                    break;
                case ALLEGRO_KEY_DOWN:
                    player->trocaDirecao(2);
                    break;
                case ALLEGRO_KEY_LEFT:
                    player->trocaDirecao(3);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    player->trocaDirecao(1);
                    break;
                case ALLEGRO_KEY_ENTER:
                    if (evento.keyboard.modifiers | ALLEGRO_KEYMOD_ALT) {
                        auto mode = al_get_display_flags(display);
                        if (mode | ALLEGRO_WINDOWED) {
                            al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
                        } else {
                            al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, false);
                        }
                    }
                    break;
                case ALLEGRO_KEY_Q:
                case ALLEGRO_KEY_ESCAPE:
                    exit(0);

            }
        } else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) { // click no mouse
            if (evento.mouse.x > 0 && evento.mouse.x < 20 &&
                    evento.mouse.y > 0 && evento.mouse.y < 20) // cordenadas do botao
                exit(0);
        } else if (evento.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
            al_acknowledge_resize(display);
            screen_width = al_get_display_width(display); 
            screen_height = al_get_display_height(display);
            _redraw = true;
        } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // click no mouse
            exit(0);
        } else if (evento.type == ALLEGRO_EVENT_TIMER) {
            if (evento.timer.source == draw_timer)
                _redraw = true;
            else if (evento.timer.source == logic_timer)
                _tick = true;
        }

        redraw();
    }

    al_destroy_display(display); // Finaliza a janela
}

void GameMgr::redraw() {
}

int GameMgr::run(){
    load();    
    while(true){
        update();
        processInput();
        redraw();
    }        
    return 0;
}

int main(int argc, char **argv){
    
    auto gm = new GameMgr();
    gm->run();
    
    return 0;
}