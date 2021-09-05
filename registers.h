#ifndef REGISTER_H
#define REGISTER_H

#include <stdint.h>

 struct chip8_registers {
	uint8_t registers[16];
	uint16_t index;
	uint16_t pc;
	uint8_t sp;
	uint8_t delayTimer;
	uint8_t soundTimer;

};

#endif // !REGISTER_H
