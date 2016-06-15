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


int GameMgr::load(){
    // iniciar gerador de números randômicos
    std::srand(std::time(0));
    
    // loading......
    load_images();
    
    return 0;
}

int GameMgr::load_images(){
    img_parmeira[0] = al_load_bitmap(".//res//pal.png");
    img_parmeira[1] = al_load_bitmap(".//res//palC.png");
    img_parmeira[2] = al_load_bitmap(".//res//palB.png");
    img_parmeira[3] = al_load_bitmap(".//res//palD.png");
    img_parmeira[4] = al_load_bitmap(".//res//palE.png");
  
    img_trofeu[0] = al_load_bitmap(".//res//trofeu.png"); 
    img_bola[0] = al_load_bitmap(".//res//bola.png");
    
    img_botao_desligar = al_load_bitmap(".//res//logout.png");
}
void GameMgr::update(){

}
void GameMgr::redraw(){

}

