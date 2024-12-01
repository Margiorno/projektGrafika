// podstawowe funkcje
#ifndef GK2024_FUNKCJE_H_INCLUDED
#define GK2024_FUNKCJE_H_INCLUDED

#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>

void Funkcja1();
void Funkcja2();
void Funkcja3();
void Funkcja4();
void Funkcja5();
void Funkcja6();
void Funkcja7();
void Funkcja8();
void Funkcja9();
void Funkcja10();

void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
SDL_Color getPixel(int x, int y);
void czyscEkran(Uint8 R, Uint8 G, Uint8 B);
void ladujBMP(char const* nazwa, int x, int y);

#endif // GK2024_FUNKCJE_H_INCLUDED
