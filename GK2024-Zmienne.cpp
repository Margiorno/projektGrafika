// zmienne globalne
#include "GK2024-Zmienne.h"

SDL_Window* window = NULL;
SDL_Surface* screen = NULL;

SDL_Color paleta8[szerokosc*wysokosc];
SDL_Color paleta7[szerokosc*wysokosc];
int ileKolorow = 0;

SDL_Color paleta8k[256];
SDL_Color paleta8s[256];
SDL_Color paleta7k[128];
SDL_Color paleta7s[128];

std::map<SDL_Color, int> kolorCzestotliwosc;

int tablicaBayera4[4][4]={{6,14,8,16},{10,2,12,4},{7,15,5,13},{11,3,9,1}};
float zaktualizowanaTablicaBayera4[4][4];

int tablicaBayera2[2][2] = { {2,4}, {3,1}};
float zaktualizowanaTablicaBayera2[2][2];
