#include "memory.h"


void static checker_memmory(int index) {
	if (index <= 0 || index > CHIP8_MEMORY_SIZE) {
		printf("out of range memory!");
		exit(-1);
	}


}

void memory_set(struct chip8_memory* memory, int index, unsigned char val) {
	checker_memmory(index);
	memory->memory[index] = val;
}


unsigned char memory_get(struct chip8_memory* memory, int index) {
	checker_memmory(index);
	return memory->memory[index];
}