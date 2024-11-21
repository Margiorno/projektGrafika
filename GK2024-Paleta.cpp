#include "GK2024-Paleta.h"
#include "GK2024-Zmienne.h"
#include "GK2024-Funkcje.h"

#include <map>
#include <vector>
#include <algorithm>



void narzuconaV1() {
    SDL_Color kolor;
    int R, G, B;
    int kolor8bit;
    int nowyR, nowyG, nowyB;

    for(int y = 0; y < wysokosc/2; y++) {
        for(int x = 0; x < szerokosc/2; x++) {
            kolor = getPixel(x, y);
            R = kolor.r;
            G = kolor.g;
            B = kolor.b;

            nowyR = R>>5;
            nowyG = G>>5;
            nowyB = B>>6;

            R = nowyR<<5;
            G = nowyG<<5;
            B = nowyB<<6;

            setPixel(x + szerokosc/2, y, R, G, B);
        }
    }
}

void narzuconaV2() {
    SDL_Color kolor;
    int R, G, B;
    int kolor8bit;
    int nowyR, nowyG, nowyB;

    for(int y = 0; y < wysokosc/2; y++) {
        for(int x = 0; x < szerokosc/2; x++) {
            kolor = getPixel(x, y);
            R = kolor.r;
            G = kolor.g;
            B = kolor.b;

            nowyR = R>>5;
            nowyG = G>>5;
            nowyB = B>>6;

            R = nowyR*255.0/7.0;
            G = nowyG*255.0/7.0;
            B = nowyB*255.0/3.0;

            setPixel(x, y + wysokosc/2, R, G, B);
        }
    }
}

void narzuconaV3() {
    SDL_Color kolor;
    int R, G, B;
    int kolor8bit;
    int nowyR, nowyG, nowyB;

    for(int y = 0; y < wysokosc/2; y++) {
        for(int x = 0; x < szerokosc/2; x++) {
            kolor = getPixel(x, y);
            R = kolor.r;
            G = kolor.g;
            B = kolor.b;

            nowyR = round(R*7.0/255);
            nowyG = round(G*7.0/255);
            nowyB = round(B*3.0/255);

            R = nowyR*255.0/7.0;
            G = nowyG*255.0/7.0;
            B = nowyB*255.0/3.0;

            setPixel(x + szerokosc/2, y + wysokosc/2, R, G, B);
        }
    }
}


void narysujPalete(int px, int py, SDL_Color pal8[]) {
    int x, y;
    for(int k = 0; k < 128; k++) {
        y = k / 32;
        x = k % 32;

        for(int xx = 0; xx < 10; xx++) {
            for(int yy = 0; yy < 10; yy++) {
                setPixel(x*10+xx+px, y*10+yy+py, pal8[k].r, pal8[k].g, pal8[k].b);
            }
        }
    }
}






Uint8 z24Kdo8K(SDL_Color kolor) {
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

SDL_Color z8Kdo24K(Uint8 kolor8bit) {
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

void paletaNarzucona() {
    Uint8 kolor8bit, szary8bit;
    SDL_Color kolor, nowyKolor, nowySzary;

    for(int y = 0; y < wysokosc/2; y++) {
        for(int x = 0; x < szerokosc/2; x++) {
            kolor = getPixel(x, y);
            kolor8bit = z24Kdo8K(kolor);
            nowyKolor = z8Kdo24K(kolor8bit);
            setPixel(x + szerokosc/2, y, nowyKolor.r, nowyKolor.g, nowyKolor.b);
        }
    }
    for(int k = 0; k < 256; k++) {
        paleta8k[k] = z8Kdo24K(k);
    }
    narysujPalete(0, 210, paleta8k);

    SDL_UpdateWindowSurface(window);
}






Uint8 kwantyzuj(Uint8 wartosc, int max_wartosc) {

    return wartosc * max_wartosc / 255;
}

Uint8 z24Kdo7K(SDL_Color kolor) {
    Uint8 nowyR = kwantyzuj(kolor.r, 3); // 0-3 (2 bity)
    Uint8 nowyG = kwantyzuj(kolor.g, 7); // 0-7 (3 bity)
    Uint8 nowyB = kwantyzuj(kolor.b, 3); // 0-3 (2 bity)

    return (nowyR << 5) | (nowyG << 2) | nowyB; // Indeks 0-127
}

SDL_Color z7Kdo24K(Uint8 kolor7bit) {
    SDL_Color kolor;
    Uint8 nowyR = (kolor7bit & 0b11100000) >> 5; // 2 bity
    Uint8 nowyG = (kolor7bit & 0b00011100) >> 2; // 3 bity
    Uint8 nowyB = (kolor7bit & 0b00000011);      // 2 bity

    kolor.r = nowyR * 255 / 3;
    kolor.g = nowyG * 255 / 7;
    kolor.b = nowyB * 255 / 3;
    kolor.a = 255;

    return kolor;
}

void narysujPalete7BIT(int px, int py, SDL_Color pal7[]) {
    int x, y;
    for (int k = 0; k < 128; k++) {
        y = k / 16;
        x = k % 16;

        for (int xx = 0; xx < 20; xx++) {
            for (int yy = 0; yy < 20; yy++) {
                setPixel(x * 20 + xx + px, y * 20 + yy + py, pal7[k].r, pal7[k].g, pal7[k].b);
            }
        }
    }
}

void paletaNarzucona7BIT() {
    Uint8 kolor7bit;
    SDL_Color kolor, nowyKolor;

    for (int y = 0; y < wysokosc / 2; y++) {
        for (int x = 0; x < szerokosc / 2; x++) {
            kolor = getPixel(x, y);

            kolor7bit = z24Kdo7K(kolor);
            nowyKolor = z7Kdo24K(kolor7bit);

            setPixel(x + szerokosc / 2, y, nowyKolor.r, nowyKolor.g, nowyKolor.b);
        }
    }

    for (int k = 0; k < 128; k++) {
        paleta7k[k] = z7Kdo24K(k);
    }

    narysujPalete7BIT(0, 210, paleta7k);
}

Uint8 z24Kdo7S(SDL_Color kolor) {
    Uint8 szary8bit, szary7bit;
    szary8bit = round(0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b);
    szary7bit = round(szary8bit*128.0/255.0);

    return szary7bit;
}

SDL_Color z7Sdo24S(Uint8 szary7bit) {
    SDL_Color szary;
    int nowyS;

    nowyS = szary7bit*(255.0/128.0);

    szary.r = nowyS;
    szary.g = nowyS;
    szary.b = nowyS;

    return szary;
}

void paletaNarzuconaSzara() {
    Uint8 szary8bit;
    SDL_Color kolor, nowySzary;

    for(int y = 0; y < wysokosc/2; y++) {
        for(int x = 0; x < szerokosc/2; x++) {
            kolor = getPixel(x, y);
            szary8bit = z24Kdo7S(kolor);
            nowySzary = z7Sdo24S(szary8bit);
            setPixel(x + szerokosc / 2, y, nowySzary.r, nowySzary.g, nowySzary.b);
        }
    }
    for(int k = 0; k < 128; k++) {
        paleta8s[k] = z7Sdo24S(k);
    }
    narysujPalete_szary(0, 210, paleta8s);

    SDL_UpdateWindowSurface(window);
}

void narysujPalete_szary(int px, int py, SDL_Color pal8[]){
    int x, y;
    for(int k=0; k<128; k++) {
        y = k / 32;
        x = k % 32;

        for(int xx=0; xx<10; xx++){
            for(int yy=0; yy<10; yy++){
                setPixel(x*10+xx+px, y*10+yy+py, pal8[k].r, pal8[k].g, pal8[k].b);
            }
        }
    }
}

int dodajKolor(SDL_Color kolor){
    int aktualnyKolor = ileKolorow;
    paleta7[aktualnyKolor] = kolor;
    if(ileKolorow < 128){
        cout << aktualnyKolor << ": [";
        cout << (int)kolor.r << "," << (int)kolor.g << "," << (int)kolor.b << "]" << endl;
    }
    ileKolorow++;
    return aktualnyKolor;
}

 bool porownajKolory(SDL_Color kolor1, SDL_Color kolor2) {

    if (kolor1.r != kolor2.r)
        return false;
    if (kolor1.g != kolor2.g)
        return false;
    if (kolor1.b != kolor2.b)
        return false;

    return true;
}

int sprawdzKolor(SDL_Color kolor) {

    if(ileKolorow > 0) {
        for(int k=0; k<ileKolorow; k++) {
            if(porownajKolory(kolor, paleta7[k]))
                return k;
        }
    }
    return dodajKolor(kolor);
}

void czyscPalete(){
    for(int k = 0; k < 128; k++){
        paleta7[k] = {0, 0, 0};
    }
    ileKolorow = 0;
}

void paletaWykryta(){
    czyscPalete();
    int indexKoloru;
    SDL_Color kolor;
    for (int y = 0; y < wysokosc / 2; y++){
        for(int x = 0; x < szerokosc/2; x++){
            kolor = getPixel(x, y);
            indexKoloru = sprawdzKolor(kolor);
        }
    }
    cout << endl << "ile kolorow: "<<ileKolorow<<endl;
    if(ileKolorow <= 128){
        cout <<"Paleta spelnia ograniczenia 7-bit/piksel"<<endl;
        narysujPalete(0, 210, paleta7);
    }
    else
        cout <<"Paleta przekracza ograniczenia 7-bit/piksel"<<endl;
}
