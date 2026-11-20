#pragma once
#include <SDL3/SDL.h>

class Tile {
    public:
        Tile(const SDL_Rect& Rect, const SDL_PixelFormatDetails* fmt)
        : Rect{Rect},
          colour{SDL_MapRGB(fmt, nullptr, 125, 100, 75)}
        {}

        void Render(SDL_Surface* Surface) const {
            SDL_FillSurfaceRect(
                Surface,
                &Rect,
                colour
            );
        };
    private:
        SDL_Rect Rect;
        Uint32 colour{0};
};