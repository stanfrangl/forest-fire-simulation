#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "errorHandling.h"

class Window {
public:
    Window() {
        SDLWindow = SDL_CreateWindow(
            "Hello Window",
            640, 640, 
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_MINIMIZED);
        checkSDLError("Creating window");
    }
    
    void render() {
        // get the details of the window's pixel format
        const SDL_PixelFormatDetails* FmtDetails =
        SDL_GetPixelFormatDetails(GetSurface()->format);
        checkSDLError("Getting pixel format details");
        
        // create the background colour of the window suitable for the surface
        SDL_FillSurfaceRect(GetSurface(), nullptr, 
        SDL_MapRGB(FmtDetails, nullptr, 0, 0, 0));
        checkSDLError("Filling background colour");
    }
    
    void update() {
        SDL_UpdateWindowSurface(SDLWindow);
        checkSDLError("Updating window durface");
    }
    
    SDL_Surface* GetSurface() const {
        return SDL_GetWindowSurface(SDLWindow);
    }
    
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    
    ~Window() {
        if (SDLWindow && SDL_Init(SDL_INIT_VIDEO)) {
            SDL_DestroyWindow(SDLWindow);
            checkSDLError("Destroying window surface");
        }
        else {
            std::cerr << "Skipping SDL_DestroyWindow\n";
        }
    }

private:
    SDL_Window* SDLWindow = nullptr;
};
