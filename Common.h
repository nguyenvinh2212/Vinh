
#ifndef Common_h
#define Common_h

#include<iostream>
#include<math.h>
#include<stdlib.h>

#include<ctype.h>
#include<cstring>
#include <string>
#include<vector>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>

SDL_Texture *loadTexture(const char *filename);
#include"def.h"
#include "Game_object.h"

struct App  // đại diện cho ứng dụng game
{
    SDL_Renderer* renderer;
    SDL_Window* window;
    int keyboard[MAX_KEYBOARD_KEYS];
    char inputText[MAX_LINE_LENGTH];
    void (*logic)();
    void (*draw)();
    bool running = true;
};
struct Star{
    int x, y;
    int speed;
};
extern App app;
#endif
