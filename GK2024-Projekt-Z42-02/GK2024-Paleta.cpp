// funkcje do redukcji kolorów i tworzenia palet
#include "GK2024-Paleta.h"
#include "GK2024-Zmienne.h"
#include "GK2024-Funkcje.h"

void narzuconaV1()
{
    SDL_Color kolor;
    int R, G, B;
    int kolor8bit;
    int nowyR, nowyG, nowyB;

    for(int y=0;y<wysokosc/2;y++)
    {
        for(int x=0;x<szerokosc/2;x++)
        {
            kolor = getPixel(x,y);
            R = kolor.r;
            G = kolor.g;
            B = kolor.b;

            nowyR = R>>5;
            nowyG = G>>5;
            nowyB = B>>6;

            R = nowyR<<5;
            G = nowyG<<5;
            B = nowyB<<6;
            setPixel(x+szerokosc/2,y , R,G,B);
        }
    }
}

void narzuconaV2()
{

    SDL_Color kolor;
    int R, G, B;
    int kolor8bit;
    int nowyR, nowyG, nowyB;

    for(int y=0;y<wysokosc/2;y++)
    {
        for(int x=0; x<szerokosc/2;x++)
        {
            kolor = getPixel(x,y);
            R = kolor.r;
            G = kolor.g;
            B = kolor.b;

            nowyR = R>>5;
            nowyG = G>>5;
            nowyB = B>>6;
            R = nowyR*255.0/7.0;
            G = nowyG*255.0/7.0;
            B = nowyB*255.0/3.0;

            setPixel(x,y+wysokosc/2,R,G,B);
        }
    }
}

void narzuconaV3()
{
    SDL_Color kolor;
        int R, G, B;
        int kolor8bit;
        int nowyR, nowyG, nowyB;

    for(int y=0;y<wysokosc/2;y++)
    {
        for(int x=0;x<szerokosc/2;x++)
        {
            kolor = getPixel(x,y);
            R = kolor.r;
            G = kolor.g;
            B = kolor.b;

            nowyR = round(R*7.0/255.0);
            nowyG = round(G*7.0/255.0);
            nowyB = round(B*3.0/255.0);

            R = nowyR*255.0/7.0;
            G = nowyG*255.0/7.0;
            B = nowyB*255.0/3.0;

            setPixel(x+szerokosc/2,y+wysokosc/2,R,G,B);

        }
    }
}

Uint8 z24Kdo8K(SDL_Color kolor)
{
    Uint8 kolor8bit;
    int R, G, B;
    int nowyR, nowyG, nowyB;

    R = kolor.r;
    G = kolor.g;
    B = kolor.b;
    nowyR = round(R*7.0/255.0);
    nowyG = round(G*7.0/255.0);
    nowyB = round(B*3.0/255.0);

    kolor8bit = (nowyR<<5) | (nowyG<<2) | nowyB;

    return kolor8bit;
}

SDL_Color z8Kdo24K(Uint8 kolor8bit)
{
    SDL_Color kolor;
    int R, G, B;
    int nowyR, nowyG, nowyB;

    nowyR = (kolor8bit&(0b11100000))>>5;
    nowyG = (kolor8bit&(0b00011100))>>2;
    nowyB = (kolor8bit&(0b00000011));

    R = nowyR*255.0/7.0;
    G = nowyG*255.0/7.0;
    B = nowyB*255.0/3.0;

    kolor.r = R;
    kolor.g = G;
    kolor.b = B;

    return kolor;
}

void narysujPalete(int px, int py, SDL_Color pal8[])
{
    int x, y;
    for (int k=0; k<256; k++){
        y = k / 32;
        x = k % 32;

        for (int xx=0; xx<10; xx++){
            for (int yy=0; yy<10; yy++){
                setPixel(x*10+xx+px, y*10+yy+py, pal8[k].r, pal8[k].g, pal8[k].b);
            }
        }
    }
}

void paletaNarzucona()
{
    Uint8 kolor8bit, szary8bit;
    SDL_Color kolor, nowyKolor, nowySzary;

    for (int y=0; y<wysokosc/2; y++){
        for (int x=0; x<szerokosc/2; x++){
            kolor = getPixel(x,y);
            kolor8bit = z24Kdo8K(kolor);
            nowyKolor = z8Kdo24K(kolor8bit);
            setPixel(x + szerokosc/2, y, nowyKolor.r, nowyKolor.g, nowyKolor.b);
        }
    }
    for (int k=0; k<256; k++){
        paleta8k[k] = z8Kdo24K(k);
    }
    narysujPalete(0, 210, paleta8k);
}

Uint8 z24Kdo6K(SDL_Color kolor)
{
    Uint8 kolor6bit;
    int R, G, B;
    int nowyR, nowyG, nowyB;

    R = kolor.r;
    G = kolor.g;
    B = kolor.b;
    nowyR = round(R*3.0/255.0);
    nowyG = round(G*3.0/255.0);
    nowyB = round(B*3.0/255.0);

    kolor6bit = (nowyR<<4) | (nowyG<<2) | nowyB;

    return kolor6bit;
}

SDL_Color z6Kdo24K(Uint8 kolor6bit)
{
    SDL_Color kolor;
    int R, G, B;
    int nowyR, nowyG, nowyB;

    nowyR = (kolor6bit&(0b00110000))>>4;
    nowyG = (kolor6bit&(0b00001100))>>2;
    nowyB = (kolor6bit&(0b00000011));

    R = nowyR*255.0/3.0;
    G = nowyG*255.0/3.0;
    B = nowyB*255.0/3.0;

    kolor.r = R;
    kolor.g = G;
    kolor.b = B;

    return kolor;
}

void narysujPalete6BIT(int px, int py, SDL_Color pal6[])
{
    int x, y;
    for (int k=0; k<64; k++){
        y = k / 16;
        x = k % 16;

        for (int xx=0; xx<20; xx++){
            for (int yy=0; yy<20; yy++){
                setPixel(x*20+xx+px, y*20+yy+py, pal6[k].r, pal6[k].g, pal6[k].b);
            }
        }
    }
}

void paletaNarzucona6BIT()
{
    Uint8 kolor6bit, szary6bit;
    SDL_Color kolor, szary, nowyKolor, nowySzary;

    for (int y=0; y<wysokosc/2; y++){
        for (int x=0; x<szerokosc/2; x++){
            kolor = getPixel(x,y);

            kolor6bit = z24Kdo6K(kolor);
            nowyKolor = z6Kdo24K(kolor6bit);
            setPixel(x + szerokosc/2, y, nowyKolor.r, nowyKolor.g, nowyKolor.b);
        }
    }
    for (int k=0; k<64; k++){
        paleta6k[k] = z6Kdo24K(k);
    }
    narysujPalete6BIT(0, 200, paleta6k);
}

void szary()
{
    SDL_Color kolor;

    int szary;
    for(int y=0;y<wysokosc/2;y++)
    {
        for(int x=0;x<szerokosc/2;x++)
        {
            kolor=getPixel(x,y);

            szary=kolor.r*0.299+kolor.g*0.587+kolor.b*0.114;
            setPixel(x+szerokosc/2,y+wysokosc/2,szary,szary,szary);
        }
    }
}

Uint8 z24Kdo6Kszary(SDL_Color kolor)
{

    Uint8 szary6bit;
    int jasnosc;
    jasnosc=0.299*kolor.r+0.587*kolor.g+0.114*kolor.b;

    szary6bit=round(jasnosc*63.0/255.0);

    return szary6bit;
}

SDL_Color z6Kdo24Kszary(Uint8 szary6bit)
{
    SDL_Color szary;
    int jasnosc;

    jasnosc = round(szary6bit * 255.0/63.0);

    szary.r = jasnosc;
    szary.g = jasnosc;
    szary.b = jasnosc;

    return szary;
}


void paletaNarzuconaSzary6BIT()
{
    Uint8  szary6bit;
    SDL_Color szary, kolor, nowySzary;

    for (int y=wysokosc/2; y<wysokosc; y++){
        for (int x=szerokosc/2; x<szerokosc; x++){
            kolor = getPixel(x,y);
            szary6bit = z24Kdo6Kszary(kolor);
            nowySzary = z6Kdo24Kszary(szary6bit);
            setPixel(x, y, nowySzary.r, nowySzary.g, nowySzary.b);
        }
    }
    for (int k=0; k<64; k++){
        paleta6s[k] = z6Kdo24Kszary(k);
    }
    narysujPalete6BIT(0, 280, paleta6s);
}


