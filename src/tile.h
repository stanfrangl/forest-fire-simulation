#pragma once
#include <SDL3/SDL.h>

enum class Type {bare, growing, mature, ash};
enum class Status {alive, burning};

class tile {
    public:
        tile(const SDL_Rect& Rect, const SDL_PixelFormatDetails* fmt)
        : Rect{Rect},
          fmt{fmt}
        {
            UpdateColour();
        }
        void SetType(Type NewType) {type = NewType; UpdateColour();}
        void SetStatus(Status NewStatus) {status = NewStatus; UpdateColour();}
        Type GetType() const {return type;}
        Status GetStatus() const {return status;}
        void Render(SDL_Surface* Surface) const {
            SDL_FillSurfaceRect(
                Surface,
                &Rect,
                colour
            );
        };
    private:
        Uint32 Map(Uint8 r, Uint8 g, Uint8 b) const {
            return SDL_MapRGB(fmt, nullptr, r, g, b);
        }
        void UpdateColour(void) {
            const bool burning = (status == Status::burning);
            switch (type) {
                case Type::bare:    colour = Map(235, 220, 180); break;
                case Type::growing: colour = burning ? Map(255, 230, 80) : Map(90, 200, 90); break;
                case Type::mature:  colour = burning ? Map(255, 160, 0) : Map(20, 110, 40); break;
                case Type::ash:     colour = Map(130, 130, 130); break;
            }
        }
        SDL_Rect Rect;
        const SDL_PixelFormatDetails* fmt;
        Uint32 colour{0};
        Type type{Type::bare};
        Status status{Status::alive};
};