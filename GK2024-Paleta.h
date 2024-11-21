#ifndef GK2024_PALETA_H_INCLUDED
#define GK2024_PALETA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

// Redukcja kolorów i tworzenie palet
void narzuconaV1();
void narzuconaV2();
void narzuconaV3();

// Konwersje między paletami 24-bitowymi a 8-/7-bitowymi
Uint8 z24Kdo8K(SDL_Color kolor);
SDL_Color z8Kdo24K(Uint8 kolor8bit);
Uint8 z24Kdo7K(SDL_Color kolor);
SDL_Color z7Kdo24K(Uint8 kolor7bit);
Uint8 z24Kdo7S(SDL_Color kolor);
SDL_Color z7Sdo24S(Uint8 szary7bit);

// Funkcje związane z tworzeniem i rysowaniem palet
void paletaNarzucona();
void paletaNarzucona7BIT();
void paletaNarzuconaSzara();
void narysujPalete(int px, int py, SDL_Color pal8[]);
void narysujPalete7BIT(int px, int py, SDL_Color pal7[]);
void narysujPalete_szary(int px, int py, SDL_Color pal8[]);
void paletaWykryta();
#endif
