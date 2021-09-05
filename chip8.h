#ifndef CHIP8_H
#define CHIP8_H

#include "config.h"
#include "memory.h"
#include "registers.h"
#include "stack.h"
#include "keyboard.h"
#include "screen.h"

struct chip8 {
	struct chip8_memory memory;
	struct chip8_stack stack;
	struct chip8_registers registers;
	struct chip8_keyboard keyboard;
	struct chip8_screen screen;
};

void chip8_reset(struct chip8* chip8);
bool sprite_drawer(struct chip8_screen* screen,int x,int y, const char* sprite,int num );

#endif // !CHIP8_H
