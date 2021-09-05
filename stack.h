#ifndef STACK_H
#define STACK_H

#include "config.h"
#include <stdint.h>
struct chip8;
struct chip8_stack {
	uint16_t stack[16];
};

void stack_pusher(struct chip8* chip8, uint16_t val);
unsigned short stack_poper(struct chip8* chip8);

#endif // !STACK_H
