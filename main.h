#ifndef MAIN_H
#define MAIN_H

#include "pch.h"

#undef main

SDL_Window*		window   = NULL;
SDL_Renderer*	renderer = NULL;

SDL_Texture*	solidTexture;
SDL_Rect			solidRect;

SDL_Event e;

enum {menu,game,quit};
int gamestate = menu;
//LTexture image1[4];

bool running = true;
					
#endif // MAIN_H
