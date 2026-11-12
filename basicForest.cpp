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

int main(int argc, int *argv[]) {
    //SDL Boilerplate
    SDL_INIT(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Basic Forest Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

}