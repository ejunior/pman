
// simula o textcolor 
//#include <stdafx.h>

#ifndef MYCONIO_H
#define MYCONIO_H

#include <conio.h>
#include <windows.h>
#include <stdio.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128

//simula o textcolor+textbackground
//void TextColor(int fontcolor,int backgroundcolor)
//{
//   HANDLE screen;
//      //int textcolor = LIGHTGREEN;
//      //int backgroundcolor = BLACK;
//   screen = GetStdHandle(STD_OUTPUT_HANDLE);
//  int color_attribute;
//  color_attribute = backgroundcolor;
//  color_attribute = _rotl(color_attribute,4) | fontcolor;
//  SetConsoleTextAttribute(screen,color_attribute);
//}      

// simula o clrscr()

void clrscr() {
    system("cls");
}

// simula o gotoxy

void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}


#endif // MYCONIO_H

