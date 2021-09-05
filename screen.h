#ifndef SCREEN_H
#define SCREEN_H

#include <stdbool.h>
#include "config.h"

struct chip8_screen {
	bool pixels[WINDOW_H][WINDOW_W];
		
};

void screen_set(struct chip8_screen* screen,int x,int y);
bool screen_is_set(struct chip8_screen* screen,int x,int y);

#endif // !SCREEN_H
