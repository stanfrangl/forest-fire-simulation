#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Window {
public:
    Window() {
        SDLWindow = SDL_CreateWindow(
            "Hello Window",
            640, 640, 
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_MINIMIZED);
        
        // get the details of the window's pixel format
        const SDL_PixelFormatDetails* FmtDetails{
            SDL_GetPixelFormatDetails(GetSurface()->format)
        };
        
        // create the background colour of the window suitable for the surface
        SDL_FillSurfaceRect(GetSurface(), nullptr, 
                            SDL_MapRGB(FmtDetails, nullptr, 120, 120, 100));
        
        SDL_UpdateWindowSurface(SDLWindow);
    }

    SDL_Surface* GetSurface() const {
        return SDL_GetWindowSurface(SDLWindow);
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
