// zmienne globalne
#ifndef GK2024_ZMIENNE_H_INCLUDED
#define GK2024_ZMIENNE_H_INCLUDED

#include <SDL2/SDL.h>
#include <map>

#define szerokosc 640
#define wysokosc 400

#define tytul "GK2024 - Projekt - Zespol 21"

extern SDL_Window* window;
extern SDL_Surface* screen;

extern SDL_Color paleta8[szerokosc*wysokosc];
extern SDL_Color paleta7[szerokosc*wysokosc];
extern int ileKolorow;

extern SDL_Color paleta8k[256];
extern SDL_Color paleta8s[256];
extern SDL_Color paleta7k[128];
extern SDL_Color paleta7s[128];
extern std::map<SDL_Color, int> kolorCzestotliwosc;

extern int tablicaBayera4[4][4];
extern float zaktualizowanaTablicaBayera4[4][4];

extern int tablicaBayera2[2][2];
extern float zaktualizowanaTablicaBayera2[2][2];


#endif // GK2024_ZMIENNE_H_INCLUDED
