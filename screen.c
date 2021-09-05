#include "screen.h"

static void screen_checker(int x, int y) {
	if (x <= 0 && x > WINDOW_H && y <= 0 && y > WINDOW_H) {
		printf("error screen checker");
		exit(-1);
	}
}

void screen_set(struct chip8_screen* screen, int x, int y) {
	screen_checker(x, y);
	screen->pixels[y][x]= true;

}
bool screen_is_set(struct chip8_screen* screen, int x, int y)
{
	screen_checker(x, y);
	return screen->pixels[y][x];
}