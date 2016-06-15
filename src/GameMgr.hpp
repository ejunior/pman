/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameMgr.hpp
 * Author: ur5f
 *
 * Created on June 15, 2016, 10:24 AM
 */

#ifndef GAMEMGR_HPP
#define GAMEMGR_HPP

class GameMgr {
protected:
    ALLEGRO_BITMAP *img_parmeira[5]{nullptr, nullptr, nullptr, nullptr, nullptr};
    ALLEGRO_BITMAP *img_trofeu[1]{nullptr};
    ALLEGRO_BITMAP *img_bola[1]{nullptr};
    ALLEGRO_BITMAP *img_botao_desligar{nullptr};
        
    ALLEGRO_EVENT_QUEUE *fila_eventos;
    
    bool redraw = true;
    bool tick = true;
    
public:
    GameMgr();   
    virtual ~GameMgr();
    int run();    
    
private:
    int load();
    void update();
    void redraw();
    
    load_images();
};

#endif /* GAMEMGR_HPP */

