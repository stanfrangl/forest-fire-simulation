#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Window {
public:
    Window() {
        SDLWindow = SDL_CreateWindow(
            "Hello Window",
            800, 800, 
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_MINIMIZED);

        SDL_GetWindowSurface(SDLWindow);
        SDL_UpdateWindowSurface(SDLWindow);
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
 
    ~Window() {
        if (SDLWindow && SDL_Init(SDL_INIT_VIDEO)) {
            SDL_DestroyWindow(SDLWindow);
        }
        else {
            std::cerr << "Skipping SDL_DestroyWindow\n";
        }
    }

private:
    SDL_Window* SDLWindow{nullptr};
};
