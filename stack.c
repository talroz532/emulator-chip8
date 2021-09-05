
#include "stack.h"
#include "chip8.h"

#include <stdint.h>
#include <stdio.h>
static void stack_checker(struct chip8* chip8) {
	if (chip8->registers.sp >= sizeof(chip8->stack.stack)) {
		printf("out of range sp!");
		exit(-1);
	}
}

void stack_pusher(struct chip8* chip8, uint16_t val) {
	
	chip8->registers.sp += 1;
	stack_checker(chip8);
	chip8->stack.stack[chip8->registers.sp] = val;
	
}
unsigned short stack_poper(struct chip8* chip8) {

	stack_checker(chip8);
	unsigned int result = chip8->stack.stack[chip8->registers.sp];
	chip8->registers.sp -= 1;
	return result;
}