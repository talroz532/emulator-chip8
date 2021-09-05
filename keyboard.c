#include "keyboard.h"

static void keyboard_checker(int key) {
	if (key<0 || key>=16) {
		exit(-1);
	}
}
int keyboard_map(const char* map, char key) {

	for (int i = 0; i < 16; i++) {
		if (map[i] == key) {
			return i;
		}
	}
	return -1;
}

void keyboard_down(struct chip8_keyboard* keyboard, int key) {
	keyboard_checker(key);
	keyboard->keyboard[key] = true;

}
void keyboard_up(struct chip8_keyboard* keyboard, int key) {
	keyboard_checker(key);
	keyboard->keyboard[key] = false;
}

bool keyboard_is_down(struct chip8_keyboard* keyboard, int key) {
	return keyboard->keyboard[key];
}
void keyboard_is_up(struct chip8_keyboard* keyboard, int key);