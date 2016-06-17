/*
 * constantes utilizadas em todo o sistema, este arquivo provê um ponto único para alterar diversos aspectos do programa
 */

/* 
 * File:   constantes.h
 * Author:
 *
 * Created on June 9, 2016, 7:08 PM
 */

#ifndef CONSTANTES_H
#define CONSTANTES_H

#define QUANTIDADE_TROFEUS 500

//todo: cleanup
//#define TELA_WIDTH al_get_display_width(display)
//#define TELA_HEIGHT al_get_display_height(display)

#define REFRESH_RATE 59

//   w = al_get_display_width(display);
//   h = al_get_display_height(display);

// NÃO USAR DENTO DA FUNÇÃO DRAW, POIS A CARGA DE ARQUIVOS É UM PROCESSO MUITO LENTO!!!!!
//#define BTN_LOGOUT  al_load_bitmap(".//res//logout.png")
//#define IMG_TROFEU  al_load_bitmap(".//res//trofeu.png")
//#define IMG_BOLA    al_load_bitmap(".//res//bola.png")
//
//#define IMG_PALM    al_load_bitmap(".//res//pal.png")
//#define IMG_PALM_U  al_load_bitmap(".//res//palC.png")
//#define IMG_PALM_D  al_load_bitmap(".//res//palB.png")
//#define IMG_PALM_R  al_load_bitmap(".//res//palD.png")
//#define IMG_PALM_L  al_load_bitmap(".//res//palE.png")
//
//#define IMG_INIMIGO_1 al_load_bitmap(".//res//coxa.png");
//#define IMG_INIMIGO_2 al_load_bitmap(".//res//mira.png");
//#define IMG_INIMIGO_3 al_load_bitmap(".//res//chape.png");
//#define IMG_INIMIGO_4 al_load_bitmap(".//res//goias.png");

//#define FONTE_DEFAULT fonte//al_load_font(".//res//tahoma.TTF", 10, 0)

// tipo do retorno das funções de desenho e da classe personagem, vi que voce ficava alterando isso de vez em quando
#define _TIPO_TELA double


// cores disponíveis para identificação dos elementos na tela;
#define  ALCOLOR_BLACK al_map_rgb(0,0,0)
#define  ALCOLOR_WHITE al_map_rgb(255,255,255)
#define  ALCOLOR_RED al_map_rgb(255,0,0)
#define  ALCOLOR_GREEN al_map_rgb(0,255,0)
#define  ALCOLOR_BLUE al_map_rgb(0,0,255)


// velocidade dos objetos 

#define VELOCIDADE_BOLA   0.0
#define VELOCIDADE_ATOR   15
#define VELOCIDADE_TROFEU 4

#endif /* CONSTANTES_H */

