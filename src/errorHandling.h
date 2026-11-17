#pragma once
#include <SDL3/SDL.h>
#include <iostream>

#define ERROR_LOGGING

void checkSDLError(const std::string& action) {
#ifdef ERROR_LOGGING
    const char* error = SDL_GetError();
    if (*error != '\0') {
        std::cerr << action << " Error: " << error << "\n";
        SDL_ClearError();
    }
#endif
}