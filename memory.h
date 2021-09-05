#ifndef MEMORY_H
#define MEMORY_H

#include "config.h"

struct chip8_memory {
	char memory[CHIP8_MEMORY_SIZE];
};

void static checker_memmory(int index);
void memory_set(struct chip8_memory* memory, int index, unsigned char val);
unsigned char memory_get(struct chip8_memory* memory, int index);

#endif // !MEMORY_H
