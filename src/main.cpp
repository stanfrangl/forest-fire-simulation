#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <vector>
#include "Window.h"
#include "tile.h"

int main(int, char**) {
  // initialisation
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;
  const auto* fmt = SDL_GetPixelFormatDetails(GameWindow.GetSurface()->format);
  //building the grid
  constexpr int Columns = 16;
  constexpr int Rows = 16;
  constexpr int Cell = 40;
  std::vector<tile> Tiles;
  Tiles.reserve(Rows * Columns);
  for (int Row = 0; Row < Rows; ++Row) {
    for (int col = 0; col < Columns; ++col) {
      Tiles.emplace_back(
        SDL_Rect{col * Cell, Row * Cell, Cell, Cell},
        fmt
      );
    }
  }
  Tiles[0].SetType(Type::bare);
  Tiles[1].SetType(Type::growing);
  Tiles[2].SetType(Type::mature);
  Tiles[2].SetStatus(Status::burning);
  Tiles[3].SetType(Type::ash);
  // Application loop
  SDL_Event event;
  bool IsRunning = true;
  while (IsRunning) {
    // Process events
    while (SDL_PollEvent(&event)) {
      // examine event object and react
      if (event.type == SDL_EVENT_QUIT) IsRunning = false;
    }
    // Update objects
    // Render background
    GameWindow.render();
    // Render everything else
    for (const auto& MyTile : Tiles) {
      MyTile.Render(GameWindow.GetSurface());
    }
    // Swap buffer
    GameWindow.update();
  }

  // shutdown
  SDL_Quit();
  return 0;
}