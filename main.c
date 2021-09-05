#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "chip8.h"

const char keyboard_maping[16] = {
	/*
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
	0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F
	*/
	SDLK_0,SDLK_1,SDLK_2,SDLK_3,SDLK_4,SDLK_5,SDLK_6,SDLK_7,
	SDLK_8,SDLK_9,SDLK_a,SDLK_b,SDLK_c,SDLK_d,SDLK_e,SDLK_f
};

int main() {
	struct chip8 chip8;
	chip8_reset(&chip8);
	screen_set(&chip8.screen, 0, 0);
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(
		"Chip-8",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_W * 10, WINDOW_H * 10,
		SDL_WINDOW_SHOWN
	);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);


	while (1) {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
			{
				SDL_DestroyWindow(window);
				return 0;

			}
			break;
			case SDL_KEYUP:
			{
				char key = event.key.keysym.sym;
				int vkey = keyboard_map(keyboard_maping, key);

				if (vkey != -1) {
					keyboard_up(&chip8.keyboard, vkey);
				}

			}
			break;
			case SDL_KEYDOWN:
			{
				char key = event.key.keysym.sym;
				int vkey = keyboard_map(keyboard_maping, key);

				if (vkey != -1) {
					keyboard_down(&chip8.keyboard, vkey);
				}

			}
			break;
			}

			if (event.type == SDL_QUIT) {
				SDL_DestroyWindow(window);
				return 0;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 240, 2, 0);
		for (int x = 0; x < WINDOW_H; x++) {
			for (int y = 0; y < WINDOW_W; y++) {
				if (screen_is_set(&chip8.screen, x, y)) {
					SDL_Rect r;
					r.x = x*10;
					r.y = y*10;
					r.h = WINDOW_H;
					r.w = WINDOW_W;
					SDL_RenderFillRect(renderer, &r);
				}

				

			}
		}
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	return 0;
}