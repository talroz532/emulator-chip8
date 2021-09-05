#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>

struct chip8_keyboard
{
	bool keyboard[16];
};

int keyboard_map(const char* map,char key);
void keyboard_down(struct chip8_keyboard* keyboard, int key);
void keyboard_up(struct chip8_keyboard* keyboard, int key);

bool keyboard_is_down(struct chip8_keyboard* keyboard, int key);
//void keyboard_is_up(struct chip8_keyboard* keyboard, int key);
#endif // !KEYBOARD_H
