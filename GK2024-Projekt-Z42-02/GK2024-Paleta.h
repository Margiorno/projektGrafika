// funkcje do redukcji kolorów i tworzenia palet
#ifndef GK2024_PALETA_H_INCLUDED
#define GK2024_PALETA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
using namespace std;

void narzuconaV1();
void narzuconaV2();
void narzuconaV3();
SDL_Color z8Kdo24K(Uint8 kolor8bit);
Uint8 z24Kdo8K(SDL_Color kolor);
void paletaNarzucona();
void narysujPalete(int px, int py, SDL_Color pal8[]);
Uint8 z24Kdo6K(SDL_Color kolor);
SDL_Color z6Kdo24K(Uint8 kolor6bit);
void paletaNarzucona6BIT();
void szary();
SDL_Color z6Kdo24Kszary(Uint8 szary6bit);
Uint8 z24Kdo6Kszary(SDL_Color kolor);

void paletaNarzuconaSzary6BIT();

#endif // GK2024_PALETA_H_INCLUDED
