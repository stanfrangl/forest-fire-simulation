#pragma once
#include <SDL3/SDL.h>

class Window {
public:
    Window() {
        SDLWindow = SDL_CreateWindow(
            "Hello Window",
            800, 800, 0
        );
        SDL_GetWindowSurface(SDLWindow);
        SDL_UpdateWindwoSurface(SDLWindow);
    }
private:
    SDL_Window* ADLWindow{nullptr}
};
