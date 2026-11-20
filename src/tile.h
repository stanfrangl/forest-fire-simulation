#pragma once
#include <SDL3/SDL.h>
#include <random>

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
        void Update(std::mt19937& rng) {
            if (status == Status::burning) {
                if ((type == Type::mature) && std::bernoulli_distribution{matureBurnout}(rng)) {
                    SetStatus(Status::alive);
                    SetType(Type::ash);
                }
                else if ((type == Type::growing) && std::bernoulli_distribution{growingBurnout}(rng)) {
                    SetStatus(Status::alive);
                    SetType(Type::ash);
                }
                return;
            }
            switch(type) {
                case Type::bare:
                     if (std::bernoulli_distribution{bareToGrowing}(rng)) SetType(Type::growing); 
                     break;
                case Type::growing:
                    if (std::bernoulli_distribution{growingToMature}(rng)) SetType(Type::mature); 
                    else if (std::bernoulli_distribution{growingToBurning}(rng)) SetStatus(Status::burning); 
                     break;
                case Type::mature:
                    if (std::bernoulli_distribution{matureToBurning}(rng)) SetStatus(Status::burning); 
                     break;
                case Type::ash:
                    if (std::bernoulli_distribution{ashToGrowing}(rng)) SetType(Type::growing);
                    else if (std::bernoulli_distribution{ashToBare}(rng)) SetType(Type::bare); 
                     break;
            }
        }
    private:
        Uint32 Map(Uint8 r, Uint8 g, Uint8 b) const {
            return SDL_MapRGB(fmt, nullptr, r, g, b);
        }
        void UpdateColour(void) {
            const bool burning = (status == Status::burning);
            switch (type) {
                case Type::bare:    colour = Map(125, 100, 75); break;
                case Type::growing: colour = burning ? Map(255, 230, 80) : Map(90, 200, 90); break;
                case Type::mature:  colour = burning ? Map(255, 160, 0) : Map(20, 110, 40); break;
                case Type::ash:     colour = Map(200, 200, 200); break;
            }
        }
        SDL_Rect Rect;
        const SDL_PixelFormatDetails* fmt;
        Uint32 colour{0};
        Type type{Type::bare};
        Status status{Status::alive};
        static constexpr double bareToGrowing    = 0.005;
        static constexpr double ashToGrowing     = 0.01;
        static constexpr double growingToMature  = 0.05;
        static constexpr double growingToBurning = 0.00005;
        static constexpr double growingBurnout   = 0.05;
        static constexpr double matureToBurning  = 0.00005;
        static constexpr double matureBurnout    = 0.01;
        static constexpr double ashToBare        = 0.05;
};