#include <SDL2/SDL.h>
#include <memory>
#include <ctime>

// SDL Window and Surface for pixel manipulation
SDL_Window *window = NULL;
SDL_Surface *surface = NULL;

// Width and Height of cell size in pixels
unsigned int CELL_SIZE = 4;
unsigned CELL_MAP_WIDTH = 16;
unsigned CELL_MAP_HEIGHT = 16;

// Screen width and height
unsigned int SCREEN_WIDTH = CELL_MAP_WIDTH * CELL_SIZE;
unsigned int SCREEN_HEIGHT = CELL_MAP_HEIGHT * CELL_SIZE;

void DrawCell(unsigned int x, unsigned int y, unsigned int colour);

int main(int argc, int *argv[]) {
    //SDL Boilerplate
    SDL_INIT(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Basic Forest Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

}

void DrawCell(unsigned int x, unsigned int y, unsigned int colour) {
    Uint8 *pixel_ptr = (Uint8*)surface->pixels + (y * CELL_SIZE * SCREEN_WIDTH + x * CELL_SIZE)

    for (unsigned int i = 0; i < CELL_SIZE, i++) {
        for (unsigned int j = 0; j < CELL_SIZE, j++) {
            *(pixel_ptr + j * 4) = colour;
            *(pixel_ptr + j * 4 + 1) = colour;
            *(pixel_ptr + j * 4 + 2) = colour;
        }
    }

    pixel_ptr += SCREEN_WIDTH * 4;

}